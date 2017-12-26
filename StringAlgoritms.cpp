// StringAlgoritms.cpp: implementation of the StringAlgoritms class.
//
//////////////////////////////////////////////////////////////////////

#include "StringAlgoritms.h"
#include <iostream>

using namespace std;

#define NO_OF_CHARS 256
#define MAX_RLEN 50
#define OUT	0
#define IN	1

#pragma warning (disable : 4996)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


extern void ccrush(char* str);

StringAlgoritms::StringAlgoritms()
{
    char* testStr	= new char[256];
    char* testStr1	= new char[256];
    char* sOutput;
    int  i;
    char c;

	char str[] = "abbba";
	ccrush(str);

    cout<< "----------------- Start String Algorithm Examples -----------------" << endl;

    //Test 1
    std::cout<<"--Test 1--Palindrome--"<<endl;
    Palindrome(121);
    Palindrome(1212);
    std::cout<<endl;

    //Test 2
    std::cout<<"--Test 2--isAnagram--"<<endl;
    char * a = new char[4];
    char * b = new char[4];
    // With Sorting.
    sprintf(a,"abcd");
    sprintf(b,"bcda");
    cout << "Strings " << a << " and " << b << (isAnagramInPlace(a, b) ? " are anagram" : " are not anagram ") << endl;
    sprintf(a, "abcd");
    sprintf(b, "bcda");
    cout<< "Strings "<<a<<" and "<<b<< (isAnagramWithTemp(a, b) ? " are anagram" : " are not anagram ") <<endl;
    // With Temp Arrays
    sprintf(a,"abcd");
    sprintf(b,"hcda");
    cout<< "Strings "<<a<<" and "<<b<< (isAnagramInPlace(a, b) ? " are anagram" : " are not anagram ") <<endl;
    cout<< "Strings "<<a<<" and "<<b<< (isAnagramWithTemp(a, b) ? " are anagram" : " are not anagram ") <<endl;
    std::cout<<endl;

    //Test 3
    strcpy(testStr, "ilia Manasherov is good boy");
    std::cout<<"--Test 3--reverseWords--Input: "<<testStr<<endl;
    reverseWords(testStr);
    std::cout<<"-- Output: "<<testStr<<endl<<endl;

    //Test 4
    strcpy(testStr, "ilia Manasherov is good boy");
    std::cout<<"--Test 4--divideString--9--Input: "<<testStr<<endl;
    divideString(testStr,9);
    std::cout<<endl;

    //Test 5
    strcpy(testStr, "ilia Manasherov is good boy");
    std::cout<<"--Test 5--encode--Input: "<<testStr<<endl;
    char* outStr = encode(testStr);
    std::cout<<"-- Output: "<<outStr<<endl<<endl;

    //Test 6
    strcpy(testStr, "ilia Manasherov is good boy");
    std::cout<<"--Test 6--firstNonRepeating--Input: "<<testStr<<endl;
    int	firstNonRepeated = firstNonRepeating(testStr);
    std::cout<<"-- Output: "<<firstNonRepeated<<endl<<endl;

    //Test 7
    strcpy(testStr, "abcd");
    std::cout<<"--Test 7--permute--Input: "<<testStr<<endl;
    permute(testStr, 0, 3) ;
    std::cout<<endl;

    //Test 8
    strcpy(testStr, "ilia Manasherov is good boy");
    std::cout<<"--Test 8--reverseRecursion--Input: "<<testStr<<endl;
    reverseRecursion(testStr);
    std::cout<<endl<<endl;

    //Test 9
    strcpy(testStr, "abcd");
    strcpy(testStr1, "dcba");
    std::cout<<"--Test 9--areRotations--Input: "<<testStr<<" "<<testStr1<<endl;
    i = areRotations(testStr1, testStr1);
    std::cout<<"-- Output: "<<i<<endl<<endl;

    //Test 10
    strcpy(testStr, "ilia Manasherov is good boy");
    strcpy(testStr1, "is");
    std::cout<<"--Test 10--removeDirtyChars--Input: "<<testStr<<" "<<testStr1<<endl;
    sOutput = removeDirtyChars(testStr, testStr1);
    std::cout<<"-- Output: "<<sOutput<<endl<<endl;

    //Test 11
    strcpy(testStr, "ilia Manasherov is good boy");
    std::cout<<"--Test 11--printDups--Input: "<<testStr<<endl;
    printDups(testStr);
    std::cout<<endl;

    //Test 12
    strcpy(testStr, "ilia Manasherov is good boy");
    std::cout<<"--Test 12--removeDups--Input: "<<testStr<<endl;
    sOutput = sOutput, removeDups(testStr);
    std::cout<<"-- Output: "<<sOutput<<endl<<endl;

    //Test 13
    strcpy(testStr, "ilia Manasherov is good boy");
    std::cout<<"--Test 13--getMaxOccuringChar--Input: "<<testStr<<endl;
    c = getMaxOccuringChar(testStr);
    std::cout<<"-- Output: "<<c<<endl<<endl;

    //Test 14
    strcpy(testStr, "ilia Manasherov is good boy");
    std::cout<<"--Test 14--countWords--Input: "<<testStr<<endl;
    i = countWords(testStr);
    std::cout<<"-- Output: "<<i<<endl<<endl;

    cout<< "----------------- End String Algorithm Examples -----------------" << endl;
}

