#ifndef MATRICES_HPP
#define MATRICES_HPP
#include <iostream>
#include <vector>

using namespace std;
class matriz{
private: 
    int rows;
    int cols;
    std::vector<std::vector<double>> data;
public:
matriz(int rows, int cols) : rows(rows), cols(cols), data(rows, vector<double>(cols, 0.0)) {}

    void setData(const vector<vector<double>>& newData) {
        if (newData.size() != rows || newData[0].size() != cols) {
            cerr << "Error: Invalid matrix dimensions for setData()" << endl;
            return;
        }
        data = newData;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    matriz operator+(const matriz& other) const {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Error: dimensiones erradas para sumar" << endl;
            return matriz(0, 0);
        }

        matriz result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    matriz operator*(const matriz& other) const {
        if (cols != other.rows) {
            std::cerr << "Error: Matrix dimensions mismatch for multiplication" << std::endl;
            return matriz(0, 0);
        }

        matriz result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                double sum = 0.0;
                for (int k = 0; k < cols; ++k) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }
   
};


#endif // MATRICES_H