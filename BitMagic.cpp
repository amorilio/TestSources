// BitMagic.cpp: implementation of the BitMagic class.
//
//////////////////////////////////////////////////////////////////////

#include "BitMagic.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;


// 4 Makros for bitwise operations.
#define SET_BIT(Number, bit_position)                   Number |= (1<< bit_position)
#define CLEAR_BIT(Number, bit_position)                 Number &= ~(1<< bit_position)
#define TOGGLE_BIT(Number, bit_position)                Number ^= (1<< bit_position)
#define CHECK_BIT_IS_SET_OR_NOT(Number, bit_position)   Number & (1<< bit_position)


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BitMagic::BitMagic()
{

	cout << "------------- BitMagic :: Some Plays with Masks ------------- " << endl;
	printf("%x\n", 0xDEADBEEF);
	printf("%x\n", (0xDEADBEEF >> 0 & 0xFF));
	printf("%x\n", (0xDEADBEEF >> 8 & 0xFF));
	printf("%x\n", (0xDEADBEEF >> 16 & 0xFF));
	printf("%x\n", (0xDEADBEEF >> 24 & 0xFF));
	printf("%x\n", 0xDEADBEEF);
	printf("%x\n", (0xDEADBEEF >> 0 & 0xFFFF));
	printf("%x\n", (0xDEADBEEF >> 16 & 0xFFFF));

	cout << "------------- BitMagic :: getBitRepresentation ------------- " << endl;
	for (int i = 0; i <= 16; i++)
	{
		cout << std::left << setfill(' ') << setw(5) << i << " ---> ";
		cout << getBitRepresentation(i) << endl;
	}

	unsigned int x = (1 << 15) + (1 << 16);
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << endl;
	x = (1 << 31) + 1;
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << endl;
	x = (1 << 31) + (1 << 16) + (1 << 8) + (1 << 27) + (1 << 3);
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << endl;

	cout << "------------- BitMagic :: operations test ------------- " << endl;
	int a1 = 41;
	int a2 = 71;
	cout << std::left << setfill(' ') << setw(32) << a1 << " " << getBitRepresentation(a1) << endl;
	cout << std::left << setfill(' ') << setw(32) << a2 << " " << getBitRepresentation(a2) << endl;
	cout << std::left << setfill(' ') << setw(32) << (a1 | a2) << " | " << getBitRepresentation(a1 | a2) << endl;
	cout << std::left << setfill(' ') << setw(32) << (a1 & a2) << " & " << getBitRepresentation(a1 & a2) << endl;
	cout << std::left << setfill(' ') << setw(32) << (a1 ^ a2) << " ^ " << getBitRepresentation(a1 ^ a2) << endl;

	cout << "------------- BitMagic :: isPalindrome ------------- " << endl;
	x = 0x0F;
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << " " << isPalindrome(x) << endl;
	x = 0xF0;
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << " " << isPalindrome(x) << endl;

	cout << "------------- BitMagic :: swapNibbles ------------- " << endl;
	x = 100;
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << endl;
	x = swapNibbles(x);
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << endl;

	cout << "------------- BitMagic :: turnOff/turnOn ------------- " << endl;
	x = 0xFFFF;
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << endl;
	x = turnOffK(x, 3);
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << endl;

	x = 0;
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << endl;
	x = turnOnK(x, 3);
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << endl;

	cout << "------------- BitMagic :: findPosition------------- " << endl;
	x = 16;
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << " " << findPosition(x) << endl;

	cout << "------------- BitMagic :: swapBits ------------- " << endl;
	x = 123;
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << endl;
	x = swapBits(x);
	cout << std::left << setfill(' ') << setw(32) << x << " " << getBitRepresentation(x) << endl;

	cout << "------------- BitMagic :: Sum Query ------------- " << endl;
	int arr[] = { 3, 1, 5 };
	int query[] = { 8, 7 };

	int n = sizeof(arr) / sizeof(arr[0]);
	int nq = sizeof(query) / sizeof(query[0]);

	// a vector of MAXSUM number of bits
	bitset<MAXSUM> bit;

	preprocess(bit, arr, n);
	processQueries(query, nq, bit);
}

BitMagic::~BitMagic()
{
}

string BitMagic::getBitRepresentation(int x)
{
	stringstream ss;
	int r = sizeof(int)* 8;		// Initialize right position
	int iSpace = 4;

	while (r)
	{
		int bit = ((x & (1 << (r - 1))) != 0);
		ss << bit;
		if (!--iSpace)
		{
			iSpace = 4;
			ss << " ";
		}
		r--;
	}
	return ss.str();
}

//If we subtract a power of 2 numbers by 1 then all unset bits after the only set bit become set; and the set bit become unset.
//For example for 4 (100) we get following after subtracting 1, 3 (011).
//So, if a number n is a power of 2 then bitwise & of n and n-1 will be zero. We can say n is a power of 2 or not based on value of n&(n-1).
bool BitMagic::isPowerOfTwo(unsigned n)
{
	return ((n & (n - 1)) == 0);
}

