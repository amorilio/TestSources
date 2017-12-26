// Image.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "WinDef.h"

class Image
{
public :
	Image() 
	{
		_image = NULL;
	}

	bool CreateImage(int rows, int cols)
	{
		if (rows <= 0 || cols <= 0)
			return false;

		int iSizeOfData = rows * cols;
		_image = new BYTE[iSizeofHeader + iSizeOfData];

		memset(_image,					 0, iSizeofHeader);
		memset(_image + iSizeofHeader, 255, iSizeOfData);

		int* pRows = (int*) (_image);
		int* pCols = (int*) (_image + sizeof(int));

		*pRows = rows;
		*pCols = cols;

		return true;
	}

	bool Display()
	{
		int* iRows = (int *)_image;
		int* iCols = (int *)(_image + sizeof(int));

		if (*iCols <= 0 || *iRows <= 0)
			return false;

		for (int row = 0; row < *iRows; row++)
		{
			for (int col = 0; col < *iCols; col++)
			{
				printf("%d\t", _image[iSizeofHeader + (row * (*iCols) + col)]);
			}
			printf("\n");
		}


		return true;
	}

	bool DrawImage(int xLeft, int yLeft, int xRight, int yRight)
	{
		if (!_image)
			return false;

		int* iRows = (int *)_image;
		int* iCols = (int *)(_image + sizeof(int));

		if (xLeft < 0			|| yLeft < 0			|| xRight < 0			|| yRight < 0		|| 
			xLeft > *iCols	    || yLeft > *iRows	    || xRight > *iCols	    || yRight  > *iRows ||
			xLeft >= xRight		|| yLeft >= yRight)
			return false;


		for (int row = yLeft; row < yRight; row++)
		{
			memset(_image + iSizeofHeader + (row * (*iCols) + xLeft), 0, xRight - xLeft);
			/*
			for (int col = xLeft; col < xRight; col++)
			{
				int iIndex = (row * (*iCols)) + col;
				_image[iSizeofHeader + iIndex] = 0;
			}
			*/
		}
		return true;
	}

private:
	BYTE* _image;

	static const int iSizeofHeader = 2 * sizeof(int);
};

int _tmain(int argc, _TCHAR* argv[])
{
	Image* image = new Image();
	image->CreateImage(4, 5);
	image->Display();
	image->DrawImage(2, 2, 3, 4);
	printf("----------------------------------------------\n");
	image->Display();
	image->DrawImage(2, 0, 4, 1);
	printf("----------------------------------------------\n");
	image->Display();
	return 0;
}

