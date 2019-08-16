//
// Created by sherman on 06.08.2019.
//

#include <string>
#include <iostream>
#include "ThirdParty/lz4/lib/lz4.h"

namespace utils {
    const std::string compress(const std::string & str) {
        const int maxSize = LZ4_compressBound(str.length());

        char* buffer = new char[maxSize];

        if (buffer == NULL) {
            throw "Buffer was not allocated!";
        }

        const int compressedSize = LZ4_compress_default(str.c_str(), buffer, str.length(), maxSize);

        if (compressedSize <= 0) {
            throw "Data was not compressed!";
        }

        std::cout << str.length() << std::endl;
        std::cout << compressedSize << std::endl;

        std::string res(buffer);
        delete[] buffer;

        return res;
    }
}
