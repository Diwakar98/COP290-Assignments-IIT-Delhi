I have done this assignment on "macOS Mojave Version 10.14.6" and using python3.6

INTRODUCTION: Till now we have practically written very small programs containing very few no of program files, which is very easy to compile in the required sequence. But compiling them becomes really very challenging when it comes to compile real big projects. Makefile does this very efficiently. It is a small program which is written to compile the project and organise and maintain projects.

HIERARCHY: I have made a top-level Makefile which calls other Makefiles in the inner directories.
The top-level makes also maintains the sequence in which the programs are compiled.
 ----/Top
     |----/1
     |    |--mySqr.c            //This program computes the square of two numbers.
     |    |--Makefile
     |
     |----/2
     |    |--myPythonInC.c      //This programs show the current time of the Machine.
     |    |--Makefile
     |
     |----/3
     |    |--myCOP.c            //This program print COP290 is a very attractive manner.
     |    |--Makefile
     |
     |----/4
     |    |--mySqrt.c           //For finding square root using Network's Square Root Method.
     |    |--Makeifle
     |
     |----/exe
     |    |--Hello
     |
     |----|/obj
     |    |--myApp.o
     |    |--myCOP.o
     |    |--myPythonInC.o
     |    |--mySqr.o
     |    |--mySqrt.o
     |
     |--myApp.c              //This is the main file to call all the other functions.
     |--Makefile             //Top level make file
     |--README

I have 2 programs in C and 2 python embedded programs in C:
mySqr.c myPythonInC.c myCOP.c mySqrt.c

In all the Makefiles I have added "@" at the beginning of each recipe to mute the running codes, instead I have added @echo "STRING" describing the events at each steps.I have also used variable to make the make file short.

HOW TO RUN THE MAKEFILE:
Before running the project make "exe" and "obj" directory in "/Top" i.e. "/Top/exe" & "/Top/obj"
To run the make file, just go into the "./Top" directory in terminal and type "make" on terminal and hit enter.
This will compile all the C files and store the object files in directory: "/Top/obj/". An executable file will also be created in directory "/Top/exe" as "Hello".
To run the executable file, type "make RUN" in directory: "/Top/".
To delete the created object files and the executable files: run "make clean"

All the commands are:
make                #To build the project.
make RUN            #To run the project.
make clean          #To delete all the object files and the executable file.
make OBJ1           #To compile the file in folder "/TOP/1" i.e. mySqr.c
make OBJ2           #To compile the file in folder "/TOP/2" i.e. myPythonInC.c
make OBJ3           #To compile the file in folder "/TOP/3" i.e. myCOP.c
make OBJ4           #To compile the file in folder "/TOP/4" i.e. mySqrt.c
make APP            #To compile myApp.c
make EXECUTABLE     #To make executable file only if all the object files are already created.
make cleanobj       #To delete only the object files
