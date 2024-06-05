//
// Created by matthew on 6/2/24.
//

#ifndef NETWORK_BIASADD_H
#define NETWORK_BIASADD_H

#include "Operation.h"
class BiasAdd : public Operation{

private:
    Maths::MathVector<double>& Bias;
    Maths::MathVector<double> grad_of_cost;

public:
    void train(double learningRate) override;

    explicit BiasAdd(Maths::MathVector<double>& bias);
    void forwould(Maths::MathVector<double> &input) override;

protected:
    void derivative_of_cost(Maths::MathVector<double> &input) override;
    Maths::MathVector<double> derivative_of_input(Maths::MathVector<double> &input) override;

};


#endif //NETWORK_BIASADD_H
