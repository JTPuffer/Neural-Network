# Neural Network Implementation

A C++ implementation of a neural network framework with customizable layers and operations.

## Project Structure

The project is organized into the following components:

### Core Components
- `Network`: Main neural network implementation
- `Layer`: Neural network layer implementation
- `Math`: Mathematical utility functions
- `DataReader`: Handles data input and preprocessing

### Operations
The network supports various operations including:
- Weight multiplication
- Bias addition
- Sigmoid activation
- Loss calculation

### Optimization
- Custom optimizer implementation for network training

## Prerequisites

- CMake (version 3.1 or higher)
- C++17 compatible compiler
- Dataset in the `data/numbers` directory

## Building the Project

1. Create a build directory:
```bash
mkdir build
cd build
```

2. Generate build files:
```bash
cmake ..
```

3. Build the project:
```bash
make
```

The executable will be created as `Network` in your build directory.

## Data

The project expects training data in the `data/numbers` directory. The data will be automatically copied to the build directory during compilation.

## Directory Structure

```
.
├── src/
│   ├── main.cpp
│   ├── Layer.cpp
│   ├── Network.cpp
│   ├── DataReader.cpp
│   ├── Optimizer.cpp
│   └── Operations/
│       ├── WeightMultiply.cpp
│       ├── BiasAdd.cpp
│       ├── Sigmoid.cpp
│       ├── Loss.cpp
│       └── Operation.cpp
├── header/
│   ├── Layer.h
│   ├── Math.h
│   ├── Network.h
│   ├── DataReader.h
│   ├── Optimizer.h
│   └── Operations/
│       ├── Operation.h
│       ├── WeightMultiply.h
│       ├── BiasAdd.h
│       ├── Sigmoid.h
│       └── Loss.h
├── data/
│   └── numbers/
└── CMakeLists.txt
```

## Usage

```cpp
// Example usage of the neural network
#include "Network.h"
#include "DataReader.h"

int main() {
    DataReader dataReader = DataReader("numbers/train-images.idx3-ubyte","numbers/train-labels.idx1-ubyte");
    Network bob = Network({Layer(89, 534),Layer(10, 10)} );
    bob.train(dataReader, 200, Loss());
    return 0;
}
```

