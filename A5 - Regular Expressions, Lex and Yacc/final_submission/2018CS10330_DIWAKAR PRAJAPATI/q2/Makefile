ALL:
	@lex lex.l
	@yacc yac.y
	@gcc y.tab.c -o conversion
RUN:
	@./conversion input.txt output.txt
