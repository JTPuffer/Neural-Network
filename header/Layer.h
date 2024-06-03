#ifndef NETWORK_LAYER_H
#define NETWORK_LAYER_H

#include <vector>
#include <functional>
#include <random>
#include <memory>
#include "Math.h"
#include "Operations/Operation.h"

class Layer {
private:

    std::vector<Operation*> operations;
    const int neurons;
    Maths::Matrix weights;
    Maths::Vector bias;
    int seed;
    bool first;

public:
    Layer(int neurons, int seed = 1);
    virtual ~Layer();

    void setupLayer(const Maths::Vector& input);
    Maths::MathVector<double> forward(Maths::Vector& input);
    void backward(const std::vector<Layer>& input);
};

#endif //NETWORK_LAYER_H