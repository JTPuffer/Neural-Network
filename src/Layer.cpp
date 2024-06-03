//
// Created by matthew on 5/29/24.
//

#include "../header/Layer.h"
#include "../header/Operations/BiasAdd.h"
#include "../header/Operations/Sigmoid.h"
#include "../header/Operations/WeightMultiply.h"

Layer::Layer(int neurons, int seed)
        : neurons(neurons), seed(seed), first(true) {

}

Layer::~Layer() {
    for(Operation* o : operations){
        delete o;
    }

};




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

    this->operations.push_back(new WeightMultiply(weights));
    this->operations.push_back(new BiasAdd(bias));
    this->operations.push_back(new Sigmoid());
}

Maths::MathVector<double> Layer::forward(Maths::Vector& input) {
    if (this->first) {
        this->first = false;
        this->setupLayer(input);
    }



    for(Operation* o : operations){
        o->forwould(input);
    }

    return input;
}

void Layer::backward(const std::vector<Layer>& input) {
    // Implement the backward pass logic as needed
}


