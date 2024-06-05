//
// Created by matthew on 5/30/24.
//

#include "../header/DataReader.h"

dataset DataReader::readData(const std::string &imagePath, const std::string &labelPath) {

    std::ifstream imagesFile(imagePath, std::ios::binary);
    std::ifstream labelsFile(labelPath, std::ios::binary);

    if (!imagesFile.is_open() || !labelsFile.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    imageMeta imageMetadata{};
    labelMeta labelMetadata{};

    imagesFile.read(reinterpret_cast<char*>(&imageMetadata), sizeof(imageMeta));
    labelsFile.read(reinterpret_cast<char*>(&labelMetadata), sizeof(labelMeta));
    swapEndianImageMeta(imageMetadata);
    swapEndianLabelMeta(labelMetadata);


    if (imageMetadata.magic_number != 0x00000803 || labelMetadata.magic_number != 0x00000801) {
        throw std::runtime_error("Invalid magic number. Not a valid MNIST dataset.");
    }

    std::vector<Maths::Vector> labels(labelMetadata.number_of_items, Maths::Vector(10, 0));
    std::vector<Maths::Vector> images;
    for (int i = 0; i < labelMetadata.number_of_items; ++i) {
        unsigned char label;
        labelsFile.read(reinterpret_cast<char*>(&label), 1);

        labels[i][static_cast<int>(label)] = 1;
    }



    for (uint32_t i = 0; i < imageMetadata.number_of_images; ++i) {
        Maths::Vector image(imageMetadata.number_of_rows * imageMetadata.number_of_columns);
        for (uint32_t j = 0; j < imageMetadata.number_of_rows * imageMetadata.number_of_columns; ++j) {
            unsigned char pixel;
            imagesFile.read(reinterpret_cast<char*>(&pixel), 1);
            image[j] = static_cast<double>(pixel) / 255.0;  // Normalize pixel values
        }
        images.push_back(std::move(image));
    }
    return {images, labels};
}



