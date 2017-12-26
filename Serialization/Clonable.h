#pragma once
#include  <map>
#include  <string>

using namespace std;

class Clonable
{
public:
	virtual ~Clonable() {}

	virtual Clonable* createObj() const = 0;
};
