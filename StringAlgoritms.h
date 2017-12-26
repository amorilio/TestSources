// StringAlgoritms.h: interface for the StringAlgoritms class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRINGALGORITMS_H__879BE5DD_201D_4C4B_948F_6F184730B77E__INCLUDED_)
#define AFX_STRINGALGORITMS_H__879BE5DD_201D_4C4B_948F_6F184730B77E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class StringAlgoritms
{
public:
	StringAlgoritms();
	virtual ~StringAlgoritms();

	/* UTILITY FUNCTIONS */
	/*Function to reverse any sequence starting with pointer begin and ending with pointer end  */
	void reverse(char *begin, char *end);
	/* Function to swap values at two pointers */
	void swapChars (char *x, char *y);
	/* UTILITY FUNCTIONS */

	bool		Palindrome(int input);
	bool		isAnagramInPlace(char *a, char *b);
	bool		isAnagramWithTemp(char *a, char *b);
	int			isSubset(char *a, char *b);
	void		reverseWords(char *s);
	void		divideString(char *str, int n);
	char*		encode(char *src);
	int			firstNonRepeating(char *str);
	void		permute(char *a, int i, int n) ;
	void		reverseRecursion(char *str);
	int			areRotations(char *str1, char *str2);
	char*		removeDirtyChars(char *str, char *mask_str);
	void		printDups(char *str);
	char*		removeDups(char *str);
	char		getMaxOccuringChar(char *str);
	unsigned	countWords(char *str);
};

#endif // !defined(AFX_STRINGALGORITMS_H__879BE5DD_201D_4C4B_948F_6F184730B77E__INCLUDED_)
