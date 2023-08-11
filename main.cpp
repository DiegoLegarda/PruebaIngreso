#include<iostream>
#include"matrices.hpp"
#include"modelo.hpp"
#include"lectura.hpp"
#include <cmath>
#include <sstream>
#include <fstream>
#define PI 3.14159265358979323846

using namespace std;

int main(){
    float Aiz,Ader,Biz,Bder,l,Riz,Rder;
    Aiz=PI/2;
    Ader=-PI/2;
    Biz = PI;
    Bder=0;
    l=80;
    Riz=35;
    Rder=35;
    std::vector<std::vector<double>> matrixData;

    
    //modelo robot(Aiz,Ader,Biz,Bder,l,Riz,Rder);

   //     matriz vel=robot.calculo_jacobiano(0,10,80);       

    return 0;
}

int lectura(){
std::ifstream inputFile("datos.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<double> row;
        std::istringstream iss(line);
        double value;
        char comma;
        while (iss >> value >> comma) {
            row.push_back(value);
        }
        matrixData.push_back(row);
    }

    inputFile.close();

    std::cout << "Datos leídos desde el archivo:" << std::endl;
    for (const auto& row : matrixData) {
        for (const double value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

}

