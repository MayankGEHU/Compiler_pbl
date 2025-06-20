/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylineno;
ASTNode *root;
int yylex(void);
void yyerror(const char *s);

int current_scope = 0;
int semantic_error_found = 0;

typedef enum { SYM_VAR, SYM_FUNC } SymbolKind;

typedef struct Symbol {
    char *name;
    char *type;
    SymbolKind kind;
    int initialized;
    union {
        int int_val;
        float float_val;
        char char_val;
    } value;
    int scope_level;
    struct Symbol *next;
} Symbol;

Symbol *symbol_table = NULL;

void enter_scope() { current_scope++; }
void exit_scope()  { current_scope--; }

void insert_symbol(const char *name, const char *type, SymbolKind kind) {
    Symbol *sym = malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = strdup(type);
    sym->kind = kind;
    sym->initialized = 0;
    sym->scope_level = current_scope;
    sym->next = symbol_table;
    symbol_table = sym;
}

Symbol* get_symbol(const char *name) {
    Symbol *cur = symbol_table;
    while (cur) {
        if (strcmp(cur->name, name) == 0 && cur->scope_level <= current_scope) return cur;
        cur = cur->next;
    }
    return NULL;
}

void mark_initialized(const char *name) {
    Symbol *sym = get_symbol(name);
    if (sym) sym->initialized = 1;
}

void print_symbol_table() {
    printf("\nSymbol Table:\n");
    printf("---------------------------------------------------------------\n");
    printf("| %-15s | %-10s | %-8s | %-4s |\n", "Name", "Type", "Kind", "Scope");
    printf("---------------------------------------------------------------\n");
    Symbol *cur = symbol_table;
    while (cur) {
        printf("| %-15s | %-10s | %-8s | %-4d |\n",
               cur->name,
               cur->type,
               cur->kind == SYM_VAR ? "var" : "func",
               cur->scope_level);
        cur = cur->next;
    }
    printf("---------------------------------------------------------------\n");
}

