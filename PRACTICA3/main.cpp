#include <iostream>
#include <string>
#include "RLE.h"
#include "LZ78.h"
#include <vector>
#include "ENCRIPTACION.h"
#include "Integracion.h"

using namespace std;

int ejercicio1(){
    string texto;
    string comprimido;
    string descomprimido;

    cout << "Ingrese una cadena de texto: ";
    cin >> texto;

    comprimido = comprimirRLE(texto);

    descomprimido = descomprimirRLE(comprimido);

    cout << "\nTexto original: " << texto << endl;
    cout << "Texto comprimido: " << comprimido << endl;
    cout << "Texto descomprimido: " << descomprimido << endl;

    if (texto == descomprimido)
    {
        cout << "El texto recuperado es igual al original" << endl;
    }
    else
    {
        cout << "El texto recuperado es diferente" << endl;
    }

    return 0;
}


int ejercicio2(){
    int capacidadTexto = 500;

    char* textoOriginal = new char[capacidadTexto];

    cout << "Ingrese el texto: ";
    cin >> textoOriginal;


    int cantidadCaracteres = 0;

    while (textoOriginal[cantidadCaracteres] != '\0')
    {
        cantidadCaracteres++;
    }

    int cantidadPares = 0;

    ParLZ78* pares = comprimirLZ78(textoOriginal, cantidadCaracteres,cantidadPares);


    cout << endl;
    cout << "Pares generados" << endl;

    for (int i = 0; i < cantidadPares; i++)
    {
        cout << "("
             << pares[i].indice
             << ", ";

        if (pares[i].caracter == '\0')
        {
            cout << "FIN";
        }
        else
        {
            cout << pares[i].caracter;
        }

        cout << ")" << endl;
    }


    int cantidadReconstruida = 0;

    char* textoReconstruido = descomprimirLZ78(pares, cantidadPares,cantidadReconstruida);


    cout << endl;
    cout << "Texto construido" << endl;

    cout << "Original: " << textoOriginal << endl;
    cout << "Recontruido: " <<textoReconstruido << endl;


    bool correcto = verificarTexto(textoOriginal, textoReconstruido, cantidadCaracteres, cantidadReconstruida);


    cout << endl;
    cout << "Verificacion" << endl;

    if (correcto)
    {
        cout << "El texto reconstruido es IDENTICO al texto original." << endl;
    }
    else
    {
        cout << "el texto reconstruido no es igual al original." << endl;
    }

    liberarPares(pares);

    liberarTexto(textoReconstruido);

    delete[] textoOriginal;

    return 0;
}


int ejercicio3(){
    vector<unsigned char> datos;

    string texto;
    int n;
    int valorclave;

    cout << "Ingrese el texto: ";
    cin >> texto;

    for (int i = 0; i < texto.size(); i++)
    {
        datos.push_back((unsigned char)texto[i]);
    }

    cout << endl;

    do
    {
        cout << "Ingrese el valor de rotacion n (1 - 7): ";
        cin >> n;
    }
    while (n <= 0 || n >= 8);

    do
    {
        cout << "Ingrese la clave K: ";
        cin >> valorclave;
    }
    while (valorclave < 0 || valorclave > 255);

    unsigned char clave = (unsigned char)valorclave;

    vector<unsigned char> datos_encriptados = encriptar(datos, n, clave);

    cout << endl;
    cout << "DATOS ENCRIPTADOS" << endl;

    for (int i = 0; i < datos_encriptados.size(); i++)
    {
        cout << (int)datos_encriptados[i];

        if (i < datos_encriptados.size() - 1)
        {
            cout << " ";
        }
    }

    cout << endl;

    vector<unsigned char> datos_recuperados = desencriptar(datos_encriptados, n, clave);

    cout << endl;
    cout << "DATOS RECUPERADOS" << endl;

    for (int i = 0; i < datos_recuperados.size(); i++)
    {
        cout << (char)datos_recuperados[i];
    }

    cout << endl;

    return 0;
}

int ejercicio4(){
    cout << "INTEGRACION DE COMPRESION Y ENCRIPTACION" << endl;
    cout << endl;

    ejecutarIntegracion();

    return 0;
}



int main()
{
    while(true){
        int x;

        cout << "Ingrese el numero del ejercicio ";
        cin >> x;

        switch(x){
        case 1: ejercicio1();
        break;
        case 2: ejercicio2();
        break;
        case 3: ejercicio3();
        break;
        case 4: ejercicio4();
        break;
        }
    }
}
