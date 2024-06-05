//
// Created by matthew on 5/30/24.
//

#ifndef NETWORK_OPERATION_H
#define NETWORK_OPERATION_H

#include "../Math.h"

class Operation {
protected:
    Maths::MathVector<double> input;

public:
    Operation()= default;
    virtual ~Operation()= default;
    virtual void forwould(Maths::MathVector<double> &input) = 0;

    virtual Maths::MathVector<double> backward(Maths::MathVector<double>& input);

    virtual void train(double learningRate) = 0;
protected:
    virtual void derivative_of_cost(Maths::MathVector<double>& input) = 0;
    virtual Maths::MathVector<double> derivative_of_input(Maths::MathVector<double>& input) = 0;
};





#endif //NETWORK_OPERATION_H
