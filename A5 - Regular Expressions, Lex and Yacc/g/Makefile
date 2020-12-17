ALL:
	@lex myscanner.l
	@gcc lex.yy.c -o decomment -ll

RUN:
	@./decomment < input.txt