// Returns position of the only set bit in 'n'
int BitMagic::findPosition(unsigned n)
{
	if (!isPowerOfTwo(n))        return -1;
	unsigned i = 1, pos = 1;
	// Iterate through bits of n till we find a set bit i&n will be non-zero only when 'i' and 'n' have a set bit at same position
	while (!(i & n))
	{
		i = i << 1;
		++pos;
	}
	return pos;
}

unsigned int BitMagic::swapBits(unsigned int x)
{
	// Get all even bits of x
	unsigned int even_bits = x & 0xAAAAAAAA;

	// Get all odd bits of x
	unsigned int odd_bits = x & 0x55555555;


	cout << std::left << setfill(' ') << setw(32) << "Even Bits" << " " << getBitRepresentation(0xAAAAAAAA) << endl;
	cout << std::left << setfill(' ') << setw(32) << "x & Even Bits" << " " << getBitRepresentation(even_bits) << endl;
	cout << std::left << setfill(' ') << setw(32) << "Odd Bits" << " " << getBitRepresentation(0x55555555) << endl;
	cout << std::left << setfill(' ') << setw(32) << "x & Odd Bits" << " " << getBitRepresentation(odd_bits) << endl;

	even_bits >>= 1;  // Right shift even bits
	cout << std::left << setfill(' ') << setw(32) << ">>= 1 Even Bits" << " " << getBitRepresentation(even_bits) << endl;
	odd_bits <<= 1;   // Left shift odd bits
	cout << std::left << setfill(' ') << setw(32) << "<<= 1 Odd Bits" << " " << getBitRepresentation(odd_bits) << endl;

	return (even_bits | odd_bits); // Combine even and odd bits
}
//Explanation:
//100 is 01100100 in binary. The operation can be split mainly in two parts
//
//1) The expression “x & 0x0F” gives us last 4 bits of x. For x = 100, the result is 00000100. Using bitwise ‘<<' operator,
//  we shift the last four bits to the left 4 times and make the new last four bits as 0. The result after shift is 01000000.
//2) The expression “x & 0xF0” gives us first four bits of x. For x = 100, the result is 01100000.
//  Using bitwise ‘>>’ operator, we shift the digit to the right 4 times and make the first four bits as 0. The result after shift is 00000110.
//3) At the end we use the bitwise OR ‘|’ operation of the two expressions explained above.
//  The OR operator places first nibble to the end and last nibble to first. For x = 100, the value of (01000000) OR (00000110) gives the result 01000110 which is equal to 70 in decimal.
int BitMagic::swapNibbles(int x)
{
	return ((x & 0x0F) << 4 | (x & 0xF0) >> 4);
}

// This function returns true if k'th bit in x is set (or 1).
// For example if x (0010) is 2 and k is 2, then it returns true
bool BitMagic::isKthBitSet(int x, int k)
{
	return (x & (1 << (k - 1))) ? true : false;
}

// This function returns true if binary representation of x is
// palindrome. For example (1000...001) is palindrome
bool BitMagic::isPalindrome(int x)
{
	int l = 1; // Initialize left position
	int r = sizeof(int)* 8; // initialize right position

	// One by one compare bits
	while (l < r)
	{
		if (isKthBitSet(x, l) != isKthBitSet(x, r))
			return false;
		l++;     r--;
	}
	return true;
}
// Returns a number that has all bits same as n except the k'th bit which is made 0
int BitMagic::turnOffK(int n, int k)
{
	// k must be greater than 0
	if (k <= 0) return n;

	// Do & of n with a number with all set bits except the k'th bit
	// Using expression "~(1 << (k - 1))“, we get a number which has all bits set, except the k’th bit ~ sign switches 1 to 0 and visa versa
	return (n & ~(1 << (k - 1)));
}
// Returns a number that has all bits same as n except the k'th bit which is made 1
int BitMagic::turnOnK(int n, int k)
{
	// k must be greater than 0
	if (k <= 0) return n;

	// Do & of n with a number with all set bits except
	// the k'th bit
	return (n | (1 << (k - 1)));
}

//
// C++ program to answer subset sum queries using bitset
// http://www.geeksforgeeks.org/subset-sum-queries-using-bitset/
//

using namespace std;
// function to check whether a subset sum equal to n exists in the array or not.
void BitMagic::processQueries(int query[], int nq, bitset<MAXSUM> bit)
{
	// One by one process subset sum queries
	for (int i = 0; i < nq; i++)
	{
		int x = query[i];

		// If x is beyond size of bit[]
		if (x >= MAXSUM)
		{
			cout << "NA, ";
			continue;
		}

		// Else if x is a subset sum, then x'th bit must be set
		bit[x] ? cout << "Yes, " : cout << "No, ";
	}
}

// function to store all the subset sums in bit vector
void BitMagic::preprocess(bitset<MAXSUM> &bit, int arr[], int n)
{
	// set all the bits to 0
	bit.reset();

	// set the 0th bit because subset sum of 0 exists
	bit[0] = 1;

	// Process all array elements one by one
	for (int i = 0; i < n; ++i)
	{
		// Do OR of following two
		// 1) All previous sums. We keep previous value of bit.
		// 2) arr[i] added to every previous sum. We move all previous indexes arr[i] ahead.
		bit |= (bit << arr[i]);
	}
}