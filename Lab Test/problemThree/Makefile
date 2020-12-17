ALL:
	@gcc -c ./src/mulMat.c
	@gcc -c ./src/main.c
	@gcc mulMat.o main.o -o mainfile
	@mv mulMat.o ./obj/mulMat.o
	@mv main.o ./obj/main.o
	@mv mainfile ./exe/mainfile

RUN:
	@./exe/mainfile
