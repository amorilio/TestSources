#pragma once

#include <iostream>

class MutableEmployee {
public:
    MutableEmployee(const std::string & name)  : _name(name), _access_count(0) { }

    void get_name(const std::string & name) {
        _name = name;
    }
    std::string get_name() const {
        _access_count++;
        return _name;
    }
    int get_access_count() const { return _access_count; }

private:
    std::string _name;
    mutable int _access_count;
};

void testMutableEmployee()
{
    const MutableEmployee me("Ilia");

    std::string sName = me.get_name();

    std::cout << sName.c_str() << " Access Count:" << me.get_access_count() << std::endl;
}