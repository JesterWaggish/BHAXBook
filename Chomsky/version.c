/*
 * Compile:	gcc version.c -o version -Wall -std=c89
 * Run:		./version
 * Check with splint: splint version.c
 *
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int f(int x, int y){
	printf("F-ben %d %d\n", x, y);
	return x + y;
}

int g(int x){
	printf("G-ben %d\n", x);
	x *= 2;
	return x;
}

int h(int* x){
	printf("H-ban %d\n", *x);
	*x *= 2;
	printf("H-ban 2 %d\n", *x);
	return *x;
}

void jelkezelo(){
	printf("\nJel érkezett\n");
	exit(0);
}

int main()
{

	if(signal(SIGINT, jelkezelo)==SIG_IGN)
		signal(SIGINT, SIG_IGN);

	int tomb[10];
	int dt[40], st[40];
	int *s = st;
	int *d = dt;
	int n = 40;
	int a = 42;

	int i = 0;
	for(i = 0; i < 10; i++)
		printf("%d\n", i);

	/*
	* for c99 example
	for(int j = 0; j < 10; j++)
		printf("%d\n", j);
	*/

	for(i = 0; i < 10; tomb[i] = i++)
		printf("%d\n", tomb[i]);

	for(i = 0; i < n && (*d++ = *s++); i++)
		printf("%d\n", i);

	printf("F-en kívül: %d %d\n", f(a, ++a), f(++a, a));

	printf("G-n kívül: %d %d\n", g(a), a);

	printf("H-n kívül: %d %d\n", h(&a), a);

	for(;;){}

	return 0;
}


/* Splint output:
Splint 3.1.2 --- 20 Feb 2018

version.c: (in function main)
version.c:39:3: Return value (type [function (int) returns void]) ignored:
                   signal(SIGINT, S...
  Result returned by function call is not used. If this is intended, can cast
  result to (void) to eliminate message. (Use -retvalother to inhibit warning)
version.c:58:32: Expression has undefined behavior (left operand uses i,
                    modified by right operand): tomb[i] = i++
  Code has unspecified behavior. Order of evaluation of function parameters or
  subexpressions is not defined, so if a value is used and modified in
  different places not separated by a sequence point constraining evaluation
  order, then the result of the expression is unspecified. (Use -evalorder to
  inhibit warning)
version.c:61:22: Right operand of && is non-boolean (int):
                    i < n && (*d++ = *s++)
  The operand of a boolean operator is not a boolean. Use +ptrnegate to allow !
  to be used on pointers. (Use -boolops to inhibit warning)
version.c:64:39: Argument 2 modifies a, used by argument 1 (order of evaluation
                    of actual parameters is undefined): f(a, ++a)
version.c:64:47: Argument 1 modifies a, used by argument 2 (order of evaluation
                    of actual parameters is undefined): f(++a, a)
version.c:64:34: Argument 2 modifies a, used by argument 3 (order of evaluation
    of actual parameters is undefined): printf("F-en kívül:
    %d %d\n", f(a, ++a), f(++a, a))
version.c:64:45: Argument 3 modifies a, used by argument 2 (order of evaluation
    of actual parameters is undefined): printf("F-en kívül:
    %d %d\n", f(a, ++a), f(++a, a))
version.c:72:9: Unreachable code: return 0
  This code will never be reached on any possible execution. (Use -unreachable
  to inhibit warning)
version.c:12:5: Function exported but not used outside version: f
  A declaration is exported, but not used outside this module. Declaration can
  use static qualifier. (Use -exportlocal to inhibit warning)
   version.c:15:1: Definition of f
version.c:17:5: Function exported but not used outside version: g
   version.c:21:1: Definition of g
version.c:23:5: Function exported but not used outside version: h
   version.c:28:1: Definition of h
version.c:30:6: Function exported but not used outside version: jelkezelo
   version.c:33:1: Definition of jelkezelo

Finished checking --- 12 code warnings
*/