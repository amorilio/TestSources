#include "Archive.h"
#include <vector>


// ------------------------------ Archive ------------------------------ //

Archive& Archive::operator<<(int val)
{
	write(&val, sizeof(int));
	return *this;
}

Archive& Archive::operator>>(int& val)
{
	read(&val, sizeof(int));
	return *this;
}

Archive& Archive::operator<<(const string& str)
{
	int length = str.length();
	*this << length;
	write(str.c_str(), sizeof(char) * length);
	return *this;
}

Archive& Archive::operator>>(string& str)
{
	int length = -1;
	*this >> length;
	vector<char> mem(length + 1);
	char* pChars = &mem[0];
	read(pChars, sizeof(char) * length);
	mem[length] = NULL;
	str = pChars;
	return *this;
}

// ------------------------------ ArchiveFile ------------------------------ //

void ArchiveFile::write(const void* buffer, size_t length)
{
	_stream->write((const char*)buffer, length);
	if (!*_stream)
		throw "ArchiveFile::write Error";
}

void ArchiveFile::read(void* buffer, size_t length)
{
	_stream->read((char*)buffer, length);
	if (!*_stream)
		throw "ArchiveFile::read Error";
}