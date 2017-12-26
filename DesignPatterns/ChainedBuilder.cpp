#include <iostream>
#include <memory>
#include <vector>

//// Backported from C++14
//namespace std
//{
//	template<typename T, typename ...Args>
//	std::unique_ptr<T> make_unique(Args &&... args)
//	{
//		return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
//	}
//}

using namespace std;

class Widget
{
public:
	explicit Widget(string &name) : m_name(name)	{ }

	~Widget() { }

	string const &name() const	{		return m_name;	}

private:
	string const m_name;
};

class WidgetBuilder
{
public:
	WidgetBuilder &name(string const &name)	{		m_name = name; return *this;	}
	operator std::unique_ptr<Widget>()		{		return make_unique<Widget>(m_name);	}

private:
	string m_name;
};

class WidgetContainer
{
public:
	WidgetContainer(string const &firstName, string const &lastName, unique_ptr<vector<unique_ptr<Widget>>> widgets) :	m_firstName(firstName),	m_lastName(lastName), m_widgets(move(*widgets))	{ }
	
	string firstName() const	{		return m_firstName;	}

	string lastName() const		{		return m_lastName;	}

	vector<unique_ptr<Widget>> const &widgets() const	{		return m_widgets;	}

private:
	string m_firstName;
	string m_lastName;
	vector<unique_ptr<Widget>> m_widgets;
};

class WidgetContainerBuilder
{
public:

	WidgetContainerBuilder &firstName(string const &firstName)	{		m_firstName = firstName; return *this;	}

	WidgetContainerBuilder &lastName(string const &lastName)	{		m_lastName = lastName; return *this;	}

	WidgetContainerBuilder &addWidget(WidgetBuilder &widgetBuilder)
	{
		m_widgetBuilders.push_back(&widgetBuilder);
		return *this;
	}

	unique_ptr<WidgetContainer> create()
	{
		unique_ptr<vector<unique_ptr<Widget>>> widgets = make_unique<vector<unique_ptr<Widget>>>();
		for (auto &widgetBuilder : m_widgetBuilders)
		{
			widgets->push_back(*widgetBuilder);
		}
		
		return make_unique<WidgetContainer>(m_firstName, m_lastName, move(widgets));
	}

private:
	string m_firstName;
	string m_lastName;
	vector<WidgetBuilder *> m_widgetBuilders;
};

int WidgetContainerTest()
{
	unique_ptr<WidgetContainer> x(	WidgetContainerBuilder().firstName("my-first-name").lastName("my-last-name")
		.addWidget( WidgetBuilder().name("my-widget-0"))
		.addWidget(	WidgetBuilder().name("my-widget-1"))
		.create());

	cout << x->firstName().c_str() << " " << x->lastName().c_str() << endl;
	for (auto &widget : x->widgets())
	{
		cout << widget->name().c_str() << endl;
	}

	return 0;
}