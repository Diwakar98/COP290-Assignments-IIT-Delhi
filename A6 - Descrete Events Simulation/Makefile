all: compile move

compile:
	@gcc-9 -c ./src/qSim.c
	@gcc-9 qSim.o -o qSim

move:
	@mv ./qSim.o ./obj/qSim.o
	@mv ./qSim ./exe/qSim

clean:
	@rm ./exe/qSim
	@rm ./obj/qSim.o

run:
	@./exe/qSim