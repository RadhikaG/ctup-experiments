SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
export LD_LIBRARY_PATH=$SCRIPT_DIR/build/install/hpp-fcl/lib:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=$SCRIPT_DIR/build/install/CppAD/lib:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=$SCRIPT_DIR/build/install/pinocchio/lib:$LD_LIBRARY_PATH
