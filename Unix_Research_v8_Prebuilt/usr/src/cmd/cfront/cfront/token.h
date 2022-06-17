/* @(#) token.h 1.1 1/17/85 12:40:20 */
#ifndef EOF
#include "stdio.h"
#endif
extern void lex_clear();
extern void ktbl_init();
extern void otbl_init();

#define yylex()	lalex()

#define putstring(s)	fputs(s,out_file)
#define putst(ss)	fprintf(out_file,"%s ",ss)
#define putch(c)	putc(c,out_file)

			/* token numbers for C parser	*/

#define MAXTOK 256
extern char* keys[MAXTOK];

#define EOFTOK	0	/* 	EOF	*/
			/* keywords in alphabetical order */
#define ASM		1
#define AUTO		2
#define BREAK		3
#define CASE		4
#define CHAR		5
#define CLASS		6
#define CONTINUE	7
#define DEFAULT		8
#define DELETE		9
#define DO		10
#define DOUBLE		11
#define ELSE		12
#define ENUM		13
#define EXTERN		14
#define FLOAT		15
#define FOR		16
#define FORTRAN		17
#define FRIEND		18
#define GOTO		19
#define IF		20
#define INT		21
#define LONG		22
#define NEW		23
#define OPERATOR	24
#define PUBLIC		25
#define CONST		26
#define REGISTER	27
#define RETURN		28
#define SHORT		29
#define SIZEOF		30
#define STATIC		31
#define STRUCT		32
#define SWITCH		33
#define THIS		34
#define TYPEDEF		35
#define UNION		36
#define UNSIGNED	37
#define VOID		38
#define WHILE		39

			/* operators in priority order (sort of) */
#define LP		40
#define RP		41
#define LB		42
#define RB		43
#define REF		44
#define DOT		45
#define NOT		46
#define COMPL		47
#define INCR		48
#define DECR		49
#define MUL		50
#define DIV		51
#define AND		52
#define MOD		53
#define PLUS		54
#define MINUS		55
#define LS		56
#define RS		57
#define LT		58
#define LE		59
#define GT		60
#define GE		61
#define EQ		62
#define NE		63
#define ER		64
#define OR		65
#define ANDAND		66
#define OROR		67
#define QUEST		68
#define COLON		69
#define ASSIGN		70
#define CM		71
#define SM		72
#define LC		73
#define RC		74

#define INLINE		75
#define OVERLOAD	76
#define VIRTUAL		77
#define COERCE		78

			/* constants etc. */
#define ID		80
#define STRING		81
#define ICON		82
#define FCON		83
#define CCON		84
#define NAME		85
#define ZERO		86

			/* groups of tokens */
#define ASOP		90	/* op= */
#define RELOP		91	/* LE GE LT GT */
#define EQUOP		92	/* EQ NE */
#define DIVOP		93	/* DIV MOD */
#define SHIFTOP		94	/* LS RS */
#define ICOP		95	/* INCR DECR */
#define UNOP		96	/* NOT COMPL */
#define TYPE		97
	/* TYPE =	INT FLOAT CHAR DOUBLE REGISTER STATIC EXTERN AUTO
			LONG SHORT UNSIGNED INLINE FRIEND VIRTUAL */

			/* new tokens generated by syn() */
#define UMINUS		107
#define FCT		108
#define CALL		109
#define VEC		110
#define DEREF		111
#define ADDROF		112
#define CAST		113
#define ENDCAST		122
#define FIELD		114
#define LABEL		115
#define BLOCK		116
#define QUA		117
#define DCL		118
#define COBJ		119
#define EOBJ		121
#define TNAME		123
#define ILIST		124
#define PTR		125

#define ASPLUS		126
#define ASMINUS		127
#define ASMUL		128
#define ASDIV		129
#define ASMOD		130
#define ASAND		131
#define ASOR		132
#define ASER		133
#define ASLS		134
#define ASRS		135

#define ARG		136
#define KNOWN		137
#define ZTYPE		138
#define ARGT		139
#define ELIST		140
#define ANY		141
#define TABLE		142
#define LOC		143
#define DUMMY		144
#define G_ADDROF	145
#define G_CALL		146
#define IVAL		150
#define FVAL		151
#define LVAL		152
#define ELLIPSIS	155
#define AGGR		156
#define VALUE		157
#define RPTR		158
#define HIDDEN		159
#define MEM		160
#define CTOR		161
#define DTOR		162
#define CONST_PTR	163
#define CONST_RPTR	164
#define TEXT		165
#define PAIR		166
#define ANON		167
#define ICALL		168
#define ANAME		169
#define VOLATILE	170
#define SIGNED		171
#define UPLUS		172

#define A	'A'
#define I	'I'
#define Z	'Z'
#define F	'F'
#define P	'P'
#define C	'C'
#define N	'N'
#define U	'U'
#define S	'S'

#define SYN	1
#define TYP	2
#define SIMPL	3
#define ERROR	4
