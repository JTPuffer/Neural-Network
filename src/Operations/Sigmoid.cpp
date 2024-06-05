//
// Created by matthew on 6/2/24.
//

#include "../../header/Operations/Sigmoid.h"

#include <functional>


void Sigmoid::forwould(Maths::MathVector<double> &input) {
    //potenital bug transform edits the inputs value
    this->input.resize(input.size());
    std::copy(input.begin(),input.end(),this->input.begin());
    std::transform(input.begin(), input.end(), input.begin(), [](double x) {return 1 / (1 + std::exp(-x));});
    //this->input.resize(input.size());

}
Maths::MathVector<double> Sigmoid::backward(Maths::MathVector<double> &input) {
    return derivative_of_input(input);
}

Maths::MathVector<double> Sigmoid::derivative_of_input(Maths::MathVector<double> &gradient) {
    std::transform(this->input.begin(), this->input.end(), this->input.begin(), [](double x) {return std::exp(-x)/std::pow(1+std::exp(-x),2);});
    return gradient * this->input;
}

void Sigmoid::derivative_of_cost(Maths::MathVector<double> &input) {
    throw std::logic_error("Function not yet implemented");

}

void Sigmoid::train(double learningRate) {
    return;
}
