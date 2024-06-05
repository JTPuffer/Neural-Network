//
// Created by matthew on 6/3/24.
//

#include "../../header/Operations/Loss.h"
#include "algorithm"
Maths::MathVector<double> Loss::forwould(const Maths::MathVector<double>& input, const Maths::MathVector<double>& target) {
    Maths::MathVector<double> out = target - input;
    std::transform(out.begin(),out.end(),out.begin(),[](double a) {return std::pow(a,2);} );
    return out;
}

Maths::MathVector<double> Loss::backward(const Maths::MathVector<double>& input, const Maths::MathVector<double>& target) {
    return (target - input) * -2.0;
}
