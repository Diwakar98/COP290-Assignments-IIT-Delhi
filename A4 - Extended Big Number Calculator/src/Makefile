ALL: COMPILE LIBRARY EXECUTABLE MOVE
COMPILE:
	@gcc -c compare.c
	@gcc -c arithmetic.c
	@gcc -c addnew.c
	@gcc -c subnew.c
	@gcc -c mulnew.c
	@gcc -c abs.c
	@gcc -c pownew.c
	@gcc -c divnew.c
	@gcc -c sqrtnew.c
	@gcc -c trim.c
	@gcc -c main.c

LIBRARY:
	@ar cr libarbprecision.a compare.o trim.o addnew.o subnew.o mulnew.o pownew.o sqrtnew.o abs.o divnew.o

EXECUTABLE:
	@gcc compare.o trim.o addnew.o subnew.o mulnew.o pownew.o sqrtnew.o abs.o divnew.o arithmetic.o -o ARITHMETIC
	@gcc main.o -o mainfile -L. -larbprecision

MOVE:
	@mv compare.o ../obj/compare.o
	@mv arithmetic.o ../obj/arithmetic.o
	@mv addnew.o ../obj/addnew.o
	@mv subnew.o ../obj/subnew.o
	@mv mulnew.o ../obj/mulnew.o
	@mv abs.o ../obj/abs.o
	@mv pownew.o ../obj/pownew.o
	@mv divnew.o ../obj/divnew.o
	@mv sqrtnew.o ../obj/sqrtnew.o
	@mv trim.o ../obj/trim.o
	@mv ./main.o ../obj/main.o
	@mv ARITHMETIC ../exe/ARITHMETIC
	@mv ./mainfile ../exe/mainfile

RUN:
	@../exe/mainfile
