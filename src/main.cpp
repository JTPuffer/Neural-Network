#include <iostream>

#include "../header/Network.h"
#include "../header/Layer.h"
#include "../header/DataReader.h"

int main(){

    dataset dataset = DataReader::readData("numbers/train-images.idx3-ubyte","numbers/train-labels.idx1-ubyte");



    Network bob = Network({Layer(100, 534),Layer(10, 10)} );


    bob.train(dataset.first,dataset.second,Loss());
    return 0;
}

