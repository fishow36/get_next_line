#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char *str;
	int a;
	
	a = get_next_line(1, &str);
	printf("gnl %d\n", a);
	printf("gnl %s\n", str);
}