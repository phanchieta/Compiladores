README
(Outdated y.tab.c and y.tab.h in repo. Recompile lalg.y before running)

Install bison and flex with:

$ sudo apt-get install bison
$ sudo apt-get install flex

(Note: you many need to install m4 also)

Compile with:

$ yacc -d lalg.y
$ flex --header-file=lex.yy.h trabalho2.l
$ gcc -o prog_name y.tab.c lex.yy.c hash.c

Run with:

$ ./prog_name
