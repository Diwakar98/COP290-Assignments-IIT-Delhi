ALL:
	@lex main.l
	@yacc yacc.y
	@yacc -d yacc.y
	@gcc y.tab.c -o mainfile
RUN:
	@./mainfile
