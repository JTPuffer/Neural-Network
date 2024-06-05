//
// Created by matthew on 6/2/24.
//

#include "../../header/Operations/BiasAdd.h"

void BiasAdd::forwould(Maths::MathVector<double> &input) {
    this->input.resize(input.size());
    std::copy(input.begin(),input.end(),this->input.begin());
    input += Bias;
}


BiasAdd::BiasAdd(Maths::MathVector<double>& bias) : Bias(bias) {}

void BiasAdd::derivative_of_cost(Maths::MathVector<double> &input) {
    grad_of_cost =  input;
}

Maths::MathVector<double> BiasAdd::derivative_of_input(Maths::MathVector<double> &input) {
    return input;
}

void BiasAdd::train(double learningRate) {
    Bias = Bias - ( grad_of_cost * learningRate);
}


