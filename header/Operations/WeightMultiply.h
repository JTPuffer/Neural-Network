//
// Created by matthew on 6/2/24.
//

#ifndef NETWORK_WEIGHTMULTIPLY_H
#define NETWORK_WEIGHTMULTIPLY_H

#include "Operation.h"
class WeightMultiply : public Operation{
private:
    Maths::Matrix& weights;
public:
    explicit WeightMultiply(Maths::Matrix& weights);

    void forwould(Maths::MathVector<double> &input) override;
    Maths::MathVector<double> backward(Maths::MathVector<double> &input) override;
};


#endif //NETWORK_WEIGHTMULTIPLY_H
