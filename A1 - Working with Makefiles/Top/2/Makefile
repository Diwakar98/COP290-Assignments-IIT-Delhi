myPythonInC: myPythonInC.c
	@echo "Compiling: myPythonInC.c -> myPythonInC.o"
	@gcc -I/Library/Frameworks/Python.framework/Versions/3.7/include/python3.7m -c myPythonInC.c
	@echo "myPythonInC.c successfully compiled"
	@echo "Moving myPythonInC: /Top/2 -> /Top/obj"
	@mv myPythonInC.o ../obj/myPythonInC.o
clean:
	@echo "Removing myPythonInC"
	@rm ../obj/myPythonInC.o
