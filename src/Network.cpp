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

void Network::train(DataReader& reader, size_t batch_size, const Loss& loss) {
    auto batch = reader.getBatch(batch_size);
    while(!batch.empty()) {

        for (const auto& [input, target] : batch) {
            Maths::Vector predictions = forward(input);

            auto maxElementIter = std::max_element(predictions.begin(), predictions.end());
            int maxIndex = std::distance(predictions.begin(), maxElementIter);

            auto maxlabeliter = std::max_element(target.begin(), target.end());
            int maxlabel = std::distance(target.begin(), maxlabeliter);


            std::cout << "image value: " << maxIndex << " real value " << maxlabel << std::endl;


            this->backward(loss.backward(predictions, target));

            for (auto &l: this->layers) {
                l.train(0.1);
            }

        }
        batch = reader.getBatch(batch_size);
    }


}






