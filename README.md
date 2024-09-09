# test_marker
(TODO) List test cases which execute marked code.

## Quick Install

```shell
cmake --preset release_gcc
cmake --build --preset release_gcc
```

for all users
```shell
sudo cmake --install out/build/release/gcc
```
**or** install for `$USER` only
```shell
cmake --install out/build/release/gcc --prefix ~/.local
export CMAKE_PREFIX_PATH=$HOME/.local:$CMAKE_PREFIX_PATH
```
