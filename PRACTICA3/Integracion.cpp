#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

#include "RLE.h"
#include "LZ78.h"
#include "ENCRIPTACION.h"
#include "Integracion.h"

using namespace std;

int ejecutarIntegracion()
{
    try
    {
        string texto;
        int metodo;
        int n;
        int valorClave;

        cout << "Ingrese el texto: ";
        cin >> texto;

        cout << endl;
        cout << "Seleccione el metodo de compresion:" << endl;
        cout << "1. RLE" << endl;
        cout << "2. LZ78" << endl;
        cout << "Opcion: ";
        cin >> metodo;

        if (metodo != 1 && metodo != 2)
        {
            throw invalid_argument("Metodo de compresion no valido.");
        }

        cout << endl;

        cout << "Ingrese el valor de rotacion n (1 - 7): ";
        cin >> n;

        if (n < 1 || n > 7)
        {
            throw invalid_argument("El valor de rotacion debe estar entre 1 y 7.");
        }

        cout << "Ingrese la clave K (0 - 255): ";
        cin >> valorClave;

        if (valorClave < 0 || valorClave > 255)
        {
            throw invalid_argument("La clave debe estar entre 0 y 255.");
        }

        unsigned char clave = (unsigned char)valorClave;

        vector<unsigned char> datosComprimidos;

        if (metodo == 1)
        {
            string comprimido = comprimirRLE(texto);

            for (int i = 0; i < comprimido.size(); i++)
            {
                datosComprimidos.push_back((unsigned char)comprimido[i]);
            }

            cout << endl;
            cout << "Texto comprimido con RLE: ";
            cout << comprimido << endl;
        }
        else
        {
            int cantidadCaracteres = texto.size();
            int cantidadPares = 0;

            char* textoOriginal = new char[cantidadCaracteres + 1];

            for (int i = 0; i < cantidadCaracteres; i++)
            {
                textoOriginal[i] = texto[i];
            }

            textoOriginal[cantidadCaracteres] = '\0';

            ParLZ78* pares = comprimirLZ78(textoOriginal, cantidadCaracteres, cantidadPares);

            cout << endl;
            cout << "Pares generados por LZ78:" << endl;

            for (int i = 0; i < cantidadPares; i++)
            {
                cout << "("<< pares[i].indice<< ", ";

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

            for (int i = 0; i < cantidadPares; i++)
            {
                unsigned char byte1 =(unsigned char)(pares[i].indice >> 8);

                unsigned char byte2 =(unsigned char)(pares[i].indice & 255);

                unsigned char byte3 =(unsigned char)pares[i].caracter;

                datosComprimidos.push_back(byte1);
                datosComprimidos.push_back(byte2);
                datosComprimidos.push_back(byte3);
            }

            liberarPares(pares);
            delete[] textoOriginal;
        }

        vector<unsigned char> datosEncriptados = encriptar(datosComprimidos, n, clave);

        ofstream archivo("datos_encriptados.bin", ios::binary);

        if (!archivo)
        {
            throw runtime_error("No se pudo crear el archivo.");
        }

        for (int i = 0; i < datosEncriptados.size(); i++)
        {
            archivo.put((char)datosEncriptados[i]);
        }

        archivo.close();

        cout << endl;

        ifstream archivoEntrada("datos_encriptados.bin", ios::binary);

        if (!archivoEntrada)
        {
            throw runtime_error("No se pudo abrir el archivo.");
        }

        vector<unsigned char> datosLeidos;

        char byte;

        while (archivoEntrada.get(byte))
        {
            datosLeidos.push_back((unsigned char)byte);
        }

        archivoEntrada.close();

        vector<unsigned char> datosDesencriptados = desencriptar(datosLeidos, n, clave);

        string textoFinal;

        if (metodo == 1)
        {
            string comprimido;

            for (int i = 0; i < datosDesencriptados.size(); i++)
            {
                comprimido = comprimido + (char)datosDesencriptados[i];
            }

            textoFinal = descomprimirRLE(comprimido);
        }
        else
        {
            int cantidadPares = datosDesencriptados.size() / 3;

            ParLZ78* pares = new ParLZ78[cantidadPares];

            int posicion = 0;

            for (int i = 0; i < cantidadPares; i++)
            {
                int parte1 = (int)datosDesencriptados[posicion];

                int parte2 = (int)datosDesencriptados[posicion + 1];

                pares[i].indice = parte1 * 256 + parte2;

                pares[i].caracter = (char)datosDesencriptados[posicion + 2];

                posicion += 3;
            }

            int cantidadReconstruida = 0;

            char* reconstruido = descomprimirLZ78(pares, cantidadPares,cantidadReconstruida);

            for (int i = 0; i < cantidadReconstruida; i++)
            {
                textoFinal += reconstruido[i];
            }

            liberarTexto(reconstruido);
            delete[] pares;
        }

        ofstream archivoFinal("texto_final.txt");

        if (!archivoFinal)
        {
            throw runtime_error("No se pudo crear el archivo final.");
        }

        archivoFinal << textoFinal;
        archivoFinal.close();

        cout << endl;
        cout << "Texto final: " << textoFinal << endl;

        cout << endl;

        if (texto == textoFinal)
        {
            cout << "VERIFICACION" << endl;
            cout << "El texto final es igual al original."<< endl;
        }
        else
        {
            cout << "VERIFICACION" << endl;
            cout << "El texto final es diferente al original." << endl;
        }
    }
    catch (const exception& e)
    {
        cout << endl;
        cout << "ERROR: " << e.what() << endl;

        return 1;
    }

    return 0;
}