#include "IPConverter.h"
#include <stdio.h>
#include <cstdint>
#include <cstring>
#include <thread>

IPConverter::IPConverter(){}

IPConverter::~IPConverter(){}

int IPConverter::parseIPV4StringToInt(char* ipAddress)
{
	unsigned int ip[4];
	sscanf(ipAddress, "%d.%d.%d.%d", 
		&ip[0], 
		&ip[1], 
		&ip[2], 
		&ip[3]);
	return ip[0] | (ip[1] << 8) | (ip[2] << 16) | (ip[3] << 24);
}

char* IPConverter::parseIntToIPV4String(int ip)
{
	char* result = new char[16];
	sprintf(result, "%d.%d.%d.%d", 
		(ip >> 0) & 0xFF, 
		(ip >> 8) & 0xFF, 
		(ip >> 16) & 0xFF, 
		(ip >> 24) & 0xFF);
	return result;
}

bool testIPConverter()
{
	IPConverter ipConverter;
	char ipAddressString[16]	= "192.168.125.221";
	char netMaskString[16]		= "255.255.0.0";
	char subnetString[16]		= "192.168.0.0";

	int ipAddress = ipConverter.parseIPV4StringToInt(ipAddressString);
	int netmask = ipConverter.parseIPV4StringToInt(netMaskString);
	int subnet = ipConverter.parseIPV4StringToInt(subnetString);

	if (ipAddress & netmask != subnet)
		return false;

	char* convertedipAddressString = ipConverter.parseIntToIPV4String(ipAddress);
	if (strcmp(ipAddressString, convertedipAddressString))
		return false;

	return true;
}