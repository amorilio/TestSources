#pragma once
#include  <map>
#include  <string>

using namespace std;

class Archive
{
private:
	bool _isStoring;
public:
	Archive(bool isStoring = true) : _isStoring(isStoring) {}
	virtual ~Archive() {}

	virtual void write(const void* buffer, size_t length) {}
	virtual void read(void* buffer, size_t length) {}

	Archive& operator<<(const string& str);
	Archive& operator>>(string& str);

	Archive& operator<<(int val);
	Archive& operator>>(int& val);

	bool isStoring() const { return _isStoring; }
	void setDirection(bool isStoring) { _isStoring = isStoring; }
};

class ArchiveFile : public Archive
{
private:
	iostream* _stream;
public:
	ArchiveFile(iostream* stream) : _stream(stream) {}
	virtual ~ArchiveFile() {}

	virtual void write(const void *buffer, size_t length);
	virtual void read(void* buffer, size_t length);
};