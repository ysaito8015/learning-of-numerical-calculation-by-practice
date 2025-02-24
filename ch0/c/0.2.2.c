#include <stdio.h>

#define typename(x) _Generic((x),    \
    char: "char",        \
    short: "short",        \
    int: "int",            \
    long: "long",        \
    float: "float",        \
    double: "double",    \
    char *: "char *",    \
    short *: "short *",    \
    int *: "int *",        \
    long *: "long *",    \
    void *: "void *",    \
    default: "other")

void main() {
	double a = 1.0;
	float b = 1.0;
	double c = 1.0e2;
	float d = 1.0e2f;

	printf("double a : %f\n", a);
	printf("double a type is: %s\n", typename(a));
	printf("float  b : %f\n", b);
	printf("float  b type is: %s\n", typename(b));
	printf("double c : %f\n", c);
	printf("double c type is: %s\n", typename(c));
	printf("float  d : %f\n", d);
	printf("float  c type is: %s\n", typename(d));
}
