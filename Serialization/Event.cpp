#include "Event.h"

PERSISTENT_IMPL(Event)

void Event::serialize(Archive& stream)
{
	if (stream.isStoring())
		stream << _id;
	else
		stream >> _id;
}