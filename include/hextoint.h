#pragma once

#include <sstream>

unsigned int hextoint(std::string hexstring)
{
    unsigned long value;

    std::stringstream sstream;
    sstream << std::hex << hexstring;

    sstream >> value;
    return value;
}