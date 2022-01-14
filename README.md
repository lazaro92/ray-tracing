# RayTracing: A Computer Graphics project

## Introduction 
 
This is a Computer Graphics project for the summer of 2020 in order to improve my programming skills in C++ and also because I felt curious and wanted to do it.
 
For the project I'm visiting the next pages:

* [Scratchapixel](https://www.scratchapixel.com/) - Page with a lot of information about the maths behind the Ray Tracer.
* [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html) - Book that explains how to make a RayTracing in a shorter and fun way. It does not profundice in the maths.

## Compilation and execution (under Linux)

In order to compile the project, execute the next instruction: `g++ -Wall src/main.cpp -o output`. Note that if you use another compiler you will have to know how to compile and link a program under it.

Then execute the generated program by execute `./output > image.ppm`. Note that the output from the execution is saved in a *PPM* text file that indicate the color for every pixel. For more information about the format check the [Wikipedia example](https://en.wikipedia.org/wiki/Netpbm#PPM_example).

## Results of the execution

You can open the scene by uploading the file in an online PPM viewer like [PPM Viewer](https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html).
