/*
* =====================================================================================
*
*       Filename:  kmp.c
*
*    Description:  Knuth-Morris-Pratt string matching
*
*        Version:  1.0
*        Created:  5/6/2015 2:52:13 PM
*       Revision:  none
*
*         Author:  ifrouter
*        Company:  ifrouter.blogspot.com
*
* =====================================================================================
*/
#include "kmp.h"

static int kmp_compute_prefix(const char *s, int slen)
{
	int i ;
	for (i = 1; i <slen;i++)
	{
		if (!memcmp(s+i, s, slen-i))
			return slen - i;
	}
	return 0;
}
KMP_MATCH * kmp_init(const char*s, int slen)
{
	int i = 0;
	KMP_MATCH *pkmp = NULL;
	if (s <= 0) return NULL;
	if (slen < 1) return NULL;

	pkmp = malloc(sizeof(KMP_MATCH));

	if (pkmp == NULL)	return NULL;

	pkmp->string = malloc(slen);
	if (NULL == pkmp->string)
	{
		free(pkmp);
		return NULL;
	}
	pkmp->jump = malloc(sizeof(int)*slen);
	if (NULL == pkmp->jump)
	{
		free(pkmp->string);
		free(pkmp);
		return NULL;
	}
	pkmp->string_len = slen;
	memcpy(pkmp->string, s, slen);
	

	for (i = 0; i < pkmp->string_len; i++)
	{
		pkmp->jump[i] = kmp_compute_prefix(pkmp->string, i + 1);
	}

	return pkmp;
}

void kmp_free(KMP_MATCH *pkmp)
{
	free(pkmp->jump);
	free(pkmp->string);
	free(pkmp);
	pkmp = NULL;
}

const char *kmp_match(const char*text, int text_len,KMP_MATCH *pkmp)
{
	int i;
	int j=0;
	if (pkmp == NULL)	return NULL;

	for (i = 0; i < text_len;i++)
	{
		if (pkmp->string[j] == text[i])
		{
			++j;
			if (j == pkmp->string_len)
			{
				return text + i+1 -j;
			}
		}
		else
		{
			if ( j>0)
			{
				j=pkmp->jump[j-1];
				--i;
			}
		}
	}
	return NULL;
}
