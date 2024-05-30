#include <iostream>

#include "Network.h"
#include "Layer.h"

int main(){

    Network bob = Network(Layer(10,[](double x) {return 1 / (1 + std::exp(-x));},534),   Layer(5,[](double x) {return 1 / (1 + std::exp(-x));},5));

    Maths::MathVector<double> vec = {1, 2, 34, 5, 6, 7, 8, 9};
    bob.forward(vec).print();

    return 0;
}

