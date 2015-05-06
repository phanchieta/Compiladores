/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ATRIBUICAO = 258,
     IGUAL = 259,
     MAIOR_IGUAL = 260,
     MENOR_IGUAL = 261,
     MENOR_MAIOR = 262,
     MAIOR = 263,
     MENOR = 264,
     MAIS = 265,
     MENOS = 266,
     VEZES = 267,
     DIVIDIDO = 268,
     VIRGULA = 269,
     PONTO_E_VIRGULA = 270,
     PONTO = 271,
     DOIS_PONTOS = 272,
     PARENTESES_ESQUERDO = 273,
     PARENTESES_DIREITO = 274,
     NUM_INTEIRO = 275,
     NUM_REAL = 276,
     COMENTARIO = 277,
     NUMERO_INT_MAL_FORMADO = 278,
     NUMERO_REAL_MAL_FORMADO = 279,
     CARACTERES_INVALIDOS = 280,
     PROGRAM = 281,
     START = 282,
     END = 283,
     CONST = 284,
     VAR = 285,
     REAL = 286,
     INTEGER = 287,
     PROCEDURE = 288,
     ELSE = 289,
     READ = 290,
     WRITE = 291,
     WHILE = 292,
     DO = 293,
     IF = 294,
     THEN = 295,
     FOR = 296,
     TO = 297,
     IDENT = 298
   };
#endif
/* Tokens.  */
#define ATRIBUICAO 258
#define IGUAL 259
#define MAIOR_IGUAL 260
#define MENOR_IGUAL 261
#define MENOR_MAIOR 262
#define MAIOR 263
#define MENOR 264
#define MAIS 265
#define MENOS 266
#define VEZES 267
#define DIVIDIDO 268
#define VIRGULA 269
#define PONTO_E_VIRGULA 270
#define PONTO 271
#define DOIS_PONTOS 272
#define PARENTESES_ESQUERDO 273
#define PARENTESES_DIREITO 274
#define NUM_INTEIRO 275
#define NUM_REAL 276
#define COMENTARIO 277
#define NUMERO_INT_MAL_FORMADO 278
#define NUMERO_REAL_MAL_FORMADO 279
#define CARACTERES_INVALIDOS 280
#define PROGRAM 281
#define START 282
#define END 283
#define CONST 284
#define VAR 285
#define REAL 286
#define INTEGER 287
#define PROCEDURE 288
#define ELSE 289
#define READ 290
#define WRITE 291
#define WHILE 292
#define DO 293
#define IF 294
#define THEN 295
#define FOR 296
#define TO 297
#define IDENT 298



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
