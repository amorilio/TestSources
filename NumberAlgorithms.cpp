// Prime.cpp: implementation of the Prime class.
//
//////////////////////////////////////////////////////////////////////

#include "NumberAlgorithms.h"

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <conio.h>
#include <string>
#include "math.h"
#include <stack>

//
// Quick and good summary of sorting and data structure manipulation time complexities
// http://bigocheatsheet.com/
//


//
//	Number - Digits query from Geeksforgeeks
//
//http://www.geeksforgeeks.org/tag/number-digits/
//
//

//http://www.geeksforgeeks.org/convert-base-decimal-vice-versa/

// Get next pointer - current pointer , convert both to (char*) and subtract
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NumberAlgorithms::NumberAlgorithms()
{
    printf("\nGCD(%2d,%2d) = [%d]", 6, 4, gcd(6, 4));
    printf("\nGCD(%2d,%2d) = [%d]", 4, 6, gcd(4, 6));
    printf("\nGCD(%2d,%2d) = [%d]", 3, 17, gcd(3, 17));
    printf("\nGCD(%2d,%2d) = [%d]", 17, 3, gcd(17, 3));
    printf("\nGCD(%2d,%2d) = [%d]", 1, 6, gcd(1, 6));
    printf("\nGCD(%2d,%2d) = [%d]", 10, 1, gcd(10, 1));
    printf("\nGCD(%2d,%2d) = [%d]", 10, 6, gcd(10, 6));

    printf("\nGCD(%2d,%2d) = [%d]", 6, 4, gcd_recurse(6, 4));
    printf("\nGCD(%2d,%2d) = [%d]", 4, 6, gcd_recurse(4, 6));
    printf("\nGCD(%2d,%2d) = [%d]", 3, 17, gcd_recurse(3, 17));
    printf("\nGCD(%2d,%2d) = [%d]", 17, 3, gcd_recurse(17, 3));
    printf("\nGCD(%2d,%2d) = [%d]", 1, 6, gcd_recurse(1, 6));
    printf("\nGCD(%2d,%2d) = [%d]", 10, 1, gcd_recurse(10, 1));
    printf("\nGCD(%2d,%2d) = [%d]", 10, 6, gcd_recurse(10, 6));

    int array[6] = { 1, 3, 3, 5, 5, 5 };
    removeDuplicates(array, 6);
    CheckIfNumberPrime();
    GeneratePrimeNumbers(100);

    static const unsigned int array_size = 10;
    int iArray[array_size];

    cout << "---> Start Insertion Sort Test" << endl;
    createArray(iArray, array_size);
    printArray(iArray, array_size);
    SortInsertion(iArray, array_size);
    printArray(iArray, array_size);
    cout << "---> End Insertion Sort Test" << endl;

    cout << "---> Start Merge Sort Test" << endl;
    createArray(iArray, array_size);
    printArray(iArray, array_size);
    SortMerge(iArray, 0, array_size - 1);
    printArray(iArray, array_size);
    cout << "---> End Merge Sort Test" << endl;

    cout << "---> Start Heap Sort Test" << endl;
    createArray(iArray, array_size);
    printArray(iArray, array_size);
    SortHeap(iArray, array_size);
    printArray(iArray, array_size);
    cout << "---> End Heap Sort Test" << endl;

    cout << "---> reverseNumber" << endl;
    reverseNumber(321);
    reverseNumber(-456);
    reverseNumber(1234567899);

    cout << "---> convertToBase" << endl;
    convertToBase(12, 2);
    convertToBase(10, 16);
    convertToBase(124, 10);

    cout << "---> convertBinarytoDecimal" << endl;
    convertBinarytoDecimal(101);
    convertBinarytoDecimal(1111);
    convertBinarytoDecimal(10001);

    cout << "---> smallestNumber " << endl;
    smallestNumber(8);		// -> output 8
    smallestNumber(36);		// -> output 49  4 * 9
    smallestNumber(100);	// -> output 455 4 * 5 * 5
    smallestNumber(121);	// -> output -1  11 * 11 - are not digits.
}

