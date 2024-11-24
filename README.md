### Scripts and experiments related to compile-time-urdf-parser

Dependencies:
1. `$ sudo apt install cmake libassimp-dev liburdfdom-dev libeigen3-dev liboctomap-dev`
2. `$ sudo apt install llvm clang clang-tools libclang-dev`

Setup instructions:
1. Make a top-level directory that holds all your project-related repos, say `$ mkdir -p ctup_stuff && cd ctup_stuff`.
2. `$ git clone git@github.com:RadhikaG/ctup-experiments.git`
3. `$ cd ctup-experiments`
4. `$ git submodule update --init --recursive`
5. `$ mkdir -p build && cd build`
6. `$ cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1`
7. Should not be needed: `$ export PKG_CONFIG_PATH=$(pwd)/install/CppAD/lib/pkgconfig:$(PKG_CONFIG_PATH)`
8. `$ make -j$(nproc)`
9. This initializes env vars related to the project, run this whenever you open a new terminal to work on the project: `$ source ../init_path_vars.sh`
10. See if basic example works: `$ ./pin_fk ../deps/pinocchio/models/baxter_simple.urdf`
