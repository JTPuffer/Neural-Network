//
// Created by matthew on 5/30/24.
//

#include "../header/DataReader.h"

std::vector<Image> DataReader::readData(const std::string &imagePath, const std::string &labelPath) {

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

    std::vector<int> labels(labelMetadata.number_of_items);
    for (int i = 0; i < labelMetadata.number_of_items; ++i) {
        unsigned char label;
        labelsFile.read(reinterpret_cast<char*>(&label), 1);
        labels[i] = static_cast<int>(label);
    }

    std::vector<Image> dataset;
    for (int i = 0; i < imageMetadata.number_of_images; ++i) {
        Maths::Vector image(imageMetadata.number_of_rows * imageMetadata.number_of_columns );
        imagesFile.read(reinterpret_cast<char*>(image.data()), imageMetadata.number_of_rows * imageMetadata.number_of_columns);
        dataset.emplace_back(std::move(image), labels[i]);
    }

    return dataset;
}