//
//	Utilities
//
void NumberAlgorithms::swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }

void NumberAlgorithms::swap(int x, int y)
{

    // Code to swap 'x' (1010) and 'y' (0101)
    x = x ^ y;  // x now becomes 15 (1111)
    y = x ^ y;  // y becomes 10 (1010)
    x = x ^ y;  // x becomes 5 (0101)
}

void NumberAlgorithms::swap1(int var1, int var2)
{
    int swap;

    cout << " Values Before swapping Using Temp:  " << endl;
    cout << "First Integer =" << var1 << endl;
    cout << "Second Integer =" << var2 << endl;
    swap = var1;
    var1 = var2;
    var2 = swap;
    cout << " Values After swapping:  " << endl;
    cout << "First Integer =" << var1 << endl;
    cout << "Second Integer =" << var2 << endl;
}

void NumberAlgorithms::swap2(int var1, int var2)
{
    cout << " Values Before swapping Without Using Temp:  " << endl;
    cout << "First Integer =" << var1 << endl;
    cout << "Second Integer =" << var2 << endl;

    var1 = var1 + var2;
    var2 = var1 - var2;
    var1 = var1 - var2;

    cout << " Values After swapping:  " << endl;
    cout << "First Integer =" << var1 << endl;
    cout << "Second Integer =" << var2 << endl;
}

void NumberAlgorithms::createArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;
}

void NumberAlgorithms::printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


//
//	Number / Digit algorithms
//
bool NumberAlgorithms::CheckIfNumberPrime()
{
    int number,count=0;
    cout<<"ENTER NUMBER TO CHECK IT IS PRIME OR NOT "<<endl;
    cin>>number;
    for(int a=1;a<=number;a++)
    {
        // If number can be divided by any number smaller then it without remainder
        // Increase count.
        if(number%a==0)
        {
            count++;
        }
    }

    // if count is 2 this means that number can be divided by 1 and itself, so it's prime
    if(count==2)
    {
        cout<<"PRIME NUMBER "<<endl;
        return true;
    }
    else
    {
        cout<<"NOT A PRIME NUMBER "<<endl;
        return false;
    }
}

void NumberAlgorithms::GeneratePrimeNumbers(int n)
{

    // Create array of ones p. Starting from 2 pass over all numbers until n and check that p[i] is still 1
    // if yes declare the number as prime and declare all it's parents as non prime in p

    int nrPrime = 0;
    int prime[78498]; // 78498 is the number of prime numbers smaller than 1 000 000.
    char p[1000];

    memset(p, 1, sizeof(char) * (n + 1));

    p[1] = 0;

    int i = 2;
    for (; i <= n; ++i)
    {
        if (p[i]) {
            prime[nrPrime] = i;
            ++nrPrime;
            int j = i * 2;
            while (j <= n) {
                p[j] = 0;
                j += i;
            }
        }
    }

    cout<<"Prime numbers from : 0 to "<<n<<endl;
    for (i=0; i<nrPrime; i++)
        cout<<prime[i] << " ";
    cout<<endl;
}

int NumberAlgorithms::removeDuplicates(int a[], int array_size)
{
    int i, j;
    j = 0;

    // Print old array...
    printf("\n\nOLD : ");
    for(i = 0; i < array_size; i++)
    {
        printf("[%d] ", a[i]);
    }

    // Remove the duplicates ...
    for (i = 1; i < array_size; i++)
    {
        if (a[i] != a[j])
        {
            j++;
            a[j] = a[i]; // Move it to the front
        }
    }

    // The new array size..
    array_size = (j + 1);

    // Print new array...
    printf("\n\nNEW : ");
    for(i = 0; i < array_size; i++)
    {
        printf("[%d] ", a[i]);
    }
    printf("\n\n");

    // Return the new size...
    return(j + 1);
}

int NumberAlgorithms::gcd(int a, int b)
{
    int temp;
    while(b)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    return(a);
}

