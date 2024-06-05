//
// Created by matthew on 6/4/24.
//
#include "../../header/Operations/Operation.h"
Maths::MathVector<double> Operation::backward(Maths::MathVector<double> &input) {

    derivative_of_cost(input);

    return derivative_of_input(input);
}