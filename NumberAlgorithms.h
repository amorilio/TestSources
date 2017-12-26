// Prime.h: interface for the Prime class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRIME_H__35938C20_E202_479B_8F4D_4E6DFA74472D__INCLUDED_)
#define AFX_PRIME_H__35938C20_E202_479B_8F4D_4E6DFA74472D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
class NumberAlgorithms
{
public:
    NumberAlgorithms();
    virtual ~NumberAlgorithms() = default;

    //
    //	Utilities
    //
    void createArray(int arr[], int n);
    void printArray(int arr[], int n);
    void swap(int* a, int* b); 
    void swap(int x, int y);
    void swap1(int var1, int var2);
    void swap2(int var1, int var2);

    //
    //	Number / Digit algorithms
    //
    bool CheckIfNumberPrime();

    void GeneratePrimeNumbers(int n);

    int removeDuplicates(int a[], int array_size);

    int gcd(int a, int b);

    int gcd_recurse(int a, int b);

    void towers_of_hanio(int n, char from, char to, char temp);

    void check_endian();

    int fibonacci(int n);

    int reverseNumber(int input);

    std::string convertToBase(int input, int base);

    int convertBinarytoDecimal(long long binary);

    char* itoa(int num, char* str, int base);

    long long int smallestNumber(int n);

    //
    //	Sorts
    //
    void SortInsertion(int array[], int size);

    void SortSelection(int array[], int size);

    void SortQuick(int array[], int iStart, int iEnd);

    void Merge(int array[], int leftIdx, int middleIdx, int rightIdx);
    void SortMerge(int array[], int leftIdx, int rightIdx);

    void Heapify(int array[], int size, int idx);
    void createAndBuildHeap(int *array, int size);
    void SortHeap(int* array, int size);

};

#endif // !defined(AFX_PRIME_H__35938C20_E202_479B_8F4D_4E6DFA74472D__INCLUDED_)
