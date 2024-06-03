//
// Created by matthew on 5/29/24.
//
#include <vector>
#include "Layer.h"
#ifndef NETWORK_NETWORK_H
#define NETWORK_NETWORK_H

class Network {

private:
    std::vector<Layer> layers;

public:

    explicit Network(std::vector<Layer> layers);


    virtual ~Network() = default;

    Maths::Vector forward(const Maths::Vector& vars);
    void backward();
    void train(std::vector<Maths::Vector> input , std::vector<float> target);



};


#endif //NETWORK_NETWORK_H
