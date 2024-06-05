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

void Network::backward(Maths::MathVector<double> gradient) {

    for (auto it = this->layers.rbegin(); it != this->layers.rend(); ++it) {
        gradient = it->backward(gradient);
    }

}

void Network::train(std::vector<Maths::Vector>& input, std::vector<Maths::Vector>& target, Loss loss) {
    if(input.size() != target.size()){
        throw std::invalid_argument("labels and data must be of the same size");
    }

    for (size_t i = 0; i < input.size(); ++i) {
        //double completionPercentage = static_cast<double>(i + 1) / input.size() * 100.0;
        //std::cout << "Completion: " << completionPercentage << "%" << std::endl;



        Maths::Vector predictions = forward(input[i]);

        auto maxElementIter = std::max_element(predictions.begin(), predictions.end());
        int maxIndex = std::distance(predictions.begin(), maxElementIter);

        auto maxlabeliter = std::max_element(target[i].begin(), target[i].end());
        int maxlabel = std::distance(target[i].begin(), maxlabeliter);


        std::cout << "image value: " << maxIndex << " real value "<< maxlabel <<std::endl;
        //Maths::Vector  bob = loss.forwould(predictions,target[0]);

        this->backward(loss.backward(predictions, target[i]));

        for (auto& l: this->layers){
            l.train(0.1);
        }

    }



}






