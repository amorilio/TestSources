#pragma once
#include "Clonable.h"
#include "Archive.h"

class Persistent : public Clonable
{
public:
	virtual ~Persistent() {}
	static Persistent* load(Archive& stream);
	void store(Archive& stream) const;
protected:
	virtual void serialize(Archive& stream) {}
	virtual int version() const { return 0; }
};