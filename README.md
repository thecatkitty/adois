A DOS-Only Installer
===================

The aim of this project is to create a setup program for DOS software.

You'll need OpenWatcom `BIN` (eg. `BINNT64` and `BINNT`) in your path. Also, wizard build doesn't work with the latest CMake release (3.17.2), so putting CMake dev build `bin` directory in PATH is needed too.

`INCLUDE` environment variable should point ti OpenWatcom `H` directory.

Building on Windows
------------------
Inside *VS Tools Command Prompt*.

```powershell
cmake -G "Watcom WMake" -S wizard -B build\wizard
cmake -G "NMake Makefiles" -S compiler -B build\compiler

cd build
cd wizard
wmake

cd ..
cd compiler
nmake
```
