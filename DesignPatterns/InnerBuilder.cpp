#include <iostream>
#include "InnerBuilder.h"

using namespace std;



string ConcreteObject::getName() const
{
	return name;
}

int ConcreteObject::getAge() const
{
	return age;
}

string ConcreteObject::InnerBuilder::getName() const
{
	return name;
}

int ConcreteObject::InnerBuilder::getAge() const
{
	return age;
}

ConcreteObject::InnerBuilder& ConcreteObject::InnerBuilder::setName(string n)
{
	name = n;
	return *this;
}

ConcreteObject::InnerBuilder& ConcreteObject::InnerBuilder::setAge(int a)
{
	age = a;
	return *this;
}

ConcreteObject* ConcreteObject::InnerBuilder::build()
{
	return new ConcreteObject(*this);
}

ConcreteObject::ConcreteObject(InnerBuilder& ib)
{
	name = ib.getName();
	age = ib.getAge();
}

void InnerBuilderTest()
{
	ConcreteObject* obj = ConcreteObject::InnerBuilder().setName("aa").setAge(14).build();
	cout << obj->getName() << " " << obj->getAge() << endl;
}
