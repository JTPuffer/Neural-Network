#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

#ifndef Maths_H
#define Maths_H

namespace Maths {

    template<typename T>
    class MathVector : public std::vector<T> {
    public:
        using std::vector<T>::vector; // Inherit constructors

        // Addition
        MathVector<T> operator+(const MathVector<T>& other) const {
            if (this->size() != other.size()) {
                throw std::invalid_argument("Vectors must be of the same size");
            }
            MathVector<T> result(this->size());
            for (size_t i = 0; i < this->size(); ++i) {
                result[i] = (*this)[i] + other[i];
            }
            return result;
        }
        MathVector<T>& operator+=(const MathVector<T> &other) {
            if (this->size() != other.size()) {
                throw std::invalid_argument("Vectors must be of the same size");
            }

            for (size_t i = 0; i < this->size(); ++i) {
                (*this)[i] = (*this)[i] + other[i];
            }
            return *this;
        }
        // Subtraction
        MathVector<T> operator-(const MathVector<T>& other) const {
            if (this->size() != other.size()) {
                throw std::invalid_argument("Vectors must be of the same size");
            }
            MathVector<T> result(this->size());
            for (size_t i = 0; i < this->size(); ++i) {
                result[i] = (*this)[i] - other[i];
            }
            return result;
        }

        // Scalar multiplication
        MathVector<T> operator*(const T& scalar) const {
            MathVector<T> result(this->size());
            for (size_t i = 0; i < this->size(); ++i) {
                result[i] = (*this)[i] * scalar;
            }
            return result;
        }



        // Print the vector
        void print() const {
            for (const auto& value : *this) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    };

    template<typename T>
    class MathsMatrix {
    private:
        std::vector<std::vector<T>> data;
        size_t rows{}, cols{};

    public:
        // Constructors
        MathsMatrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
            data.resize(rows, std::vector<T>(cols, 0));
        }
        MathsMatrix() = default;
        explicit MathsMatrix(const std::vector<std::vector<T>>& values)
                : rows(values.size()), cols(values[0].size()), data(values) {}

        // Access elements
        T& operator()(size_t i, size_t j) {
            return data[i][j];
        }

        const T& operator()(size_t i, size_t j) const {
            return data[i][j];
        }

        // Addition
        MathsMatrix operator+(const MathsMatrix& other) const {
            if (rows != other.rows || cols != other.cols) {
                throw std::invalid_argument("Matrices must have the same dimensions for addition");
            }
            MathsMatrix result(rows, cols);
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    result(i, j) = data[i][j] + other(i, j);
                }
            }
            return result;
        }

        // Subtraction
        MathsMatrix operator-(const MathsMatrix& other) const {
            if (rows != other.rows || cols != other.cols) {
                throw std::invalid_argument("Matrices must have the same dimensions for subtraction");
            }
            MathsMatrix result(rows, cols);
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    result(i, j) = data[i][j] - other(i, j);
                }
            }
            return result;
        }

        // Scalar multiplication
        MathsMatrix operator*(T scalar) const {
            MathsMatrix result(rows, cols);
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    result(i, j) = data[i][j] * scalar;
                }
            }
            return result;
        }

        // MathsMatrix multiplication
        MathsMatrix operator*(const MathsMatrix& other) const {
            if (cols != other.rows) {
                throw std::invalid_argument("Matrices must have compatible dimensions for multiplication");
            }
            MathsMatrix result(rows, other.cols);
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < other.cols; ++j) {
                    for (size_t k = 0; k < cols; ++k) {
                        result(i, j) += data[i][k] * other(k, j);
                    }
                }
            }
            return result;
        }

        MathVector<T> operator*(const MathVector<T>& vec) const {
            if (cols != vec.size()) {
                throw std::invalid_argument("Matrix columns must match vector size for multiplication");
            }
            MathVector<T> result(rows, 0);
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    result[i] += data[i][j] * vec[j];
                }
            }
            return result;
        }


        // Transpose
        [[nodiscard]] MathsMatrix transpose() const {
            MathsMatrix result(cols, rows);
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    result(j, i) = data[i][j];
                }
            }
            return result;
        }

        // Print the matrix
        void print() const {
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    std::cout << data[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        [[nodiscard]] size_t getRows() const {
            return rows;
        }

        [[nodiscard]] size_t getCols() const {
            return cols;
        }
    };



    inline MathVector<double> dotProduct(const Maths::MathsMatrix<double>& one, const Maths::MathVector<double>& two) {
        if (one.getCols() != two.size()) {
            std::cerr << "Error: The number of columns in the matrix must be equal to the size of the vector for dot product calculation." << std::endl;
            return {};
        }

        Maths::MathVector<double> result(one.getRows());
        for (size_t i = 0; i < one.getRows(); ++i) {
            double sum = 0.0;
            for (size_t j = 0; j < one.getCols(); ++j) {
                sum += one(i, j) * two[j];
            }
            result[i] = sum;
        }
        return result;
    }
    // Typedef for convenience
    typedef MathVector<double> Vector;
    typedef MathsMatrix<double> Matrix;
}

#endif
