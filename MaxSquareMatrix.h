#pragma once

#define R 6
#define C 5

class MaxSquareMatrix
{
public:
    MaxSquareMatrix(void);
    ~MaxSquareMatrix(void);

    int minTestMaxSquareMatrix(int a, int b, int c);
    void printMaxSubSquare(bool M[R][C]);

    void displayMatrix( int const *p,  int r,  int c);
    void rotate( int *pSource,  int *pDestination,  int row,  int col);
};

void TestMaxSquareMatrix();
void TestrotateMatrix();