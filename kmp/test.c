#include <stdio.h>
#include <string.h>

#include "kmp.h"

int main()
{
	char *text = "ababababca";
	char *s = "ababca";
	char *result = NULL;
	int i;

	KMP_MATCH *pkmp = kmp_init(s, strlen(s));
	if (pkmp == NULL)
	{
		return 0;
	}


	result = kmp_match(text, strlen(text), pkmp);
	if (result)
	{
		printf("found: offset is %d\n", result-text);
	}
	else
	{
		printf("not found\n");
	}

	kmp_free(pkmp);
	return 0;
}