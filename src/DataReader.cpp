//
// Created by matthew on 5/30/24.
//

#include "../header/DataReader.h"

DataReader::DataReader(const std::string &imagePath, const std::string &labelPath) {

    imagesFile.open(imagePath, std::ios::binary);
    labelsFile.open(labelPath, std::ios::binary);

    if (!imagesFile.is_open() || !labelsFile.is_open()) {
        throw std::runtime_error("Failed to open file");
    }


    imagesFile.read(reinterpret_cast<char*>(&imageMetadata), sizeof(imageMeta));
    labelsFile.read(reinterpret_cast<char*>(&labelMetadata), sizeof(labelMeta));
    swapEndianImageMeta(imageMetadata);
    swapEndianLabelMeta(labelMetadata);


    if (imageMetadata.magic_number != 0x00000803 || labelMetadata.magic_number != 0x00000801) {
        throw std::runtime_error("Invalid magic number. Not a valid MNIST dataset.");
    }
    current_image_index = 0;
    current_label_index = 0;

}


dataset DataReader::getBatch(size_t batch_size) {
    if (current_image_index >= imageMetadata.number_of_images || current_label_index >= labelMetadata.number_of_items) {
        return {};
    }
    dataset batch;
    batch.reserve(batch_size);

    for (size_t i = 0; i < batch_size; ++i) {
        if (current_image_index >= imageMetadata.number_of_images || current_label_index >= labelMetadata.number_of_items) {
            break;
        }

        // Read label
        unsigned char label;
        labelsFile.read(reinterpret_cast<char*>(&label), 1);
        Maths::Vector label_vector(10, 0);
        label_vector[static_cast<int>(label)] = 1;

        // Read image
        Maths::Vector image(imageMetadata.number_of_rows * imageMetadata.number_of_columns);
        for (uint32_t j = 0; j < imageMetadata.number_of_rows * imageMetadata.number_of_columns; ++j) {
            unsigned char pixel;
            imagesFile.read(reinterpret_cast<char*>(&pixel), 1);
            image[j] = static_cast<double>(pixel) / 255.0;  // Normalize pixel values
        }

        batch.emplace_back(std::move(image), std::move(label_vector));

        current_image_index++;
        current_label_index++;
    }

    return batch;
}
