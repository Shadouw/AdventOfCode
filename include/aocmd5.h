#pragma once

// Link against crypto to make MD5 function available

#include <iomanip>
#include <string>
#include <sstream>

// Install on Linux: 
// sudo apt-get install libssl-dev
#include <openssl/md5.h>

std::string getmd5hexhash(const std::string input)
{
    static unsigned char md5_result[MD5_DIGEST_LENGTH];
    MD5((const unsigned char *)input.c_str(), input.length(), md5_result);

    std::stringstream retval;

    for (auto c : md5_result)
    {
        retval << std::setfill('0') << std::setw(2) << std::hex << (unsigned int)c;
    }

    return retval.str();
}