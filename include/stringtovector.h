// Stolen from
// https://stackoverflow.com/questions/5607589/right-way-to-split-an-stdstring-into-a-vectorstring
#pragma once

#include <string>
#include <sstream>
#include <vector>

std::vector <std::string> stringtovector(const std::string &inputstring, const char separator)
{
    std::string token;
    std::stringstream sstream(inputstring);
    std::vector <std::string>tokens;

    while ( getline( sstream, token, separator ) )
    {
        if ( token.size() )
            tokens.push_back(token);
    }

    return tokens;
}

std::vector <long> stringtolongvector(const std::string &inputstring, const char separator)
{
    std::string token;
    std::stringstream sstream(inputstring);
    std::vector <long>tokens;

    while ( getline( sstream, token, separator ) )
    {
        if ( token.size() )
            tokens.push_back(atol(token.c_str()));
    }

    return tokens;
}