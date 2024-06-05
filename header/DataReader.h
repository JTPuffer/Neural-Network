//
// Created by matthew on 5/30/24.
//

#ifndef NETWORK_DATAREADER_H
#define NETWORK_DATAREADER_H

#include <string>
#include <fstream>
#include <iterator>
#include <vector>
#include <iostream>
#include "Math.h"

typedef std::pair<std::vector<Maths::Vector>, std::vector<Maths::Vector>> dataset;
class DataReader {
private:
    struct __attribute__ ((packed)) imageMeta {
        uint32_t magic_number;
        uint32_t number_of_images;
        uint32_t number_of_rows;
        uint32_t number_of_columns;
    };

    struct  __attribute__ ((packed)) labelMeta{
        uint32_t magic_number;
        uint32_t number_of_items;
    };
    static uint32_t swapEndian(uint32_t x) {
        return ((x >> 24) & 0xFF) |
               ((x << 8) & 0xFF0000) |
               ((x >> 8) & 0xFF00) |
               ((x << 24) & 0xFF000000);
    }
    static void swapEndianImageMeta(imageMeta& meta) {
        meta.magic_number = swapEndian(meta.magic_number);
        meta.number_of_images = swapEndian(meta.number_of_images);
        meta.number_of_rows = swapEndian(meta.number_of_rows);
        meta.number_of_columns = swapEndian(meta.number_of_columns);
    }

    static void swapEndianLabelMeta(labelMeta& meta) {
        meta.magic_number = swapEndian(meta.magic_number);
        meta.number_of_items = swapEndian(meta.number_of_items);
    }
public:

    static dataset readData(const std::string& image,const std::string& label);


};


#endif //NETWORK_DATAREADER_H
