#pragma once
class IPConverter
{
public:
	IPConverter();
	~IPConverter();

	static int		parseIPV4StringToInt(char* ipAddress);
	static char*	parseIntToIPV4String(int ip);

};

extern bool testIPConverter();