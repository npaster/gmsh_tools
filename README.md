# gmsh_tools

This C++ librairy provides some tools to read and write meshes:
    - ".mesh" of Medit
    - ".msh"  of Gmsh
    
 In addition, it gives functionalities to export data for post-processing in gmsh.
 
 
# Installation
The library runs on Unix systems. It is written in C++11 and requires a recent compiler to be compiled (GCC >= 5.0 or Clang >= 3.8). Older compilers may work but they are neither supported nor tested.

To compile it:
 make
 
 
 You will end up with an executable named `gmsh_tools` and some meshes in `/meshes`.
 
 
# Exemple
There is an exemple in main.cc

    gmsh_tools ./meshes/<meshes>
    

