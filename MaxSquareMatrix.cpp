#include "MaxSquareMatrix.h"

#include<stdio.h>

MaxSquareMatrix::MaxSquareMatrix(void)
{
}

MaxSquareMatrix::~MaxSquareMatrix(void)
{
}

/*
http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

1) Construct a sum matrix S[R][C] for the given M[R][C].
	a)	Copy first row and first columns as it is from M[][] to S[][]
	b)	For other entries, use following expressions to construct S[][]
		If M[i][j] is 1 then
			S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
		Else If M[i][j] is 0
			S[i][j] = 0
2) Find the maximum entry in S[R][C]
3) Using the value and coordinates of maximum entry in S[i], print sub-matrix of M[][]
*/

void MaxSquareMatrix::printMaxSubSquare(bool M[R][C])
{
	int i, j;
	int S[R][C];
	int max_of_s, max_i, max_j;

	/* Set first column of S[][]*/
	for (i = 0; i < R; i++)
		S[i][0] = M[i][0];

	/* Set first row of S[][]*/
	for (j = 0; j < C; j++)
		S[0][j] = M[0][j];

	/* Construct other entries of S[][]*/
	for (i = 1; i < R; i++)
	{
		for (j = 1; j < C; j++)
		{
			if (M[i][j] == 1)
				S[i][j] = minTestMaxSquareMatrix(S[i][j - 1], S[i - 1][j], S[i - 1][j - 1]) + 1;
			else
				S[i][j] = 0;
		}
	}

	/* Find the maximum entry, and indexes of maximum entry S[][] */
	max_of_s = S[0][0];
	max_i = 0;
	max_j = 0;

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (max_of_s < S[i][j])
			{
				max_of_s = S[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	printf("\n Maximum size sub-matrix is: \n");
	for (i = max_i; i > max_i - max_of_s; i--)
	{
		for (j = max_j; j > max_j - max_of_s; j--)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}

/* UTILITY FUNCTIONS */
/* Function to get minimum of three values */
int MaxSquareMatrix::minTestMaxSquareMatrix(int a, int b, int c)
{
	int m = a;
	if (m > b)    m = b;
	if (m > c)    m = c;
	return m;
}

/* Driver function to test above functions */
void TestMaxSquareMatrix()
{
	bool M[R][C] = {{ 0, 1, 1, 0, 1 },
					{ 1, 1, 0, 1, 0 },
					{ 0, 1, 1, 1, 0 },
					{ 1, 1, 1, 1, 0 },
					{ 1, 1, 1, 1, 1 },
					{ 0, 0, 0, 0, 0 } };
	//bool M[R][C] =  {{0, 1, 1, 0, 1},
	//                 {1, 1, 0, 1, 0},
	//                 {0, 1, 1, 1, 0},
	//                 {1, 1, 2, 2, 0},
	//                 {1, 2, 2, 3, 1},
	//                 {0, 0, 0, 0, 0}};

	MaxSquareMatrix sqm;

	sqm.printMaxSubSquare(M);

	getchar();
}

void MaxSquareMatrix::displayMatrix(int const *p, int r, int c)
{
	int row, col;
	printf("\n\n");

	for (row = 0; row < r; row++)

	{
		for (col = 0; col < c; col++)
		{
			printf("%d\t", *(p + row * c + col));
		}
		printf("\n");
	}

	printf("\n\n");
}

void MaxSquareMatrix::rotate(int *pSource, int *pDestination, int row, int col)
{
	int tempRow, tempCol;
	for (tempRow = 0; tempRow < row; tempRow++)
	{
		for (tempCol = 0; tempCol < col; tempCol++)
		{
			int iDShift = tempCol * row + (row - tempRow - 1);
			int iSShift = tempRow * col + tempCol;

			*(pDestination + iDShift) = *(pSource + iSShift);
		}
	}
}
void TestrotateMatrix()
{
	// declarations
	int image[3][4] = { { 1, 2, 3, 4 },
						{ 5, 6, 7, 8 },
						{ 9, 10, 11, 12 } };
	int *pSource;
	int *pDestination;
	int m = 3;
	int n = 4;

	// setting initial values and memory allocation
	pSource = (int *)image;
	pDestination = new int(m*n);

	MaxSquareMatrix sqm;

	// process each buffer
	sqm.displayMatrix(pSource, m, n);

	sqm.rotate(pSource, pDestination, m, n);

	sqm.displayMatrix(pDestination, n, m);

	delete pDestination;

	getchar();
	return;
}