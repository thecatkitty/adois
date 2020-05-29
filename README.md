A DOS-Only Installer
===================

The aim of this project is to create a setup program for DOS software.

Currently it builds under Windows only, but I'm working on it! I'm trying to find a way for having both C++1x (OpenWatcom doesn't support it) and `far` pointers (ia16-elf-g++ doesn't support them).

Prerequisites for building
-------------------------
* OpenWatcom v2 – `BINNT64` directory in `%PATH%` before VS tools; `%WATCOM%` set
* VS tools (`cl`, `nmake`...) in `%PATH%` – simplest way is to run *VS Tools Command Prompt* 
* CMake nightly in `%PATH%` – latest CMake release (3.17.2) doesn't support OW yet

In order to build everything, run `build.ps1`.