StringAlgoritms::~StringAlgoritms()
{
}

/* UTILITY FUNCTIONS */
/*Function to reverse any sequence starting with pointer begin and ending with pointer end  */
void StringAlgoritms::reverse(char *begin, char *end)
{
    char temp;
    while (begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

/* Function to swap values at two pointers */
void StringAlgoritms::swapChars (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Needed for qsort
int compare (const void * a, const void * b)
{
    return ( *(char*)a - *(char*)b );
}
/* UTILITY FUNCTIONS */

bool StringAlgoritms::Palindrome(int input)
{
    int reverse	=	0;
    int key		=	input;

    while (input != 0){
        reverse = reverse * 10 + input % 10;
        input = input / 10;
    }

    if(reverse==key)
    {
        cout<<key<<" is a Palindrome Number" << endl;
        return true;
    }
    else
    {
        cout<<key<<"is NOT a Palindrome Number"<< endl;
        return false;
    }
}

int StringAlgoritms::isSubset(char *a, char *b)
{
    int letterPresent[256] = { 0 };

    for(int i=0; a[i]!='\0'; i++)
    {
        letterPresent[a[i]]++;
    }

    for(int i=0; b[i]!='\0'; i++)
    {
        if(!letterPresent[b[i]])
        {
            return 1;
        }
    }
    return 0;
}

bool StringAlgoritms::isAnagramInPlace(char *a, char *b)
{
    int sizeofA = sizeof(a);
    int sizeofB = sizeof(b);

    if (sizeofA != sizeofB)
        return false;

    qsort(a, sizeofA, sizeof(char), compare );
    qsort(b, sizeofB, sizeof(char), compare );

    for (int i = 0; i < sizeofA; i++)
    {
        if ( a[i] != b[i] )
            return false;
    }
    return true;
}

bool StringAlgoritms::isAnagramWithTemp(char *a, char *b)
{
    int i =0;
    int tmp[NO_OF_CHARS] = { 0 };

    int sizeofA = sizeof(a);
    int sizeofB = sizeof(b);

    if (sizeofA != sizeofB) return false;

    for ( i =0 ; i < sizeofA; i++,a++,b++)
    {
        tmp[*a]++;
        tmp[*b]--;
    }

    for ( i =0 ; i < NO_OF_CHARS; i++)
        if (tmp[i]) return false;

        return true;
}

void StringAlgoritms::reverseWords(char *s)
{
    char *word_begin = NULL;
    char *temp = s; /* temp is for word boundary */

    /*STEP 1 of the above algorithm */
    while( *temp )
    {
    /*This condition is to make sure that the string start with
        valid character (not space) only*/
        if (( word_begin == NULL ) && (*temp != ' ') )
        {
            word_begin=temp;
        }
        if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0')))
        {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    } /* End of while */

    /*STEP 2 of the above algorithm */
    reverse(s, temp-1);
}

/* Function to print n equal parts of str*/
void StringAlgoritms::divideString(char *str, int n)
{
    int str_size = strlen(str);
    int i;
    int part_size;

    /*Check if string can be divided in n equal parts */
    if(str_size%n != 0)
    {
        printf("Invalid Input: String size is not divisible by n\n");
        return;
    }

    /* Calculate the size of parts to find the division points*/
    part_size = str_size/n;
    for(i = 0; i< str_size; i++)
    {
        if(i%part_size == 0)
            printf("\n"); /* newline separator for different parts */
        printf("%c", str[i]);
    }

    printf("\n");
}

/* Returns the Run Length Encoded string for the source string src */
char * StringAlgoritms::encode(char *src)
{
    int rLen;
    char count[MAX_RLEN];
    int len = strlen(src);

    /* If all characters in the source string are different,
    then size of destination string would be twice of input string.
    For example if the src is "abcd", then dest would be "a1b1c1d1"
    For other inputs, size would be less than twice.  */
    char *dest = (char *)malloc(sizeof(char)*(len*2 + 1));

    int i, j = 0, k;

    /* traverse the input string one by one */
    for(i = 0; i < len; i++)
    {
        /* Copy the first occurrence of the new character */
        dest[j++] = src[i];

        /* Count the number of occurrences of the new character */
        rLen = 1;
        while(i + 1 < len && src[i] == src[i+1])
        {
            rLen++;
            i++;
        }

        /* Store rLen in a character array count[] */
        sprintf(count, "%d", rLen);

        /* Copy the count[] to destination */
        for(k = 0; *(count+k); k++, j++)
        {
            dest[j] = count[k];
        }
    }

    /*terminate the destination string */
    dest[j] = '\0';
    return dest;
}

/* The function returns index of first non-repeating
character in a string. If all characters are repeating
then returns -1 */
int StringAlgoritms::firstNonRepeating(char *str)
{
    int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
    int i;
    for (i = 0; *(str+i);  i++)
        count[*(str+i)]++;
    int index = -1;

    for (i = 0; *(str+i);  i++)
    {
        if (count[*(str+i)] == 1)
        {
            index = i;
            break;
        }
    }

    free(count); // To avoid memory leak
    return index;
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void StringAlgoritms::permute(char *pString, int iStart, int iEnd)
{

    if (iStart == iEnd)
    {
        printf("%s\n", pString);
        return;
    }

    for (auto j = iStart; j <= iEnd; j++)
    {
        swapChars(pString + iStart, pString + j);
        permute(pString, iStart + 1, iEnd);
        swapChars(pString + iStart, pString + j); //backtrack
    }
}

/* Function to print reverse of the passed string */
void StringAlgoritms::reverseRecursion(char *str)
{
    if(*str)
    {
        reverseRecursion(str+1);
        printf("%c", *str);
    }
}

/* Function checks if passed strings (str1 and str2) are rotations of each other */
int StringAlgoritms::areRotations(char *str1, char *str2)
{
    int size1   = strlen(str1);
    int size2   = strlen(str2);
    char *temp;
    void *ptr;

    /* Check if sizes of two strings are same */
    if (size1 != size2)
        return 0;

    /* Create a temp string with value str1.str1 */
    temp   = (char *)malloc(sizeof(char)*(size1*2 + 1));
    temp[0] = '\0';
    strcat(temp, str1);
    strcat(temp, str1);

    /* Now check if str2 is a substring of temp */
    ptr = strstr(temp, str2);

    free(temp); // Free dynamically allocated memory

                /* strstr returns NULL if the second string is NOT a
    substring of first string */
    if (ptr != NULL)
        return 1;
    else
        return 0;
}

/* removeDirtyChars takes two string as arguments: First
string (str)  is the one from where function removes dirty
characters. Second  string is the string which contain all
dirty characters which need to be removed  from first string */
char * StringAlgoritms::removeDirtyChars(char *str, char *mask_str)
{
    int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
    int i;
    for (i = 0; *(str+i);  i++)
        count[*(str+i)] = 0;

    int ip_ind  = 0, res_ind = 0;
    char temp;
    while(*(str + ip_ind))
    {
        temp = *(str + ip_ind);
        if(count[temp] == 0)
        {
            *(str + res_ind) = *(str + ip_ind);
            res_ind++;
        }
        ip_ind++;
    }

    /* After above step string is ngring.
    Removing extra "iittg" after string*/
    *(str+res_ind) = '\0';

    return str;
}

/* Print duplicates present in the passed string */
void StringAlgoritms::printDups(char *str)
{
    // Create an array of size 256 and fill count of every character in it
    int count[NO_OF_CHARS] = {0};

    for (int i = 0; *(str+i);  i++)
        count[*(str+i)]++;

    // Print characters having count more than 0
    for (int i = 0; i < NO_OF_CHARS; i++)
        if(count[i] > 1)
            printf("%c,  count = %d \n", i,  count[i]);
}

/* Function to remove spaces Using STRINGSTREAM */
#include  <sstream>
string removeSpaces(string str)
{
    stringstream ss;
    string sWord;    

    ss << str;				/* Storing the whole string into string stream */    
    str = "";				/* Making the string empty */    
    while (!ss.eof())		/* Running loop till end of stream */
    {        
        ss >> sWord;		/* extracting word by word from stream */
        str = str + sWord;	/* concatenating in the string to be returned*/
    }
    return str;
}

/* Returns the maximum occurring character in the input string */
char StringAlgoritms::getMaxOccuringChar(char *str)
{
    int count[NO_OF_CHARS];
    int i;
    int max_index = 0;

    for (i = 0; *(str+i);  i++)
        count[*(str+i)]++;

    for(i = 1; i < NO_OF_CHARS; i++)
        if(count[i] > count[max_index])
            max_index = i;
        
    return max_index;
}

/* returns number of words in str */
unsigned StringAlgoritms::countWords(char *str)
{
    int state = OUT;
    unsigned wc = 0;  // word count

    // Scan all characters one by one
    while (*str)
    {
        // If next character is a separator, set the state as OUT
        if (*str == ' ' || *str == '\n' || *str == '\t')
            state = OUT;

        // If next character is not a word separator and state is OUT,
        // then set the state as IN and increment word count
        else if (state == OUT)
        {
            state = IN;
            ++wc;
        }

        // Move to next character
        ++str;
    }

    return wc;
}


/* Function removes duplicate characters from the string
This function work in-place and fills null characters
in the extra space left */
char * StringAlgoritms::removeDups(char *str)
{
	bool bin_hash[NO_OF_CHARS] = { 0 };
	int iFrom = 0, iTo = 0;
	char temp;

	/* In place removal of duplicate characters*/
	while (*(str + iFrom))
	{
		temp = *(str + iFrom);
		if (bin_hash[temp] == 0)
		{
			bin_hash[temp] = 1;
			*(str + iTo) = *(str + iFrom);
			iTo++;
		}
		iFrom++;
	}

	/* After above step string is stringiittg.
	Removing extra iittg after string*/
	*(str + iTo) = '\0';

	return str;
}

//	a			a
//	abba		abba
//	abbba		aa
//	aaabb		bb
//	abbb		a	
//	aabbbac		c
//	aabbcccbaac	c
//	caabbbaac	cc
void ccrush(char* str)
{
    int iFrom = 0 , iTo = 0;
	int iPrev = -1;

    int iCount = 1;

	while (*(str + iFrom))
	{
	

		if (*(str + iTo) == *(str + iFrom))
		{
			iCount++;
		}
		else {
			if (iCount >= 3)
			{
				*(str + iTo) = *(str + iFrom);
			}
			else 
			{
				iTo++;
			}
		}

		iFrom++;
    }
    *(str + iTo) = '\0';
}