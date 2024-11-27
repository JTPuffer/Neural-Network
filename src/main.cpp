#include <iostream>

#include "../header/Network.h"
#include "../header/Layer.h"
#include "../header/DataReader.h"

int main(){

    DataReader dataReader = DataReader("numbers/train-images.idx3-ubyte","numbers/train-labels.idx1-ubyte");



    Network bob = Network({Layer(89, 534),Layer(10, 10)} );


    bob.train(dataReader, 200, Loss());
    return 0;
}

