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

    // Xavier initialization for weights
    double xavier_scale = std::sqrt(2.0 / (input.size() + neurons));
    std::normal_distribution<> dis(0.0, xavier_scale);

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

Maths::Vector Layer::backward(Maths::Vector &input) {

    for (auto it = operations.rbegin(); it != operations.rend(); ++it) {
        input = (*it)->backward(input);
    }
    return input;
}

void Layer::train(double learningRate) {
    for(Operation* o : operations){
        o->train(learningRate);
    }
}


