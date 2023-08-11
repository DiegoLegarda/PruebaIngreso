#include<iostream>
#include"matrices.hpp"
#include"modelo.hpp"
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;

int main(){
    matriz mat1(3,2);
    matriz mat2(2,1);
    matriz mat3(3,3);
    modelo robot(PI/2,PI/2,PI,0.0,80.0,35.0,35.0);
       // matriz mov1=robot.calcular_vector_global(12,23,45);
       // matriz mov2=robot.calcular_vector_Local(12,23,45);
        matriz vel=robot.calculo_jacobiano(12,23,45);
        /*
        mat1.setData({{1, 2},{3, 4},{5, 6}});
        
        mat3.setData({{1, 2 ,5},{3, 4, 7},{5, 6, 8}});

        mat2.setData({{7},{8}});

        matriz mat4 = mat1 * mat2;
        matriz mat5=mat3*mat4;

        //matriz mat3=mat1+mat2;

        std::cout << "Matrix 1:" << std::endl;
        mat1.print();

        std::cout << "Matrix 2:" << std::endl;
        mat2.print();

        std::cout << "Matrix 4:" << std::endl;
        mat3.print();

        std::cout << "Matrix 4:" << std::endl;
        mat4.print();

        std::cout << "Matrix 4:" << std::endl;
        mat5.print();

        */

    return 0;
}