#include "Persistent.h"
#include "Archive.h"
#include "Event.h"
#include <fstream>

void main()
{
	auto_ptr<Event> event(new Event());

	fstream file("C:\\Users\\imanasherov\\Desktoptry.data", ios::out | ios::in | ios::binary | ios::trunc);

	ArchiveFile stream(&file);

	if (!file)
		throw "Unable to open file for writing";

	event->store(stream);

	file.seekg(0, ios::beg);

	Event* newEvent = dynamic_cast<Event*>(Persistent::load(stream));

	event.reset(newEvent);

	file.close();
}