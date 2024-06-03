//
// Created by matthew on 6/2/24.
//

#include "../../header/Operations/BiasAdd.h"

void BiasAdd::forwould(Maths::MathVector<double> &input) {
    input += Bias;
}

Maths::MathVector<double> BiasAdd::backward(Maths::MathVector<double> &input) {
    return {};
}



BiasAdd::BiasAdd(Maths::MathVector<double>& bias) : Bias(bias) {}


