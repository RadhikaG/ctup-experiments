#!/bin/python3
import re
import numpy as np
import sys

def parse_matrix_block(lines, start_index):
    matrix = []
    for i in range(6):
        row = re.findall(r"[-+]?[0-9]*\.?[0-9]+(?:[eE][-+]?[0-9]+)?", lines[start_index + i])
        matrix.append([float(x) for x in row])
    return np.array(matrix)

def count_ops_only_TT(A, B, tol=1e-8):
    A = np.where(np.abs(A) < tol, 0, A)
    B = np.where(np.abs(B) < tol, 0, B)
    mults = 0
    adds = 0
    for i in range(6):
        for j in range(6):
            terms = [A[i, k] * B[k, j] for k in range(6) if A[i, k] != 0 and B[k, j] != 0]
            num_terms = len(terms)
            if num_terms > 0:
                mults += num_terms
                adds += num_terms - 1
    return mults, adds

def count_ops_CT(A, B, tol=1e-8, is_TT=False):
    A = np.where(np.abs(A) < tol, 0, A)
    B = np.where(np.abs(B) < tol, 0, B)

    TL_A = A[:3, :3]
    TR_A = A[:3, 3:]
    BL_A = A[3:, :3]
    BR_A = A[3:, 3:]

    TL_B = B[:3, :3]
    TR_B = B[:3, 3:]
    BL_B = B[3:, :3]
    BR_B = B[3:, 3:]

    mults = 0
    adds = 0

    if not is_TT:
        mults += 81
        adds += 54
        return mults, adds

    # if is_TT, we consider internal sparsity as well, so we count 
    # individual entries for zero/nonzero status

    A = np.where(np.abs(A) < tol, 0, A)
    B = np.where(np.abs(B) < tol, 0, B)

    TL_A = A[:3, :3]
    TR_A = A[:3, 3:]
    BL_A = A[3:, :3]
    BR_A = A[3:, 3:]

    TL_B = B[:3, :3]
    TR_B = B[:3, 3:]
    BL_B = B[3:, :3]
    BR_B = B[3:, 3:]

    mults = 0
    adds = 0

    # Compute top-left block: TL_A * TL_B
    for i in range(3):
        for j in range(3):
            terms = [TL_A[i, k] * TL_B[k, j] for k in range(3) if TL_A[i, k] != 0 and TL_B[k, j] != 0]
            num_terms = len(terms)
            if num_terms > 0:
                mults += num_terms
                adds += num_terms - 1

    # Compute top-right block: TL_A * TR_B + TR_A * BR_B
    for i in range(3):
        for j in range(3):
            terms_tl = [TL_A[i, k] * TR_B[k, j] for k in range(3) if TL_A[i, k] != 0 and TR_B[k, j] != 0]
            terms_tr = [TR_A[i, k] * BR_B[k, j] for k in range(3) if TR_A[i, k] != 0 and BR_B[k, j] != 0]
            num_terms = len(terms_tl) + len(terms_tr)
            if num_terms > 0:
                mults += num_terms
                adds += num_terms - 1

    # Skip bottom-left block: BL_A * TL_B + BR_A * BL_B

    # Skip bottom-right block: BR_A * BR_B since it is equal to TL_A * TL_B

    return mults, adds

def parse_file(filepath):
    with open(filepath, 'r') as f:
        lines = f.readlines()

    i = 0
    iterations = []
    while i < len(lines):
        if lines[i].startswith("------ i ="):
            iteration = {}
            i += 1
            while i < len(lines) and not lines[i].startswith("---") and not lines[i].startswith("------ i ="):
                line = lines[i].strip()
                if line.startswith("X_T:"):
                    iteration["X_T"] = parse_matrix_block(lines, i + 1)
                    i += 7
                elif line.startswith("X_J:"):
                    iteration["X_J"] = parse_matrix_block(lines, i + 1)
                    i += 7
                elif line.startswith("X_pi:"):
                    iteration["X_pi"] = parse_matrix_block(lines, i + 1)
                    i += 7
                elif line.startswith("X_0:"):
                    iteration["X_0"] = parse_matrix_block(lines, i + 1)
                    i += 7
                elif line.startswith("X_0 par:"):
                    iteration["X_0_par"] = parse_matrix_block(lines, i + 1)
                    i += 7
                else:
                    i += 1
            iterations.append(iteration)
        else:
            i += 1

    return iterations

def analyze_file(filepath):
    iterations = parse_file(filepath)

    n_matmuls = 0
    n_CT_mults = 0
    n_CT_adds = 0
    n_TT_mults = 0
    n_TT_adds = 0
    n_CT_TT_mults = 0
    n_CT_TT_adds = 0
    n_no_CT_TT_mults = 0
    n_no_CT_TT_adds = 0

    for data in iterations:
        n_matmuls += 1
        ct_m1, ct_a1 = count_ops_CT(data["X_T"], data["X_J"])
        tt_m1, tt_a1 = count_ops_only_TT(data["X_T"], data["X_J"])
        ct_tt_m1, ct_tt_a1 = count_ops_CT(data["X_T"], data["X_J"], is_TT=True)

        n_CT_mults += ct_m1
        n_CT_adds += ct_a1
        n_TT_mults += tt_m1
        n_TT_adds += tt_a1
        n_CT_TT_mults += ct_tt_m1
        n_CT_TT_adds += ct_tt_a1
        n_no_CT_TT_mults += ct_tt_m1
        n_no_CT_TT_adds += ct_tt_a1

        if "X_0_par" in data:
            n_matmuls += 1
            ct_m2, ct_a2 = count_ops_CT(data["X_0_par"], data["X_pi"])
            tt_m2, tt_a2 = count_ops_only_TT(data["X_0_par"], data["X_pi"])
            ct_tt_m2, ct_tt_a2 = count_ops_CT(data["X_0_par"], data["X_pi"], is_TT=True)

            n_CT_mults += ct_m2
            n_CT_adds += ct_a2
            n_TT_mults += tt_m2
            n_TT_adds += tt_a2
            n_CT_TT_mults += ct_tt_m2
            n_CT_TT_adds += ct_tt_a2
            n_no_CT_TT_mults += 216
            n_no_CT_TT_adds += 180

    return {
        "n_dense_mults": 216 * n_matmuls,
        "n_dense_adds": 180 * n_matmuls,
        "n_CT_mults": n_CT_mults,
        "n_CT_adds": n_CT_adds,
        "n_TT_mults": n_TT_mults,
        "n_TT_adds": n_TT_adds,
        "n_CT_TT_mults": n_CT_TT_mults,
        "n_CT_TT_adds": n_CT_TT_adds,
        "n_no_CT_TT_mults": n_no_CT_TT_mults,
        "n_no_CT_TT_adds": n_no_CT_TT_adds,
    }

def main():
    if len(sys.argv) != 2:
        print("Usage: python analyze_matmuls.py <input_file>")
        sys.exit(1)

    filepath = sys.argv[1]
    results = analyze_file(filepath)
    print(results)

if __name__ == "__main__":
    main()
