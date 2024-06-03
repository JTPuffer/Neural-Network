//
// Created by matthew on 6/2/24.
//

#include "../../header/Operations/Sigmoid.h"

#include <functional>


void Sigmoid::forwould(Maths::MathVector<double> &input) {
    //potenital bug transform edits the inputs value
    std::transform(input.begin(), input.end(), input.begin(), [](double x) {return 1 / (1 + std::exp(-x));});

}

Maths::MathVector<double> Sigmoid::backward(Maths::MathVector<double> &input) {
    return Maths::MathVector<double>();
}
