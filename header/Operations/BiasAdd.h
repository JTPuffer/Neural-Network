//
// Created by matthew on 6/2/24.
//

#ifndef NETWORK_BIASADD_H
#define NETWORK_BIASADD_H

#include "Operation.h"
class BiasAdd : public Operation{
private:
    Maths::MathVector<double>& Bias;
public:

    explicit BiasAdd(Maths::MathVector<double>& bias);

    void forwould(Maths::MathVector<double> &input) override;
    Maths::MathVector<double> backward(Maths::MathVector<double> &input) override;
};


#endif //NETWORK_BIASADD_H
