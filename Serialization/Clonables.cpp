#include "Clonables.h"

Clonables::~Clonables()
{
	for (NameToClonable::const_iterator it = __clonables.begin(); it != __clonables.end(); it++){
		const Clonable* clone = it->second;
		delete clone;
	}
	__clonables.clear();
}

void Clonables::addClonable(const char* className, const Clonable* clone)
{
	string name = className;
	NameToClonable::const_iterator it = __clonables.find(name);
	if (it == __clonables.end()) {
		__clonables[name] = clone;
	}
}

Clonable* Clonables::create(const char *className)
{
	string name = className;
	NameToClonable::const_iterator it = __clonables.find(name);
	if (it == __clonables.end()) return NULL;

	const Clonable* clone = it->second;

	return clone->createObj();
}