### Scripts and experiments related to compile-time-urdf-parser

Dependencies:

1. `$ sudo apt install cmake libassimp-dev liburdfdom-dev libeigen3-dev liboctomap-dev`
2. `$ sudo apt install bear libyaml-cpp-dev libboost-all-dev`
3. `$ sudo apt install llvm clang clang-tools libclang-dev g++`

Setup instructions:

1. Make a top-level directory that holds all your project-related repos, say `$ mkdir -p ctup_stuff && cd ctup_stuff`
2. `$ git clone git@github.com:RadhikaG/ctup-experiments.git`
3. Optionally: `$ git clone git@github.com:RadhikaG/vamp.git`. Within vamp: `$ git checkout pin-int`
4. `$ cd ctup-experiments`
5. `$ git submodule update --init --recursive`
6. BuildIt needs a fix to compile with stricter cflags: `$ git apply --directory='deps/compile-time-urdf-parser/deps/buildit' helper_scripts/cpp17-warning-fix.patch`
7. Set up micromamba env with dependencies: `$ micromamba env create -f environment.yaml`

Build instructions:

1. Activate env (do this before building/running anything in this repo): `$ micromamba activate rla_env`
2. `$ mkdir -p build && cd build`
3. `$ cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1`
4. `$ make -j4`

Run instructions:

More application instructions incoming, but here's some immediate ones.

RLA FK intrin evaluation for iiwa with pinocchio comparison:
```
$ cd build
$  ./apps/rla_fk_intrin/eval_fk_intrin ../models/iiwa/iiwa_rbd_accel.urdf --robot iiwa
```

RLA FK intrin evaluation for iiwa without pinocchio comparison (useful for perf counter measurements):
```
$ cd build
$  ./apps/rla_fk_intrin/eval_fk_intrin ../models/iiwa/iiwa_rbd_accel.urdf --robot iiwa --rla-only
```
