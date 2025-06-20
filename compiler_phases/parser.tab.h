/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AUTO = 258,                    /* AUTO  */
    BREAK = 259,                   /* BREAK  */
    CASE = 260,                    /* CASE  */
    CHAR = 261,                    /* CHAR  */
    CONST = 262,                   /* CONST  */
    CONTINUE = 263,                /* CONTINUE  */
    DEFAULT = 264,                 /* DEFAULT  */
    DO = 265,                      /* DO  */
    DOUBLE = 266,                  /* DOUBLE  */
    ELSE = 267,                    /* ELSE  */
    ENUM = 268,                    /* ENUM  */
    EXTERN = 269,                  /* EXTERN  */
    FLOAT = 270,                   /* FLOAT  */
    FOR = 271,                     /* FOR  */
    GOTO = 272,                    /* GOTO  */
    IF = 273,                      /* IF  */
    INT = 274,                     /* INT  */
    LONG = 275,                    /* LONG  */
    REGISTER = 276,                /* REGISTER  */
    RETURN = 277,                  /* RETURN  */
    SHORT = 278,                   /* SHORT  */
    SIGNED = 279,                  /* SIGNED  */
    SIZEOF = 280,                  /* SIZEOF  */
    STATIC = 281,                  /* STATIC  */
    STRUCT = 282,                  /* STRUCT  */
    SWITCH = 283,                  /* SWITCH  */
    TYPEDEF = 284,                 /* TYPEDEF  */
    UNION = 285,                   /* UNION  */
    UNSIGNED = 286,                /* UNSIGNED  */
    VOID = 287,                    /* VOID  */
    VOLATILE = 288,                /* VOLATILE  */
    WHILE = 289,                   /* WHILE  */
    STRING = 290,                  /* STRING  */
    IDENTIFIER = 291,              /* IDENTIFIER  */
    DEC_CONSTANT = 292,            /* DEC_CONSTANT  */
    FLOAT_CONSTANT = 293,          /* FLOAT_CONSTANT  */
    STRING_LITERAL = 294,          /* STRING_LITERAL  */
    HEX_CONSTANT = 295,            /* HEX_CONSTANT  */
    OCT_CONSTANT = 296,            /* OCT_CONSTANT  */
    CHAR_LITERAL = 297,            /* CHAR_LITERAL  */
    EQ = 298,                      /* EQ  */
    NEQ = 299,                     /* NEQ  */
    LE = 300,                      /* LE  */
    GE = 301,                      /* GE  */
    AND = 302,                     /* AND  */
    OR = 303,                      /* OR  */
    SHL = 304,                     /* SHL  */
    SHR = 305,                     /* SHR  */
    INC = 306,                     /* INC  */
    DEC = 307,                     /* DEC  */
    PLUS = 308,                    /* PLUS  */
    MINUS = 309,                   /* MINUS  */
    STAR = 310,                    /* STAR  */
    FW_SLASH = 311,                /* FW_SLASH  */
    MOD = 312,                     /* MOD  */
    LT = 313,                      /* LT  */
    GT = 314,                      /* GT  */
    ASSIGN = 315,                  /* ASSIGN  */
    BITAND = 316,                  /* BITAND  */
    BITOR = 317,                   /* BITOR  */
    BITXOR = 318,                  /* BITXOR  */
    BITNOT = 319,                  /* BITNOT  */
    NOT = 320,                     /* NOT  */
    DELIMITER = 321,               /* DELIMITER  */
    COMMA = 322,                   /* COMMA  */
    OPEN_PAR = 323,                /* OPEN_PAR  */
    CLOSE_PAR = 324,               /* CLOSE_PAR  */
    OPEN_BRACE = 325,              /* OPEN_BRACE  */
    CLOSE_BRACE = 326,             /* CLOSE_BRACE  */
    OPEN_BRACKET = 327,            /* OPEN_BRACKET  */
    CLOSE_BRACKET = 328,           /* CLOSE_BRACKET  */
    UMINUS = 329                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 79 "parser.y"

    int intval;
    float floatval;
    char *str;
    struct ASTNode *node;

#line 145 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
