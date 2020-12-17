all:
	@gcc -c ./src/myFactorial.c
	@gcc -c ./src/nCr.c
	@gcc -c ./src/mySin.c
	@gcc -c ./src/myCos.c
	@gcc -c ./src/main.c

	@ar cr libmyMath.a myFactorial.o nCr.o mySin.o myCos.o
	@gcc main.o -o mainfile -L. -lmyMath

	@mv myFactorial.o ./obj/myFactorial.o
	@mv nCr.o ./obj/nCr.o
	@mv mySin.o ./obj/mySin.o
	@mv myCos.o ./obj/myCos.o
	@mv main.o ./obj/main.o
	@mv libmyMath.a ./include/libmyMath.a