#line 149 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AUTO = 3,                       /* AUTO  */
  YYSYMBOL_BREAK = 4,                      /* BREAK  */
  YYSYMBOL_CASE = 5,                       /* CASE  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_CONTINUE = 8,                   /* CONTINUE  */
  YYSYMBOL_DEFAULT = 9,                    /* DEFAULT  */
  YYSYMBOL_DO = 10,                        /* DO  */
  YYSYMBOL_DOUBLE = 11,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_ENUM = 13,                      /* ENUM  */
  YYSYMBOL_EXTERN = 14,                    /* EXTERN  */
  YYSYMBOL_FLOAT = 15,                     /* FLOAT  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_GOTO = 17,                      /* GOTO  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_LONG = 20,                      /* LONG  */
  YYSYMBOL_REGISTER = 21,                  /* REGISTER  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_SHORT = 23,                     /* SHORT  */
  YYSYMBOL_SIGNED = 24,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 25,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 26,                    /* STATIC  */
  YYSYMBOL_STRUCT = 27,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 28,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 29,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 30,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 31,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 32,                      /* VOID  */
  YYSYMBOL_VOLATILE = 33,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_STRING = 35,                    /* STRING  */
  YYSYMBOL_IDENTIFIER = 36,                /* IDENTIFIER  */
  YYSYMBOL_DEC_CONSTANT = 37,              /* DEC_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 38,            /* FLOAT_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 39,            /* STRING_LITERAL  */
  YYSYMBOL_HEX_CONSTANT = 40,              /* HEX_CONSTANT  */
  YYSYMBOL_OCT_CONSTANT = 41,              /* OCT_CONSTANT  */
  YYSYMBOL_CHAR_LITERAL = 42,              /* CHAR_LITERAL  */
  YYSYMBOL_EQ = 43,                        /* EQ  */
  YYSYMBOL_NEQ = 44,                       /* NEQ  */
  YYSYMBOL_LE = 45,                        /* LE  */
  YYSYMBOL_GE = 46,                        /* GE  */
  YYSYMBOL_AND = 47,                       /* AND  */
  YYSYMBOL_OR = 48,                        /* OR  */
  YYSYMBOL_SHL = 49,                       /* SHL  */
  YYSYMBOL_SHR = 50,                       /* SHR  */
  YYSYMBOL_INC = 51,                       /* INC  */
  YYSYMBOL_DEC = 52,                       /* DEC  */
  YYSYMBOL_PLUS = 53,                      /* PLUS  */
  YYSYMBOL_MINUS = 54,                     /* MINUS  */
  YYSYMBOL_STAR = 55,                      /* STAR  */
  YYSYMBOL_FW_SLASH = 56,                  /* FW_SLASH  */
  YYSYMBOL_MOD = 57,                       /* MOD  */
  YYSYMBOL_LT = 58,                        /* LT  */
  YYSYMBOL_GT = 59,                        /* GT  */
  YYSYMBOL_ASSIGN = 60,                    /* ASSIGN  */
  YYSYMBOL_BITAND = 61,                    /* BITAND  */
  YYSYMBOL_BITOR = 62,                     /* BITOR  */
  YYSYMBOL_BITXOR = 63,                    /* BITXOR  */
  YYSYMBOL_BITNOT = 64,                    /* BITNOT  */
  YYSYMBOL_NOT = 65,                       /* NOT  */
  YYSYMBOL_DELIMITER = 66,                 /* DELIMITER  */
  YYSYMBOL_COMMA = 67,                     /* COMMA  */
  YYSYMBOL_OPEN_PAR = 68,                  /* OPEN_PAR  */
  YYSYMBOL_CLOSE_PAR = 69,                 /* CLOSE_PAR  */
  YYSYMBOL_OPEN_BRACE = 70,                /* OPEN_BRACE  */
  YYSYMBOL_CLOSE_BRACE = 71,               /* CLOSE_BRACE  */
  YYSYMBOL_OPEN_BRACKET = 72,              /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_BRACKET = 73,             /* CLOSE_BRACKET  */
  YYSYMBOL_UMINUS = 74,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_program = 76,                   /* program  */
  YYSYMBOL_stmt_list = 77,                 /* stmt_list  */
  YYSYMBOL_stmt = 78,                      /* stmt  */
  YYSYMBOL_block = 79,                     /* block  */
  YYSYMBOL_80_1 = 80,                      /* $@1  */
  YYSYMBOL_type = 81,                      /* type  */
  YYSYMBOL_expr = 82,                      /* expr  */
  YYSYMBOL_arg_list = 83                   /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  78

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   329


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   108,   108,   112,   113,   117,   134,   146,   154,   157,
     160,   164,   167,   171,   173,   177,   177,   181,   182,   183,
     184,   188,   189,   190,   191,   198,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   217,   223,   224,
     225
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AUTO", "BREAK",
  "CASE", "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE",
  "ENUM", "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "INT", "LONG",
  "REGISTER", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT",
  "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE",
  "STRING", "IDENTIFIER", "DEC_CONSTANT", "FLOAT_CONSTANT",
  "STRING_LITERAL", "HEX_CONSTANT", "OCT_CONSTANT", "CHAR_LITERAL", "EQ",
  "NEQ", "LE", "GE", "AND", "OR", "SHL", "SHR", "INC", "DEC", "PLUS",
  "MINUS", "STAR", "FW_SLASH", "MOD", "LT", "GT", "ASSIGN", "BITAND",
  "BITOR", "BITXOR", "BITNOT", "NOT", "DELIMITER", "COMMA", "OPEN_PAR",
  "CLOSE_PAR", "OPEN_BRACE", "CLOSE_BRACE", "OPEN_BRACKET",
  "CLOSE_BRACKET", "UMINUS", "$accept", "program", "stmt_list", "stmt",
  "block", "$@1", "type", "expr", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -68,   -68,   -67,   -68,   172,   -64,   -68,   -57,   -68,
     -68,   -68,   -68,   172,   -68,    14,     4,   -68,   -68,   -21,
      96,   172,   -44,   113,   172,   172,   172,    10,     4,   -68,
     -68,   155,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   -68,    45,   -68,    62,   130,    79,   -42,    -6,
     172,   -68,   -35,   174,   174,   174,   174,   -38,   -38,    10,
      10,   174,   174,     4,     4,   -68,   172,   -68,   -68,   147,
     -45,    25,   -68,   -68,   -68,   -68,     4,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    19,    18,     0,    17,     0,     0,    20,    36,    32,
      33,    34,    35,     0,    15,     0,     2,     3,    14,     0,
       0,     0,    36,     0,     0,     0,    40,    25,     0,     1,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     8,     0,     0,    39,     0,     0,
       0,     7,     0,    28,    29,    31,    30,    21,    22,    23,
      24,    27,    26,     0,     0,     6,    40,    37,    16,     0,
       0,     9,    11,    38,     5,    12,     0,    10
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,    16,   -14,   -25,   -68,   -68,    46,   -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    15,    16,    17,    18,    28,    19,    20,    48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       1,    21,    30,    25,    24,    32,    33,    34,    35,     2,
       1,    26,     3,     4,    29,    31,     5,    38,    39,     2,
      40,    41,     3,     4,    26,    14,     5,    67,     6,     7,
       8,     9,    10,    11,    70,    30,    12,    76,     6,     7,
       8,     9,    10,    11,    49,    75,    12,    73,    13,    71,
      72,    23,     0,    32,    33,    34,    35,     0,    13,    27,
       0,     0,    77,     0,    14,    68,     0,    43,    40,    41,
      45,    46,    47,     0,    14,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    32,    33,
      34,    35,     0,     0,     0,     0,    69,     0,    36,    37,
      38,    39,     0,    40,    41,    32,    33,    34,    35,     0,
       0,     0,    47,     0,    63,    36,    37,    38,    39,     0,
      40,    41,    32,    33,    34,    35,     0,     0,     0,     0,
       0,    64,    36,    37,    38,    39,     0,    40,    41,    32,
      33,    34,    35,     0,     0,     0,    66,     0,     0,    36,
      37,    38,    39,     0,    40,    41,    32,    33,    34,    35,
       0,     0,    42,     0,     0,     0,    36,    37,    38,    39,
       0,    40,    41,    32,    33,    34,    35,     0,     0,    44,
       0,     0,     0,    36,    37,    38,    39,     0,    40,    41,
      32,    33,    34,    35,     0,     0,    65,     0,     0,     0,
      36,    37,    38,    39,     0,    40,    41,     0,    22,     9,
      10,    11,     0,    74,    12,    50,     0,    32,    33,    34,
      35,    51,     0,    52,     0,     0,    13,    36,    37,    38,
      39,     0,    40,    41
};

