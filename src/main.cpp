#include <iostream>

#include "../header/Network.h"
#include "../header/Layer.h"
#include "../header/DataReader.h"

int main(){

    DataReader::dataset dataset = DataReader::readData("numbers/train-images.idx3-ubyte","numbers/train-labels.idx1-ubyte");

    Network bob = Network(Layer(28,[](double x) {return 1 / (1 + std::exp(-x));},534),   Layer(5,[](double x) {return 1 / (1 + std::exp(-x));},5));

    Maths::MathVector<double> vec = {1, 2, 34, 5, 6, 7, 8, 9};




    bob.forward(dataset[0].first).print();
    return 0;
}

