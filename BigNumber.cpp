// BigNumber.cpp: implementation of the BigNumber class.
//
//////////////////////////////////////////////////////////////////////

#include "BigNumber.h"
#include "stdio.h"

//*********************************************************************************************
// Method:        BigNumber
// FullName:      BigNumber::BigNumber
// Access:        public
// Returns:
// Qualifier:
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************
template <typename T>
BigNumber<T>::BigNumber()
{
	reset();
}

template <typename T>
BigNumber<T>::BigNumber(const T input)
{
	int tmp = input;
	for(int i=0; i < ARRAY_SIZE; i++)
	{
		int val = tmp%10;
		_data[ARRAY_SIZE-1-i] = val;
		tmp /= 10;
	}
}
//*********************************************************************************************
// Method:        ~BigNumber
// FullName:      BigNumber::~BigNumber
// Access:        virtual public
// Returns:
// Qualifier:
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
BigNumber<T>::~BigNumber()
{
};

//*********************************************************************************************
// Method:        BigNumber
// FullName:      BigNumber::BigNumber
// Access:        public
// Returns:
// Qualifier:
// Parameter:     const BigNumber & bn
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
BigNumber<T>::BigNumber(const BigNumber& bn)
{
	for (int i=0; i<ARRAY_SIZE; i++)
		_data[i] = bn._data[i];
}

//*********************************************************************************************
// Method:        operator=
// FullName:      BigNumber::operator=
// Access:        public
// Returns:       BigNumber&
// Qualifier:
// Parameter:     const BigNumber & bn
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
BigNumber<T>& BigNumber<T>::operator= (const BigNumber<T>& bn)
{
	for (int i=0; i<ARRAY_SIZE; i++)
		_data[i] = bn._data[i];
	return *this;
}

//*********************************************************************************************
// Method:        operator++
// FullName:      BigNumber::operator++
// Access:        public
// Returns:       void
// Qualifier:
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
void BigNumber<T>::operator++ ()
{
	int iLastIndex = ARRAY_SIZE-1;
	if(_data[iLastIndex] == 9)
	{
		_data[iLastIndex] = 0;
		update(iLastIndex - 1);
	} else
	{
		_data[iLastIndex]++;
	}
}

//*********************************************************************************************
// Method:        operator--
// FullName:      BigNumber::operator--
// Access:        public
// Returns:       void
// Qualifier:
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
void BigNumber<T>::operator-- (){};
//*********************************************************************************************
// Method:        operator+
// FullName:      BigNumber::operator+
// Access:        public
// Returns:       void
// Qualifier:
// Parameter:     const BigNumber & bn
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
void BigNumber<T>::operator+ (const BigNumber& bn) {};
//*********************************************************************************************
// Method:        operator-
// FullName:      BigNumber::operator-
// Access:        public
// Returns:       void
// Qualifier:
// Parameter:     const BigNumber & bn
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
void BigNumber<T>::operator- (const BigNumber& bn) {};
//*********************************************************************************************
// Method:        operator+
// FullName:      BigNumber::operator+
// Access:        public
// Returns:       void
// Qualifier:
// Parameter:     int i
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
void BigNumber<T>::operator+ (T i) {};
//*********************************************************************************************
// Method:        operator-
// FullName:      BigNumber::operator-
// Access:        public
// Returns:       void
// Qualifier:
// Parameter:     int i
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
void BigNumber<T>::operator- (T i) {};

//*********************************************************************************************
// Method:        reset
// FullName:      BigNumber::reset
// Access:        public
// Returns:       void
// Qualifier:
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
void BigNumber<T>::reset()
{
	for (int i=0; i<ARRAY_SIZE; i++)
		_data[i] = 0;
}
//*********************************************************************************************
// Method:        print
// FullName:      BigNumber::print
// Access:        public
// Returns:       void
// Qualifier:
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
void BigNumber<T>::print()
{
	for (int i=0; i<ARRAY_SIZE; i++)
		printf("%d",_data[i]);
	printf("\n");
}
//*********************************************************************************************
// Method:        isMax
// FullName:      BigNumber::isMax
// Access:        public
// Returns:       bool
// Qualifier:
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
bool BigNumber<T>::isMax()
{
	for (int i=0; i<ARRAY_SIZE; i++)
		if(_data[i] != 9)
			return false;
		return true;
}
//*********************************************************************************************
// Method:        isMin
// FullName:      BigNumber::isMin
// Access:        public
// Returns:       bool
// Qualifier:
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
bool BigNumber<T>::isMin()
{
	for (int i=0; i<ARRAY_SIZE; i++)
		if(_data[i] != 0)
			return false;
		return true;
}
//*********************************************************************************************
// Method:        update
// FullName:      BigNumber::update
// Access:        private
// Returns:       void
// Qualifier:
// Parameter:     int index
//
// Author:	      Ilia Manasherov
// Description:
//*********************************************************************************************

template <typename T>
void BigNumber<T>::update(T index)
{
	if(index<0)
		throw MaxRangeReached();

	if(_data[index] == 9)
	{
		_data[index] = 0;
		update(index-1);
	} else
	{
		_data[index]++;
	}
}

//*********************************************************************************************
// Method:        BigNumberTest
// FullName:      BigNumberTest
// Access:        public
// Returns:       void
// Qualifier:
//
// Author:	      Ilia Manasherov
// Description:   Test Function for Big Number
//*********************************************************************************************
void BigNumberTest()
{
	// Check INT constructor
	BigNumber<int> b1(340);
	b1.print();

	// Check operator==
	BigNumber<int> b2;
	b2.print();
	b2 = b1;
	b2.print();

	// Check Copy Constructor
	BigNumber<int> b3(b2);
	b3.print();

	BigNumber<int> b;
	while(1)
	{
		try
		{
			b.print();
			++b;
		}
		catch (BigNumber<int>::MaxRangeReached e)
		{
			printf("%s",e.what());
			return;
		}
		catch (...)
		{
			return;
		}
	}
}