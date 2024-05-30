//
// Created by matthew on 5/29/24.
//

#include "Layer.h"

Layer::Layer(int neurons, const std::function<double(double)>& activationFunction, int seed)
        : neurons(neurons), activationFunction(activationFunction), seed(seed), first(true) {}

Layer::~Layer() = default;


void Layer::setupLayer(const Maths::MathVector<double>& input) {
    std::mt19937 gen(this->seed);
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Initialize weights as a Matrix
    weights = Maths::Matrix(neurons, input.size());
    for (size_t i = 0; i < neurons; ++i) {
        for (size_t j = 0; j < input.size(); ++j) {
            weights(i, j) = dis(gen);
        }
    }

    // Initialize bias as a MathVector
    bias = Maths::Vector(neurons);
    for (size_t i = 0; i < neurons; ++i) {
        bias[i] = dis(gen);
    }
}

Maths::MathVector<double> Layer::forward(Maths::Vector& input) {
    if (this->first) {
        this->first = false;
        this->setupLayer(input);
    }

    Maths::Vector output = Maths::dotProduct(weights,input);
    output = output + bias;
    std::transform(output.begin(), output.end(), output.begin(), activationFunction);



    return output;
}

void Layer::backward(const std::vector<Layer>& input) {
    // Implement the backward pass logic as needed
}


