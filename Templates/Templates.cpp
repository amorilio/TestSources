#include <cmath>
#include <type_traits>
#include <limits>
#include <vector>

using namespace std;
#pragma optimize("",off)

template <typename T>
bool equals(T lhs, T rhs)
{
	return lhs == rhs;
}

template <>
bool equals<float>(float lhs, float rhs)
{
	return true;
}

// TAG DISPATCHING:
//	Example of using conditional template with constructing true_type/false type with is_floating_point query
//
//	Dispatch functionality to concreate template function having type parameter.
//
template <typename T>
bool conditional_equals(T lhs, T rhs)
{
	//return conditional_equals(lhs, rhs, conditional_t < is_floating_point<T>::value, true_type, false_type > {});
	return conditional_equals(lhs, rhs, conditional < is_floating_point<T>::value, true_type, false_type >::type{});
}

template <typename T>
bool conditional_equals(T lhs, T rhs, true_type) // for floating point
{
	return abs(lhs-rhs) < std::numeric_limits<T>::epsilon();
}
template <typename T>
bool conditional_equals(T lhs, T rhs, false_type) // for floating point
{
	return lhs==rhs;
}


//
// SFINAE -> Substitution faliure is not a failure 

//
//	This template will work for everyone exept Float
//	
template < typename T, typename = enable_if_t<!is_floating_point<T>::value > >
bool SFINAE1_equals(T lhs, T rhs)
{
	return lhs == rhs;
}
//
// we can not write same with template specification - compilation error 
//
//template <typename T, enable_if_t<is_floating_point<T>>>
//bool SFINAE_equals(T lhs, T rhs)
//{
//	return abs(lhs - rhs) < std::numeric_limits<T>::epsilon();
//}

template < typename T >
bool SFINAE2_equals(T lhs, T rhs, enable_if_t<!is_floating_point<T>::value>* = nullptr)
{
	return lhs == rhs;
}
template < typename T >
bool SFINAE2_equals(T lhs, T rhs, enable_if_t<is_floating_point<T>::value>* = nullptr)
{
	return abs(lhs - rhs) < std::numeric_limits<T>::epsilon();
}

//
//	Implement concrete funciton according to return type
//
template < typename T >
enable_if_t<!is_floating_point<T>::value, bool> SFINAE3_equals(T lhs, T rhs)
{
	return lhs == rhs;
}
template < typename T >
enable_if_t<is_floating_point<T>::value, bool>  SFINAE3_equals(T lhs, T rhs)
{
	return abs(lhs - rhs) < std::numeric_limits<T>::epsilon();
}


//
//	Fucntion Predicate as template parameter
////////////////////////////////////////////////////////////////////////////////////////////////////

bool has2(int const& i) 
{ 
	return i == 2; 
}

bool has3(int& i)		
{ 
	return i == 3; 
}

class Has4
{
public:
	bool operator()(int const& i) { return i == 4; }
};

template <typename It, typename Pred>
bool contains(It f, It l, Pred foo)
{
	for (; f != l; ++f)
	{
		if (foo(*f)) 
			return true;
	}
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//	Fucntion Predicate as template parameter
//

//
//	Curiously recurring template pattern
////////////////////////////////////////////////////////////////////////////////////////////////////
class shape
{
public:
	virtual shape* clone() = 0;
	virtual ~shape() = default;
};

template <typename T>
class shapeCRTP : public shape
{
	virtual shape* clone() override { return new T(*static_cast<T*>(this)); }
};

class square : public shapeCRTP<square>		{	int x;	};
class rectangle : public shapeCRTP<square>	{	int y;	};
class triangle : public shapeCRTP<square>	{	int z;	};

////////////////////////////////////////////////////////////////////////////////////////////////////
//	Curiously recurring template pattern
//
int main()
{
	bool b = equals(1, 2);
	b = equals(1.f, 2.f);


	b = conditional_equals(1.f, 2.f);

	SFINAE1_equals(1, 2);
	////SFINAE1_equals(1.f, 2.f);	// Compile Error
	SFINAE2_equals(1,2);
	SFINAE2_equals(1.f, 2.f);
	
	SFINAE3_equals(1, 2);
	SFINAE3_equals(1.f, 2.f);

	vector<int> v = { 1, 2, 3, 4 };
	b = contains(v.begin(), v.end(), has2);
	b = contains(v.cbegin(), v.cend(), has2);
	b = contains(v.begin(), v.end(), has3);
	// b = contains(v.cbegin(), v.cend(), has3); - Will not compile because has3 has no const parameter so Const iterators can not be used.
	b = contains(v.begin(), v.end(), Has4());
	b = contains(v.begin(), v.end(), [](int const& i) {return i == 5; });

	//
	//Curiously recurring template pattern
	//
	vector<shape *> shapesVector = { new square, new rectangle, new triangle, new square };
	for (auto pShape : shapesVector)
	{
		shape * s = pShape->clone();
	}
}