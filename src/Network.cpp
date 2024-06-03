//
// Created by matthew on 5/29/24.
//

#include <utility>

#include "../header/Network.h"


Network::Network(std::vector<Layer> layers) : layers(std::move(layers)){
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

void Network::train(std::vector<Maths::Vector> input, std::vector<float> target) {
    Maths::Vector predictions = forward(input[0]);

}






