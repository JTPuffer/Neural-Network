//
// Created by matthew on 5/29/24.
//
#include <vector>
#include "Layer.h"
#include "Operations/Loss.h"
#include "DataReader.h"

#ifndef NETWORK_NETWORK_H
#define NETWORK_NETWORK_H

class Network {

private:
    std::vector<Layer> layers;

public:

    explicit Network(std::vector<Layer> layers);


    virtual ~Network() = default;

    Maths::Vector forward(const Maths::Vector& vars);
    void backward(Maths::MathVector<double> vector);
    void train(DataReader& reader, size_t batch_size, const Loss& loss);



};


#endif //NETWORK_NETWORK_H
