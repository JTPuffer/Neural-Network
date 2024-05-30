//
// Created by matthew on 5/29/24.
//

#include "../header/Network.h"


Network::Network(Layer one,Layer two) {
    this->layers.push_back(one);
    this->layers.push_back(two);
}

Maths::Vector Network::forward(const Maths::Vector& vars) {
    Maths::Vector input = vars;
    for (auto& l: this->layers){
        input = l.forward(input);
    }

    return input;
}

void Network::backward() {

}

void Network::train(std::vector<float> input, std::vector<float> target) {

}