static const yytype_int8 yycheck[] =
{
       6,    68,    16,    60,    68,    43,    44,    45,    46,    15,
       6,    68,    18,    19,     0,    36,    22,    55,    56,    15,
      58,    59,    18,    19,    68,    70,    22,    69,    34,    35,
      36,    37,    38,    39,    69,    49,    42,    12,    34,    35,
      36,    37,    38,    39,    28,    70,    42,    66,    54,    63,
      64,     5,    -1,    43,    44,    45,    46,    -1,    54,    13,
      -1,    -1,    76,    -1,    70,    71,    -1,    21,    58,    59,
      24,    25,    26,    -1,    70,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    50,    -1,    53,    54,
      55,    56,    -1,    58,    59,    43,    44,    45,    46,    -1,
      -1,    -1,    66,    -1,    69,    53,    54,    55,    56,    -1,
      58,    59,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    69,    53,    54,    55,    56,    -1,    58,    59,    43,
      44,    45,    46,    -1,    -1,    -1,    67,    -1,    -1,    53,
      54,    55,    56,    -1,    58,    59,    43,    44,    45,    46,
      -1,    -1,    66,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    58,    59,    43,    44,    45,    46,    -1,    -1,    66,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    58,    59,
      43,    44,    45,    46,    -1,    -1,    66,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    58,    59,    -1,    36,    37,
      38,    39,    -1,    66,    42,    60,    -1,    43,    44,    45,
      46,    66,    -1,    68,    -1,    -1,    54,    53,    54,    55,
      56,    -1,    58,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    15,    18,    19,    22,    34,    35,    36,    37,
      38,    39,    42,    54,    70,    76,    77,    78,    79,    81,
      82,    68,    36,    82,    68,    60,    68,    82,    80,     0,
      78,    36,    43,    44,    45,    46,    53,    54,    55,    56,
      58,    59,    66,    82,    66,    82,    82,    82,    83,    77,
      60,    66,    68,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    69,    69,    66,    67,    69,    71,    82,
      69,    78,    78,    83,    66,    79,    12,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    80,    79,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    83,    83,
      83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     5,     4,     3,     3,     5,
       7,     5,     5,     2,     1,     0,     4,     1,     1,     1,
       1,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     4,     3,     1,
       0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: stmt_list  */
#line 108 "parser.y"
              { root = (yyvsp[0].node); }
#line 1302 "parser.tab.c"
    break;

  case 3: /* stmt_list: stmt  */
#line 112 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1308 "parser.tab.c"
    break;

  case 4: /* stmt_list: stmt_list stmt  */
#line 113 "parser.y"
                     { (yyval.node) = create_binary_op_node(";", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1314 "parser.tab.c"
    break;

  case 5: /* stmt: type IDENTIFIER ASSIGN expr DELIMITER  */
#line 117 "parser.y"
                                          {
        if (get_symbol((yyvsp[-3].str))) {
            fprintf(stderr, "Semantic Error: Variable '%s' redeclared\n", (yyvsp[-3].str));
            semantic_error_found = 1;
        }
        (yyval.node) = create_assignment_node((yyvsp[-3].str), (yyvsp[-1].node));
        (yyval.node)->left = create_declaration_node((yyvsp[-4].str), (yyvsp[-3].str), NULL);
        (yyval.node)->right->data_type = (yyvsp[-1].node)->data_type;
        (yyval.node)->left->data_type = strdup((yyvsp[-4].str));
        if (strcmp((yyvsp[-4].str), (yyvsp[-1].node)->data_type) != 0) {
            fprintf(stderr, "Semantic Error: Type mismatch in assignment to '%s' (declared as %s, assigned %s)\n",
            (yyvsp[-3].str), (yyvsp[-4].str), (yyvsp[-1].node)->data_type);
            semantic_error_found = 1;
        }
        insert_symbol((yyvsp[-3].str), (yyvsp[-4].str), SYM_VAR);
        mark_initialized((yyvsp[-3].str));
    }
#line 1336 "parser.tab.c"
    break;

  case 6: /* stmt: IDENTIFIER ASSIGN expr DELIMITER  */
#line 134 "parser.y"
                                       {
        Symbol *sym = get_symbol((yyvsp[-3].str));
        if (!sym) {
            fprintf(stderr, "Semantic Error: '%s' not declared\n", (yyvsp[-3].str));
            semantic_error_found = 1;
        }
        (yyval.node) = create_assignment_node((yyvsp[-3].str), (yyvsp[-1].node));
        (yyval.node)->left = create_identifier_node((yyvsp[-3].str));
        (yyval.node)->left->data_type = sym ? strdup(sym->type) : strdup("unknown");
        (yyval.node)->right->data_type = (yyvsp[-1].node)->data_type;
        mark_initialized((yyvsp[-3].str));
    }
#line 1353 "parser.tab.c"
    break;

  case 7: /* stmt: type IDENTIFIER DELIMITER  */
#line 146 "parser.y"
                                {
        if (get_symbol((yyvsp[-1].str))) {
            fprintf(stderr, "Semantic Error: Variable '%s' redeclared\n", (yyvsp[-1].str));
            semantic_error_found = 1;
        }
        (yyval.node) = create_declaration_node((yyvsp[-2].str), (yyvsp[-1].str), NULL);
        insert_symbol((yyvsp[-1].str), (yyvsp[-2].str), SYM_VAR);
    }
#line 1366 "parser.tab.c"
    break;

  case 8: /* stmt: RETURN expr DELIMITER  */
#line 154 "parser.y"
                            {
        (yyval.node) = create_binary_op_node("return", (yyvsp[-1].node), NULL);
    }
#line 1374 "parser.tab.c"
    break;

  case 9: /* stmt: IF OPEN_PAR expr CLOSE_PAR stmt  */
#line 157 "parser.y"
                                      {
        (yyval.node) = create_binary_op_node("if", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1382 "parser.tab.c"
    break;

  case 10: /* stmt: IF OPEN_PAR expr CLOSE_PAR stmt ELSE stmt  */
#line 160 "parser.y"
                                                {
        ASTNode *if_node = create_binary_op_node("if", (yyvsp[-4].node), (yyvsp[-2].node));
        (yyval.node) = create_binary_op_node("else", if_node, (yyvsp[0].node));
    }
#line 1391 "parser.tab.c"
    break;

  case 11: /* stmt: WHILE OPEN_PAR expr CLOSE_PAR stmt  */
#line 164 "parser.y"
                                         {
        (yyval.node) = create_binary_op_node("while", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1399 "parser.tab.c"
    break;

  case 12: /* stmt: type IDENTIFIER OPEN_PAR CLOSE_PAR block  */
#line 167 "parser.y"
                                               {
        insert_symbol((yyvsp[-3].str), (yyvsp[-4].str), SYM_FUNC);
        (yyval.node) = create_binary_op_node("function", create_identifier_node((yyvsp[-3].str)), (yyvsp[0].node));
    }
#line 1408 "parser.tab.c"
    break;

  case 13: /* stmt: expr DELIMITER  */
#line 171 "parser.y"
                     { (yyval.node) = (yyvsp[-1].node);
    }
#line 1415 "parser.tab.c"
    break;

  case 14: /* stmt: block  */
#line 173 "parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1421 "parser.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 177 "parser.y"
               { enter_scope(); }
#line 1427 "parser.tab.c"
    break;

  case 16: /* block: OPEN_BRACE $@1 stmt_list CLOSE_BRACE  */
#line 177 "parser.y"
                                                        { exit_scope(); (yyval.node) = (yyvsp[-1].node); }
#line 1433 "parser.tab.c"
    break;

  case 17: /* type: INT  */
#line 181 "parser.y"
        { (yyval.str) = strdup("int"); }
#line 1439 "parser.tab.c"
    break;

  case 18: /* type: FLOAT  */
#line 182 "parser.y"
            { (yyval.str) = strdup("float"); }
#line 1445 "parser.tab.c"
    break;

  case 19: /* type: CHAR  */
#line 183 "parser.y"
           { (yyval.str) = strdup("char"); }
#line 1451 "parser.tab.c"
    break;

  case 20: /* type: STRING  */
#line 184 "parser.y"
             { (yyval.str) = strdup("string"); }
#line 1457 "parser.tab.c"
    break;

  case 21: /* expr: expr PLUS expr  */
#line 188 "parser.y"
                   { (yyval.node) = create_binary_op_node("+", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = (yyvsp[-2].node)->data_type; }
#line 1463 "parser.tab.c"
    break;

  case 22: /* expr: expr MINUS expr  */
#line 189 "parser.y"
                      { (yyval.node) = create_binary_op_node("-", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = (yyvsp[-2].node)->data_type; }
#line 1469 "parser.tab.c"
    break;

  case 23: /* expr: expr STAR expr  */
#line 190 "parser.y"
                     { (yyval.node) = create_binary_op_node("*", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = (yyvsp[-2].node)->data_type; }
#line 1475 "parser.tab.c"
    break;

  case 24: /* expr: expr FW_SLASH expr  */
#line 191 "parser.y"
                         {
        (yyval.node) = create_binary_op_node("/", (yyvsp[-2].node), (yyvsp[0].node));
        if (strcmp((yyvsp[0].node)->data_type, "int") == 0 && (yyvsp[0].node)->type == NODE_TYPE_LITERAL && (yyvsp[0].node)->value.int_val == 0) {
            fprintf(stderr, "Semantic Error: Division by zero at line %d\n", yylineno);
        }
        (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
    }
#line 1487 "parser.tab.c"
    break;

  case 25: /* expr: MINUS expr  */
#line 198 "parser.y"
                              {
        (yyval.node) = create_binary_op_node("UMINUS", (yyvsp[0].node), NULL);
        (yyval.node)->data_type = (yyvsp[0].node)->data_type;
    }
#line 1496 "parser.tab.c"
    break;

  case 26: /* expr: expr GT expr  */
#line 202 "parser.y"
                   { (yyval.node) = create_binary_op_node(">", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = strdup("int"); }
#line 1502 "parser.tab.c"
    break;

  case 27: /* expr: expr LT expr  */
#line 203 "parser.y"
                   { (yyval.node) = create_binary_op_node("<", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = strdup("int"); }
#line 1508 "parser.tab.c"
    break;

  case 28: /* expr: expr EQ expr  */
#line 204 "parser.y"
                   { (yyval.node) = create_binary_op_node("==", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = strdup("int"); }
#line 1514 "parser.tab.c"
    break;

  case 29: /* expr: expr NEQ expr  */
#line 205 "parser.y"
                    { (yyval.node) = create_binary_op_node("!=", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = strdup("int"); }
#line 1520 "parser.tab.c"
    break;

  case 30: /* expr: expr GE expr  */
#line 206 "parser.y"
                   { (yyval.node) = create_binary_op_node(">=", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = strdup("int"); }
#line 1526 "parser.tab.c"
    break;

  case 31: /* expr: expr LE expr  */
#line 207 "parser.y"
                   { (yyval.node) = create_binary_op_node("<=", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = strdup("int"); }
#line 1532 "parser.tab.c"
    break;

  case 32: /* expr: DEC_CONSTANT  */
#line 208 "parser.y"
                   { (yyval.node) = create_literal_node("int", atoi((yyvsp[0].str)), 0, NULL); (yyval.node)->data_type = strdup("int"); }
#line 1538 "parser.tab.c"
    break;

  case 33: /* expr: FLOAT_CONSTANT  */
#line 209 "parser.y"
                     { (yyval.node) = create_literal_node("float", 0, atof((yyvsp[0].str)), NULL); (yyval.node)->data_type = strdup("float"); }
#line 1544 "parser.tab.c"
    break;

  case 34: /* expr: STRING_LITERAL  */
#line 210 "parser.y"
                     { (yyval.node) = create_literal_node("string", 0, 0, (yyvsp[0].str)); (yyval.node)->data_type = strdup("string"); }
#line 1550 "parser.tab.c"
    break;

  case 35: /* expr: CHAR_LITERAL  */
#line 211 "parser.y"
                   { (yyval.node) = create_literal_node("char", (int)(yyvsp[0].str)[1], 0, NULL); (yyval.node)->data_type = strdup("char"); }
#line 1556 "parser.tab.c"
    break;

  case 36: /* expr: IDENTIFIER  */
#line 212 "parser.y"
                 {
        (yyval.node) = create_identifier_node((yyvsp[0].str));
        Symbol *sym = get_symbol((yyvsp[0].str));
        (yyval.node)->data_type = sym ? strdup(sym->type) : strdup("unknown");
    }
#line 1566 "parser.tab.c"
    break;

  case 37: /* expr: IDENTIFIER OPEN_PAR arg_list CLOSE_PAR  */
#line 217 "parser.y"
                                             {
        (yyval.node) = create_func_call_node((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 1574 "parser.tab.c"
    break;

  case 38: /* arg_list: expr COMMA arg_list  */
#line 223 "parser.y"
                        { (yyval.node) = create_binary_op_node(",", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1580 "parser.tab.c"
    break;

  case 39: /* arg_list: expr  */
#line 224 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1586 "parser.tab.c"
    break;

  case 40: /* arg_list: %empty  */
#line 225 "parser.y"
                  { (yyval.node) = NULL; }
#line 1592 "parser.tab.c"
    break;


#line 1596 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 228 "parser.y"


int main() {
    insert_symbol("printf", "int", SYM_FUNC);
    yyparse();
    printf("\nGenerated AST:\n");
    print_ast(root, 0);
    printf("\nSemantic Analysis:\n");
    type_check(root);
    if (semantic_error_found) {
        printf("Semantic Errors were found during analysis.\n");
    }else{
        printf("No semantic Errors were found during analysis.\n");
    }
    printf("Semantic analysis completed.\n");
    print_symbol_table();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}
