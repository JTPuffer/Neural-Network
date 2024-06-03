//
// Created by matthew on 6/2/24.
//

#include <utility>

#include "../../header/Operations/WeightMultiply.h"

void WeightMultiply::forwould(Maths::MathVector<double> &input) {
    input = Maths::dotProduct(weights,input);
}

Maths::MathVector<double> WeightMultiply::backward(Maths::MathVector<double> &input) {

    return {};
}

WeightMultiply::WeightMultiply(Maths::Matrix& weights) :weights(weights){

}

