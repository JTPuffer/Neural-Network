#ifndef NETWORK_LAYER_H
#define NETWORK_LAYER_H

#include <vector>
#include <functional>
#include <random>
#include "Math.h"

class Layer {
private:
    const std::function<double(double)> activationFunction;
    const int neurons;
    Maths::Matrix weights;
    Maths::Vector bias;
    int seed;
    bool first;

public:
    explicit Layer(int neurons, const std::function<double(double)>& activationFunction, int seed = 1);
    virtual ~Layer();

    void setupLayer(const Maths::Vector& input);
    Maths::MathVector<double> forward(Maths::Vector& input);
    void backward(const std::vector<Layer>& input);
};

#endif //NETWORK_LAYER_H