// BitMagic.h: interface for the BitMagic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAGIC_H__6F574A23_EF71_4BF1_A4FA_BB9DE47A8886__INCLUDED_)
#define AFX_BITMAGIC_H__6F574A23_EF71_4BF1_A4FA_BB9DE47A8886__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <bitset>

// Maximum allowed query value
#define MAXSUM 10000

class BitMagic
{
public:
    BitMagic();
    virtual ~BitMagic();

    std::string getBitRepresentation( int x);
    bool isKthBitSet( int x,  int k);
    bool isPalindrome( int x);
    int  swapNibbles(int x);

    int turnOffK(int n, int k);
    int turnOnK(int n, int k);

    bool isPowerOfTwo(unsigned n);
    int findPosition(unsigned n);

    unsigned int swapBits(unsigned int x);


	void processQueries(int query[], int nq, std::bitset<MAXSUM> bit);
	void preprocess(std::bitset<MAXSUM> &bit, int arr[], int n);
};

#endif // !defined(AFX_BITMAGIC_H__6F574A23_EF71_4BF1_A4FA_BB9DE47A8886__INCLUDED_)