int NumberAlgorithms::gcd_recurse(int a, int b)
{
    int temp;
    temp = a % b;
    if (temp == 0)
    {
        return(b);
    }
    else
    {
        return(gcd_recurse(b, temp));
    }
}

void NumberAlgorithms::towers_of_hanio(int n, char from, char to, char temp)
{
    if(n > 0)
    {
        towers_of_hanio(n-1, from, temp, to);
        printf("\nMove disk %d from %c to %c\n", n, from, to);
        towers_of_hanio(n-1, temp, to, from);
    }
}

void NumberAlgorithms::check_endian()
{
    int num = 1;
    if(*(char *)&num == 1)
    {
        printf("\nLittle-Endian\n");
    }
    else
    {
        printf("Big-Endian\n");
    }
}

int NumberAlgorithms::fibonacci(int n)
{
    int* f = new int[n+1];
    f[1] = f[2] = 1;

    printf("\nf[1] = %d", f[1]);
    printf("\nf[2] = %d", f[2]);

    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i-1] + f[i-2];
        printf("\nf[%d] = [%d]",i,f[i]);
    }
    return f[n];
}

int NumberAlgorithms::reverseNumber(int input)
{
    std::cout << "Input : " << input;

    long long output = 0;	// Need long long here becasuse on 64 bit Win 7 size of long and int are same.

    while (input)
    {
        output = output * 10 + input % 10;
        input /= 10;
    }

    //
    //	Important to check integer overflow
    //
    if (output < INT_MIN || output > INT_MAX) output = 0;

    std::cout << " ---> Output : " << output << std::endl;
    return output;
}

string NumberAlgorithms::convertToBase(int input, int base)
{
    std::cout << "Input : " << input << " To Base : " << base;

    string bases = "0123456789ABCDEF";
    string output = "";

    while (input)
    {
        output = bases[input%base] + output;
        input /= base;
    }

    std::cout << " ---> Output : " << output.c_str() << std::endl;
    return output;
}

int NumberAlgorithms::convertBinarytoDecimal(long long binary)
{
    std::cout << "Input : " << binary;
    int decimal = 0;
    int index = 0;
    while (binary)
    {
        decimal += (binary % 10) * (int)pow(2, index++);
        binary /= 10;
    }
    std::cout << " ---> Output : " << decimal << std::endl;
    return decimal;
}

char* NumberAlgorithms::itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    // Handle 0 explicitely, otherwise empty string is printed for 0 
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    // Append string terminator
    str[i] = '\0';

    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end)
    {
        swap(*(str + start), *(str + end));
        start++;
        end--;
    }

    return str;
}

long long int NumberAlgorithms::smallestNumber(int n)
{
    //
    // function to find smallest number k such that the product of digits of k is equal to n Input : 100 -> Output: 455, Input: 26 -> Output : -1
    //

    std::cout << "Input : " << n;

    // if 'n' is a single digit number, then it is the required number
    if (n >= 0 && n <= 9)
    {
        std::cout << " ---> Output : " << n << std::endl;
        return n;
    }

    // stack the store the the digits
    stack<int> digits;

    // repeatedly divide 'n' by the numbers from 9 to 2 until all the numbers are used or 'n' > 1
    for (int i = 9; i >= 2 && n > 1; i--)
    {
        while (n % i == 0)
        {
            // save the digit 'i' that divides 'n' onto the stack
            digits.push(i);
            n = n / i;
        }
    }

    long long int k = 0;
    if (n != 1)
    {
        //no number 'k' can be formed
        k = -1;
    }
    else
    {
        // pop digits from the stack 'digits' and add them to 'k'
        while (!digits.empty())
        {
            k = k * 10 + digits.top();
            digits.pop();
        }
    }

    std::cout << " ---> Output : " << k << std::endl;
    // required smallest number
    return k;
}

//
//	Array Sorts
//
void NumberAlgorithms::SortInsertion(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int val = array[i];
        int j = i - 1;
        while (j >= 0, array[j] > val)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = val;
    }
}

