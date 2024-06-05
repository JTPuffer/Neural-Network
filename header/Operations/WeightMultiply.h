//
// Created by matthew on 6/2/24.
//

#ifndef NETWORK_WEIGHTMULTIPLY_H
#define NETWORK_WEIGHTMULTIPLY_H

#include "Operation.h"
class WeightMultiply : public Operation{
private:
    Maths::Matrix& weights;
    Maths::Matrix grad_of_cost;
public:
    explicit WeightMultiply(Maths::Matrix& weights);

    void forwould(Maths::MathVector<double> &input) override;

protected:
    void derivative_of_cost(Maths::MathVector<double> &input) override;

public:
    void train(double learningRate) override;

protected:
    Maths::MathVector<double> derivative_of_input(Maths::MathVector<double> &input) override;
};


#endif //NETWORK_WEIGHTMULTIPLY_H
