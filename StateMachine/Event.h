#pragma once

#include <stdio.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>

template <class T>
class Event
{
public:
	virtual ~Event(){};

	virtual std::string toString() {stringstream ss; ss<<m_value; return ss.str();};
	virtual T getValue() {return m_value;}

protected:
	Event() {} ;
	Event(T& value ) : m_value(value) {} ;
	Event(const Event& rEvent) : m_value(rEvent.m_value) {} ;

private:
	T m_value;
};

class CharacterEvent : public Event<char>
{
public:
	CharacterEvent(char c) : Event(c) {};
	virtual ~CharacterEvent(void) {};	
};

class AnyEvent : public CharacterEvent
{
public:
	static const char AnyEventChar = '*';

	virtual ~AnyEvent(void) {};	
	AnyEvent() : CharacterEvent(AnyEventChar) {};
};