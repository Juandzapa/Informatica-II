#include "encriptacion.h"
#include <vector>

using namespace std;

unsigned char rotar_izquierda(unsigned char byte, int n)
{
    return (byte << n) | (byte >> (8 - n));
}

unsigned char rotar_derecha(unsigned char byte, int n)
{
    return (byte >> n) | (byte << (8 - n));
}

vector<unsigned char> encriptar(const vector<unsigned char>& datos, int n, unsigned char clave)
{
    vector<unsigned char> resultado;

    for (int i = 0; i < datos.size(); i++)
    {
        unsigned char byte = datos[i];

        byte = rotar_izquierda(byte, n);

        byte = byte ^ clave;

        resultado.push_back(byte);
    }

    return resultado;
}

vector<unsigned char> desencriptar(const vector<unsigned char>& datos, int n, unsigned char clave)
{
    vector<unsigned char> resultado;

    for (int i = 0; i < datos.size(); i++)
    {
        unsigned char byte = datos[i];

        byte = byte ^ clave;

        byte = rotar_derecha(byte, n);

        resultado.push_back(byte);
    }

    return resultado;
}