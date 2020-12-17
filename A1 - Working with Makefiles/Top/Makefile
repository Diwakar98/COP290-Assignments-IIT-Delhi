EnD = Entering Directory
ExD = Exiting Directory
1 = Top/1
2 = Top/2
3 = Top/3
4 = Top/4
mkclean = make clean
compiler = gcc
all: APP OBJ1 OBJ2 OBJ3 OBJ4 EXECUTABLE
	@echo "Type 'make RUN' to run the executable file."
	@echo ""

OBJ1:
	@echo ""
	@echo "${EnD}: ${1}"
	@${MAKE} -C 1
	@echo "${ExD}: ${1}"
	@echo ""

OBJ2:
	@echo ""
	@echo "${EnD}: ${2}"
	@${MAKE} -C 2
	@echo "${ExD}: ${2}"
	@echo ""

OBJ3:
	@echo ""
	@echo "${EnD} ${3}"
	@${MAKE} -C 3
	@echo "${ExD}: ${3}"
	@echo ""

OBJ4:
	@echo ""
	@echo "${EnD} ${4}"
	@${MAKE} -C 4
	@echo "${ExD}: ${4}"
	@echo ""

APP:
	@echo ""
	@echo "Compiling: myApp.c -> myApp.o"
	@${compiler} -c myApp.c
	@echo "myApp.c successfully compiled"
	@echo "Moving myApp.o: /Top -> /Top/obj"
	@mv myApp.o ./obj/myApp.o
	@echo ""

EXECUTABLE:
	@echo ""
	@echo "$(EnD): /Top/obj"
	@echo "Creating EXECUTABLE file"
	@cd ./obj && ${compiler} *.o -o Hello -L/Library/Frameworks/Python.framework/Versions/3.7/lib -lpython3.7m
	@echo "EXECUTABLE file successfully created"
	@echo "Moving EXECUTABLE: /Top/obj -> /Top/exe"
	@mv ./obj/Hello ./exe/Hello
	@echo "$(ExD): /Top/obj"
	@echo ""

RUN:
	@echo "\n"
	@echo "\t\t\t    <-------STARTING PROGRAM------->"
	@./exe/Hello
	@echo "\n"
	@echo "Other commands which can be used:"
	@echo "make                #To build the project."
	@echo "make RUN            #To run the project."
	@echo "make clean          #To delete all the object files and the executable file."
	@echo "make OBJ1           #To compile the file in folder "/TOP/1" i.e. mySqr.c"
	@echo "make OBJ2           #To compile the file in folder "/TOP/2" i.e. myPythonInC.c"
	@echo "make OBJ3           #To compile the file in folder "/TOP/3" i.e. myCOP.c"
	@echo "make OBJ4           #To compile the file in folder "/TOP/4" i.e. mySqrt.c"
	@echo "make APP            #To compile myApp.c"
	@echo "make EXECUTABLE     #To make executable file only if all the object files are already created."
	@echo "make cleanobj       #To delete only the object files"
	@echo "\n"

clean: cleanobj
	@cd ./exe && rm Hello

cleanobj:
	@echo ""
	@echo "Deleted all the object files and the executable file."
	@cd ./obj && rm *.o
	@echo ""
