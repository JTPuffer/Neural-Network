//
// Created by matthew on 6/2/24.
//

#include <utility>

#include "../../header/Operations/WeightMultiply.h"

void WeightMultiply::forwould(Maths::MathVector<double> &input) {
    this->input.resize(input.size());
    std::copy(input.begin(),input.end(),this->input.begin());

    input = Maths::dotProduct(weights,input);
    //input = ;
}

WeightMultiply::WeightMultiply(Maths::Matrix& weights) :weights(weights){

}

void WeightMultiply::derivative_of_cost(Maths::MathVector<double> &gradOutput) {

    grad_of_cost =  Maths::outerProduct(gradOutput, input);;
}

Maths::MathVector<double> WeightMultiply::derivative_of_input(Maths::MathVector<double> &gradOutput) {

    return  Maths::dotProduct( weights.transpose(),gradOutput);
}

void WeightMultiply::train(double learningRate) {
    weights = weights - (grad_of_cost * learningRate);
}

