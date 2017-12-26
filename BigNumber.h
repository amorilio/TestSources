// BigNumber.h: interface for the BigNumber class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BIGNUMBER_H__F1634EA4_03E0_4C99_9AF7_D4D682AECDD0__INCLUDED_)
#define AFX_BIGNUMBER_H__F1634EA4_03E0_4C99_9AF7_D4D682AECDD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define ARRAY_SIZE 3

template <typename T>
class BigNumber
{
public:
	class MaxRangeReached
	{
	public:
		char* what()
		{
			return "Maximal Big number. Can not be increased.";
		}
	};

	BigNumber();
	virtual ~BigNumber();

	BigNumber(const BigNumber<T>& bn);
	BigNumber(const T input);
	BigNumber<T>& operator= (const BigNumber<T>& bn);

	void operator++ ();
	void operator-- ();
	void operator+ (const BigNumber<T>& bn);
	void operator- (const BigNumber<T>& bn);
	void operator+ (T i);
	void operator- (T i);

	void reset();
	void print();
	bool isMax();
	bool isMin();

protected:
	void update(T index);

private:
	T _data[ARRAY_SIZE];
};

extern void BigNumberTest();

#endif // !defined(AFX_BIGNUMBER_H__F1634EA4_03E0_4C99_9AF7_D4D682AECDD0__INCLUDED_)
