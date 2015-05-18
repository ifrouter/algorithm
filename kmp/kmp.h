#ifdef __cplusplus
extern "C" {
#endif


#ifndef __KMP_H
#define __KMP_H


/*
* =====================================================================================
*
*       Filename:  kmp.h
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

#include <stdio.h>
#include <string.h>

typedef struct KMP
{
	const char *string;
	int string_len;
	int *jump;
} KMP_MATCH;


KMP_MATCH * kmp_init(const char*s, int slen);
void kmp_free(KMP_MATCH *pkmp);
const char *kmp_match(const char*text, int text_len, KMP_MATCH *pkmp);

#endif

#ifdef __cplusplus
}
#endif