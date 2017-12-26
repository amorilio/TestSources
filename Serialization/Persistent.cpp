#include "Persistent.h"
#include "Clonables.h"

void Persistent::store(Archive& stream) const
{
	string className = typeid(*this).name();
	className = className.substr(className.find(' ') + 1);

	stream << className;
	int ver = version();
	stream << ver;
	stream.setDirection(true);

	const_cast<Persistent *>(this)->serialize(stream);
}


Persistent* Persistent::load(Archive& stream)
{
	string className;
	stream >> className;

	Clonable* clone = Clonables::Instance().create(className.c_str());
	if (clone == NULL)
		throw "Persistent::load : Error creating object";

	auto_ptr<Clonable> delitor(clone);

	Persistent * obj = dynamic_cast<Persistent *>(clone);
	if (obj == NULL) {
		throw "Persistent::load : Error creating object";
	}

	int ver = -1;

	stream >> ver;

	if (ver != obj->version())
		throw "Persistent::load : unmatched version number";

	stream.setDirection(false);

	obj->serialize(stream);

	delitor.release();

	return obj;
}