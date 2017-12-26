#pragma once
#include "Clonables.h"
#include "Persistent.h"
#include "Archive.h"

#define PERSISTENT_DECL(className)		\
	public:								\
	virtual Clonable* createObj() const \
	{									\
		return new className();			\
	}									\
	private:							\
	static AddClonable _addClonable;

#define PERSISTENT_IMPL(className)		\
	AddClonable className::_addClonable(#className, new className());

class Event : public Persistent {
private:
	int _id;
public:
	Event() : _id(0) {}
	virtual ~Event() {}
	int getId() const { return _id; }
protected:
	virtual void serialize(Archive& stream);

	PERSISTENT_DECL(Event)
};