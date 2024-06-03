//
// Created by matthew on 6/2/24.
//

#ifndef NETWORK_SIGMOID_H
#define NETWORK_SIGMOID_H

#include "Operation.h"

class Sigmoid :public Operation{
private:

public:
    void forwould(Maths::MathVector<double> &input) override;
    Maths::MathVector<double> backward(Maths::MathVector<double> &input) override;

};


#endif //NETWORK_SIGMOID_H