void NumberAlgorithms::SortSelection(int array[], int size)
{
    int pos_min;
    for (int i = 0; i < size - 1; i++)
    {
        pos_min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[pos_min])
                pos_min = j;
        }
        if (pos_min != i)
        {
            swap1(array[i], array[pos_min]);
        }
    }
}

void NumberAlgorithms::SortQuick(int array[], int iStart, int iEnd)
{
    int pivot = array[(iStart + iEnd) / 2];
    int i = iStart;
    int j = iEnd;

    while (i < j)
    {
        while (array[i]  < pivot) i++;
        while (array[j] >= pivot) j--;

        swap(array[i], array[j]);
        i++;
        j--;
    }
    if (iStart != i)
        SortQuick(array, iStart, i);

    if (iEnd != j)
        SortQuick(array, j, iEnd);
}

void NumberAlgorithms::Merge(int array[], int leftIdx, int middleIdx, int rightIdx)
{
    int i, j, k;

    int nLeft = middleIdx - leftIdx + 1;
    int nRight = rightIdx - middleIdx;

    int * arrayLeft = new int[nLeft];
    int * arrayRight = new int[nRight];

    for (i = 0; i < nLeft; i++)
        arrayLeft[i] = array[leftIdx + i];
    for (j = 0; j <= nRight; j++)
        arrayRight[j] = array[middleIdx + 1 + j];

    i = 0;
    j = 0;
    k = leftIdx;
    while (i < nLeft && j < nRight)
    {
        if (arrayLeft[i] < arrayRight[j])
            array[k++] = arrayLeft[i++];
        else
            array[k++] = arrayRight[j++];
    }
    while (i < nLeft)
        array[k++] = arrayLeft[i++];

    while (j < nRight)
        array[k++] = arrayRight[j++];

    //delete [] arrayLeft;
    //delete [] arrayRight;
}
void NumberAlgorithms::SortMerge(int array[], int leftIdx, int rightIdx)
{
    if (leftIdx < rightIdx)
    {
        int middleIdx = ((leftIdx + rightIdx - 1) / 2);
        SortMerge(array, leftIdx, middleIdx);
        SortMerge(array, middleIdx + 1, rightIdx);
        Merge(array, leftIdx, middleIdx, rightIdx);
    }
}

void NumberAlgorithms::Heapify(int array[], int size, int idx)
{
    // The main function to heapify a Max Heap. The function assumes that everything under given root (element at index idx) is already heapified

    int largest = idx;  // Initialize largest as root
    int left = (idx << 1) + 1;		// left	 = 2*idx + 1
    int right = (idx + 1) << 1;		// right = 2*idx + 2

    // See if left child of root exists and is greater than root
    if (left < size && array[left] > array[largest])
        largest = left;

    // See if right child of root exists and is greater than the largest so far
    if (right < size && array[right] > array[largest])
        largest = right;

    // Change root, if needed
    if (largest != idx)
    {
        swap(&array[largest], &array[idx]);
        Heapify(array, size, largest);
    }
}
void NumberAlgorithms::createAndBuildHeap(int *array, int size)
{
    // A utility function to create a max heap of given capacity
    int i;

    // Start from bottommost and rightmost internal mode and heapify all
    // internal modes in bottom up way
    for (i = (size - 2) / 2; i >= 0; --i)
        Heapify(array, size, i);
}
void NumberAlgorithms::SortHeap(int* array, int size)
{
    // The main function to sort an array of given size
    // Build a heap from the input data.
    createAndBuildHeap(array, size);

    // Repeat following steps while heap size is greater than 1. The last
    // element in max heap will be the minimum element
    while (size > 1)
    {
        // The largest item in Heap is stored at the root. Replace it with the
        // last item of the heap followed by reducing the size of heap by 1.
        swap(&array[0], &array[size - 1]);
        --size;  // Reduce heap size

        // Finally, heapify the root of tree.
        Heapify(array, size, 0);
    }
}
