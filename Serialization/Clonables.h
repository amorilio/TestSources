#pragma once

#include "Clonable.h"

class Clonables {
private:
	typedef map<string, const Clonable*> NameToClonable;
	NameToClonable __clonables;
private:
	Clonables() {}
	Clonables(const Clonables&);                 // Prevent copy-construction
	Clonables& operator=(const Clonables&);      // Prevent assignment
	~Clonables();

public:
	static Clonables& Instance()
	{
		static Clonables instance;   // Guaranteed to be destroyed.                              
		return instance;    // Instantiated on first use.
	}
public:
	void addClonable(const char* className, const Clonable* clone);
	Clonable* create(const char *className);
};

class AddClonable {
public:
	AddClonable(const char* className, const Clonable* clone){
		Clonables::Instance().addClonable(className, clone);
	}
};