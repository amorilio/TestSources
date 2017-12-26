#include <string>

class ConcreteObject
{
private:
	std::string	name;
	int		age;

public:
	std::string getName() const;

	int getAge() const;

	static class InnerBuilder
	{
	private:
		std::string	name;
		int		age;


	public:
		std::string getName() const;

		int getAge() const;

		InnerBuilder& setName(std::string n);

		InnerBuilder& setAge(int a);

		ConcreteObject* build();
	};

	ConcreteObject(InnerBuilder& ib);
};

extern void InnerBuilderTest();