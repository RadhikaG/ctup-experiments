### Scripts and experiments related to compile-time-urdf-parser

Dependencies:
1. `$ sudo apt install cmake libassimp-dev liburdfdom-dev libeigen3-dev liboctomap-dev bear`
2. `$ sudo apt install llvm clang clang-tools libclang-dev`

Setup instructions:

Part 1: building dependencies from source
1. Make a top-level directory that holds all your project-related repos, say `$ mkdir -p ctup_stuff && cd ctup_stuff`
2. `$ git clone git@github.com:RadhikaG/ctup-experiments.git`
3. `$ cd ctup-experiments`
4. `$ git submodule update --init --recursive`
5. BuildIt needs a fix to compile with stricter cflags: `$ git apply --directory='deps/compile-time-urdf-parser/deps/buildit' helper_scripts/cpp17-warning-fix.patch`
6. `$ mkdir -p build && cd build`
7. `$ cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1`
8. Build will die once while building CppADCodeGen, then run: `$ export PKG_CONFIG_PATH=$(pwd)/install/CppAD/lib/pkgconfig:$(PKG_CONFIG_PATH)`
9. Run again: `$ cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1`

Part 2: building code generators in samples/ and experiments in scripts/
1. `$ make -j4`
2. See if basic unrolled example works: `$ ./eval_fk ../models/baxter_simple.urdf`
3. If it errors out saying "xyz.so not found" see next step.
4. This initializes env vars related to the project, run this whenever you open a new terminal to work on the project: `$ source ../init_path_vars.sh`
