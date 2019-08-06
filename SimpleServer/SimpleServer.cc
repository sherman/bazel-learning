#include <string>
#include <iostream>
#include "ThirdParty/lz4/lib/lz4.h"
//#include "lib/lz4.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
    cout << "SimpleServer" << endl;

    const char* const src = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Lorem ipsum dolor site amat.";
    const int src_size = (int)(strlen(src) + 1);

    const int max_dst_size = LZ4_compressBound(src_size);

    char* compressed_data = malloc((size_t)max_dst_size);

    if (compressed_data == NULL) {
        cout << "Failed to allocate memory for *compressed_data." << endl;
    }

    const int compressed_data_size = LZ4_compress_default(src, compressed_data, src_size, max_dst_size);

    if (compressed_data_size <= 0) {
        cout << "A 0 or negative result from LZ4_compress_default() indicates a failure trying to compress the data." << endl;
        return 0;
    }

    if (compressed_data_size > 0) {
        cout << "We successfully compressed some data! Ratio." << endl;
        cout << "Compressed:" << strlen(compressed_data) << endl;
        return 0;
    }

    free(compressed_data);

    return 0;
}