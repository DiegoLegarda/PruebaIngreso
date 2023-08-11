#ifndef LECTURA_HPP
#define LECTURA_HPP
#include <iostream>
#include "matrices.hpp"
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;
 class lectura{
    private:
        string nombre;

    public :
    lectura(string nombre):nombre(nombre){};
    int lectura_datos(std::vector<std::vector<double>>& data){
        std::ifstream inputFile("datos.txt");

        if (!inputFile.is_open()) {
            std::cerr << "Error al abrir el archivo." << std::endl;
            return 0;
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
            data.push_back(row);
        }
        inputFile.close();
        return 0;
        
    }       


 };




#endif // MODELO_H