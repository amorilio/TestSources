#include <string>

using namespace std;

class Document;
class DocumentA;
class DocumentB;

//
//	Option 1: static factory method
//
class Document
{
	string name;
	
protected:
	Document() = default;

public:

	virtual bool open() = 0;
	virtual bool close() = 0;

	virtual string getName() = 0;

	static Document* makeDocument(char choice);

	friend class DocumentFactory;

};

//
//	Option 2: Document factory class. If Document constructors are private , DocumentFactory should be friend.
//
class DocumentFactory
{
public:
	Document* makeDocument(char choice);
};

class DocumentA : public Document
{
private:
	DocumentA() = default;

public:
	virtual string getName()  { return "DocumentA"; }
	bool open() override { return true; }
	bool close() override { return true; }

	friend class Document;
	friend class DocumentFactory;
	friend class ApplicationA;
};

class DocumentB : public Document
{
private:
	DocumentB() = default;

public:
	virtual string getName()  { return "DocumentB"; }
	bool open()  override { return true; }
	bool close() override { return true; }

	friend class Document;
	friend class DocumentFactory;
	friend class ApplicationB;
};

//
//	Option 3: NewDocument will call concrete CreateDocument metod of overloaded classes.
//
class Application
{
public:
	Application() { _index = 0; }
	Document* NewDocument();
	virtual Document *CreateDocument() = 0;

private:
	int			_index;
	Document*	_docs[10];
};

class ApplicationA : public Application
{
public:
	Document *CreateDocument();
};

class ApplicationB : public Application
{
public:
	Document *CreateDocument();
};

//
//	Test Function
//
void FactoryMethodTest();