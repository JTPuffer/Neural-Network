#include <iostream>

#include "../header/Network.h"
#include "../header/Layer.h"
#include "../header/DataReader.h"

int main(){

    DataReader::dataset dataset = DataReader::readData("numbers/train-images.idx3-ubyte","numbers/train-labels.idx1-ubyte");


    Network bob = Network({Layer(784, 534),Layer(10, 10)} );



    bob.forward(dataset[0].first).print();
    return 0;
}

