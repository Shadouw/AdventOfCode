#pragma once

// Link against crypto to make MD5 function available

#include <iomanip>
#include <sstream>
#include <string>

// Install on Linux:
// sudo apt-get install libssl-dev
#include <openssl/evp.h>
#include <openssl/md5.h>

std::string getmd5hexhash(const std::string input)
{
    static unsigned char md5_result[MD5_DIGEST_LENGTH];
    // Deprecated:
    //MD5((const unsigned char*)input.c_str(), input.length(), md5_result);
    EVP_Q_digest(NULL, "MD5", NULL, input.c_str(), input.size(), md5_result, NULL);

    std::stringstream retval;

    for (auto c : md5_result) {
        retval << std::setfill('0') << std::setw(2) << std::hex << (unsigned int)c;
    }

    return retval.str();
}
