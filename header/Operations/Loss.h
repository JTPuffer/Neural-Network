//
// Created by matthew on 6/3/24.
//

#ifndef NETWORK_LOSS_H
#define NETWORK_LOSS_H

#include "../Math.h"

class Loss {


public:
    Loss()= default;
    static Maths::MathVector<double> forwould(const Maths::MathVector<double>& input, const Maths::MathVector<double>& target);
    static Maths::MathVector<double> backward(const Maths::MathVector<double>& input, const Maths::MathVector<double>& target);

    virtual ~Loss()= default;
};


#endif //NETWORK_LOSS_H
