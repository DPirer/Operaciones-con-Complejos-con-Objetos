#include <iostream>
#include <stdlib.h>

using namespace std;

// CREAMOS LAS CLASES
class Complejo{
    private:
        float real;
        float imaginaria;

    public:
        // Constructor
        Complejo (float, float);

        // Métodos
        void suma(Complejo, Complejo);
        void resta(Complejo, Complejo);
        void multiplicacion(Complejo, Complejo);
        void division(Complejo, Complejo);
};


// DEFINIMOS EL CONSTRUCTOR
Complejo::Complejo(float _real,float _imaginaria){
    this -> real = _real;
    this -> imaginaria = _imaginaria;
}


// DEFINIMOS LAS FUNCIONES
void Complejo::suma(Complejo z1, Complejo z2){
    Complejo z(0,0);
    z.real = z1.real + z2.real;
    z.imaginaria = z1.imaginaria + z2.imaginaria;

    cout<<"\nLa suma de los dos complejos es: "<<z.real<<", "<<z.imaginaria<<"i"<<endl<<endl;
}

void Complejo::resta(Complejo z1, Complejo z2){
    Complejo z(0,0);
    z.real = z1.real - z2.real;
    z.imaginaria = z1.imaginaria - z2.imaginaria;

    cout<<"La resta de los dos complejos es: "<<z.real<<", "<<z.imaginaria<<"i"<<endl<<endl;
}

void Complejo::multiplicacion(Complejo z1, Complejo z2){
    Complejo z(0,0);
    z.real = z1.real * z2.real - z1.imaginaria * z2.imaginaria;
    z.imaginaria = z1.real * z2.imaginaria + z1.imaginaria * z2.real;

    cout<<"La multiplicacion de los dos complejos es: "<<z.real<<", "<<z.imaginaria<<"i"<<endl<<endl;
}

void Complejo::division(Complejo z1, Complejo z2){

    if((z2.real == 0) && (z2.imaginaria == 0)){
        try {
            throw 69;
        } catch (int error) {
            cout<<"Error: "<<error<<". Division por cero."<<endl<<endl;
        }
    }
    else{
        Complejo z(0,0);
        z.real = (z1.real * z2.real + z1.imaginaria * z2.imaginaria) / (z2.real * z2.real + z2.imaginaria * z2.imaginaria);
        z.imaginaria = (z1.imaginaria * z2.real - z1.real * z2.imaginaria) / (z2.real * z2.real + z2.imaginaria * z2.imaginaria);

        cout<<"La division de los dos complejos es: "<<z.real<<", "<<z.imaginaria<<"i"<<endl<<endl;
    }
}

// MAIN
int main()
{
    float real1, imaginaria1, real2, imaginaria2;


    // Pedimos al usuario que introduzca los datos
    cout<<"Introduce la parte real del primer complejo: "; cin>>real1;
    cout<<"Introduce la parte imaginaria del primer complejo: "; cin>>imaginaria1;
    cout<<"Introduce la parte real del segundo complejo: "; cin>>real2;
    cout<<"Introduce la parte imaginaria del segundo complejo: "; cin>>imaginaria2;

    // Creamos dos objetos números complejos
    Complejo z1(real1, imaginaria1);
    Complejo z2(real2, imaginaria2);

    // Y llamamos a las funciones de la case Complejo
    z1.suma(z1,z2);
    z1.resta(z1,z2);
    z1.multiplicacion(z1,z2);
    z1.division(z1,z2);

    system("pause");
    return 0;
}

