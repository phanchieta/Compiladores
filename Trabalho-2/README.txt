README

Install bison and flex with:

$ sudo apt-get install bison
$ sudo apt-get install flex

(Note: you many need to install m4 also)

Compile with:

$ yacc -d lalg.y
$ flex trabalho2.l
$ gcc -o prog_name y.tab.c lex.yy.c hash.c

Run with:

$ ./prog_name
