#ifndef MODELO_HPP
#define MODELO_HPP
#include <iostream>
#include "matrices.hpp"
#include <vector>
#include <cmath>

class modelo{

private:
       
        float Aiz;
        float Ade;
        float Biz;
        float Bde;
        float l;
        float Riz;
        float Rde;
      
public:
       
        modelo(float Aiz,float Ade,float Biz,float Bde,float l,float Riz,float Rde): Aiz(Aiz),Ade(Ade),Biz(Biz),Bde(Bde),l(l),Riz(Riz),Rde(Rde){}
        modelo(){};
        ~modelo() {};
        void setAiz (float a){
                this->Aiz =a ;
        }
        void setAde (float b) {
                this->Ade=b;
        }
        void setBiz  (float c) {
                this->Biz=c;
        }
        void setBde(float d ){
                this->Bde=d;
        }
        void setL(float e){
                this->l=e;
        }
        void setRiz (float f){
                this->Riz=f;
        }
        void setRde(float g){
                this->Rde=g;
        }
        matriz  calcular_vector_global(double theta,double v, double w){
                matriz t1(3,2);
                matriz t2(2,1);
                matriz t3(2,1);

                t1.setData({{cos(theta),sin(theta)},{-sin(theta),cos(theta)},{0,1}});
                t1.print();
                t2.setData({{v},{w}});
                t2.print();
                t3=t1*t2;
                printf("\n primera conversion \n");
                t3.print();
                return t3;
        }
        matriz  calcular_vector_Local(double theta,double v, double w){
                matriz t1=calcular_vector_global(theta, v, w);
                matriz t2(3,3);
                t2.setData({{cos(theta),-sin(theta), 0},{-sin(theta),cos(theta),0},{0,0,1}});
                matriz t3=t2*t1;
                printf("\n Segunda conversion \n");
                t3.print();
                return t3;
        }

        matriz calculo_jacobiano(double theta, double v, double w){
                matriz t2=calcular_vector_Local(theta,v, w);
                matriz jac1(2,3);
                matriz jac2(2,2);
                jac1.setData({{sin(Aiz+Biz),-cos(Aiz+Biz),-l*cos(Biz)},{sin(Ade+Bde),-cos(Ade+Bde),-l*cos(Bde)}});
                jac2.setData({{1/Riz,0},{0,-1/Rde}});
                printf("\nmatriz jacobiano\n");
                jac1.print();
                matriz mult1=jac1*t2;
                printf("\n Resultado intermedio \n");
                mult1.print();
                matriz result=jac2*mult1;
                printf("\n Resultado conversion \n");
                result.print();
                return result;
        }


        



                                                        
                                                        
                                                        
};                                                     


        
#endif // MODELO_H