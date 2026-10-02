#include "RLE.h"
#include <string>
#include <cctype>

using namespace std;

string comprimirRLE(const string &texto)
{
    string comprimido = "";

    if (texto.empty())
    {
        return comprimido;
    }

    int cantidad = 1;

    for (int i = 1; i <= texto.length(); i++)
    {
        if (i < texto.length() && texto[i] == texto[i - 1])
        {
            cantidad = cantidad + 1;
        }
        else
        {
            while (cantidad > 9)
            {
                comprimido = comprimido + "9";
                comprimido = comprimido + texto[i - 1];

                cantidad = cantidad - 9;
            }

            if (cantidad > 0)
            {
                comprimido = comprimido + to_string(cantidad);
                comprimido = comprimido + texto[i - 1];
            }

            cantidad = 1;
        }
    }

    return comprimido;
}

string descomprimirRLE(const string &textoComprimido)
{
    string original = "";

    for (int i = 0; i < textoComprimido.length(); i += 2)
    {
        int cantidad = textoComprimido[i] - '0';
        char caracter = textoComprimido[i + 1];

        for (int j = 0; j < cantidad; j++)
        {
            original = original + caracter;
        }
    }

    return original;
}

