//
// Created by matthew on 5/30/24.
//

#ifndef NETWORK_OPERATION_H
#define NETWORK_OPERATION_H

#include "../Math.h"

class Operation {
public:
    Operation()= default;
    virtual ~Operation()= default;
    virtual void forwould(Maths::MathVector<double>& input) = 0;
    virtual Maths::MathVector<double> backward(Maths::MathVector<double>& input) = 0;
};


#endif //NETWORK_OPERATION_H