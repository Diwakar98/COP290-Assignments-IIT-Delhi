all:
	@gcc -c run.c
	@gcc run.o -o RUN
	@gcc -c 2018CS10330_sh.c
	@gcc 2018CS10330_sh.c -o SHELL
	mv ./run.o ./obj/run.o
	mv ./2018CS10330_sh.o ./obj/2018CS10330_sh.o
	
	@./RUN
