#include "LZ78.h"
#include <iostream>

using namespace std;

int buscarEntrada(const EntradaDiccionario* diccionario, int cantidadEntradas, int prefijo, char caracter)
{
    for (int i = 0; i < cantidadEntradas; i++)
    {
        if (diccionario[i].prefijo == prefijo && diccionario[i].caracter == caracter)
        {
            return i + 1;
        }
    }

    return 0;
}

void aumentarDiccionario(EntradaDiccionario*& diccionario, int& capacidad)
{
    int nuevaCapacidad = capacidad * 2;

    EntradaDiccionario* nuevoDiccionario = new EntradaDiccionario[nuevaCapacidad];

    for (int i = 0; i < capacidad; i++)
    {
        nuevoDiccionario[i] = diccionario[i];
    }

    delete[] diccionario;

    diccionario = nuevoDiccionario;
    capacidad = nuevaCapacidad;
}

void aumentarPares(ParLZ78*& pares, int& capacidad)
{
    int nuevaCapacidad = capacidad * 2;

    ParLZ78* nuevosPares = new ParLZ78[nuevaCapacidad];

    for (int i = 0; i < capacidad; i++)
    {
        nuevosPares[i] = pares[i];
    }

    delete[] pares;

    pares = nuevosPares;
    capacidad = nuevaCapacidad;
}

ParLZ78* comprimirLZ78(const char* texto, int cantidadCaracteres, int& cantidadPares)
{
    cantidadPares = 0;

    int capacidadDiccionario = 4;

    EntradaDiccionario* diccionario = new EntradaDiccionario[capacidadDiccionario];

    int cantidadEntradas = 0;

    int capacidadPares = 4;

    ParLZ78* pares = new ParLZ78[capacidadPares];

    int posicion = 0;

    while (posicion < cantidadCaracteres)
    {
        int prefijo = 0;

        int nuevaPosicion = posicion;

        while (nuevaPosicion < cantidadCaracteres)
        {
            char caracterActual = texto[nuevaPosicion];

            int indiceEncontrado = buscarEntrada(diccionario, cantidadEntradas, prefijo, caracterActual);

            if (indiceEncontrado == 0)
            {
                break;
            }

            prefijo = indiceEncontrado;
            nuevaPosicion = nuevaPosicion + 1;
        }

        if (nuevaPosicion < cantidadCaracteres)
        {
            char caracterNuevo = texto[nuevaPosicion];

            if (cantidadEntradas == capacidadDiccionario)
            {
                aumentarDiccionario(diccionario, capacidadDiccionario);
            }

            diccionario[cantidadEntradas].prefijo = prefijo;
            diccionario[cantidadEntradas].caracter = caracterNuevo;

            cantidadEntradas = cantidadEntradas + 1;

            if (cantidadPares == capacidadPares)
            {
                aumentarPares(pares, capacidadPares);
            }

            pares[cantidadPares].indice = prefijo;
            pares[cantidadPares].caracter = caracterNuevo;

            cantidadPares = cantidadPares + 1;

            posicion = nuevaPosicion + 1;
        }
        else
        {
            if (cantidadPares == capacidadPares)
            {
                aumentarPares(pares, capacidadPares);
            }

            pares[cantidadPares].indice = prefijo;
            pares[cantidadPares].caracter = '\0';

            cantidadPares = cantidadPares + 1;

            posicion = nuevaPosicion;
        }
    }

    delete[] diccionario;

    return pares;
}

char* descomprimirLZ78(const ParLZ78* pares, int cantidadPares, int& cantidadCaracteres)
{
    cantidadCaracteres = 0;

    int capacidadDiccionario = 4;

    EntradaDiccionario* diccionario = new EntradaDiccionario[capacidadDiccionario];

    int cantidadEntradas = 0;

    int capacidadTexto = 16;

    char* textoReconstruido = new char[capacidadTexto];

    for (int i = 0; i < cantidadPares; i++)
    {
        int indice = pares[i].indice;
        char caracter = pares[i].caracter;

        int longitudFrase = 0;

        int temporal = indice;

        while (temporal != 0)
        {
            longitudFrase = longitudFrase + 1;

            temporal = diccionario[temporal - 1].prefijo;
        }

        if (caracter != '\0')
        {
            longitudFrase = longitudFrase + 1;
        }

        while (
            cantidadCaracteres + longitudFrase + 1
            >= capacidadTexto
            )
        {
            int nuevaCapacidad = capacidadTexto * 2;

            char* nuevoTexto = new char[nuevaCapacidad];

            for (int j = 0; j < cantidadCaracteres; j++)
            {
                nuevoTexto[j] = textoReconstruido[j];
            }

            delete[] textoReconstruido;

            textoReconstruido = nuevoTexto;
            capacidadTexto = nuevaCapacidad;
        }

        int longitudPrefijo = longitudFrase;

        if (caracter != '\0')
        {
            longitudPrefijo = longitudPrefijo - 1;
        }

        char* frase = new char[longitudFrase + 1];

        int posicionFrase = longitudPrefijo;

        if (caracter != '\0')
        {
            frase[posicionFrase] = caracter;
        }

        temporal = indice;

        while (temporal != 0)
        {
            EntradaDiccionario entrada = diccionario[temporal - 1];

            posicionFrase = posicionFrase - 1;

            frase[posicionFrase] = entrada.caracter;

            temporal = entrada.prefijo;
        }

        frase[longitudFrase] = '\0';

        for (int j = 0; j < longitudFrase; j++)
        {
            textoReconstruido[cantidadCaracteres] = frase[j];

            cantidadCaracteres = cantidadCaracteres + 1;
        }

        delete[] frase;

        if (caracter != '\0')
        {
            if (cantidadEntradas == capacidadDiccionario)
            {
                aumentarDiccionario(
                    diccionario,
                    capacidadDiccionario
                    );
            }

            diccionario[cantidadEntradas].prefijo = indice;

            diccionario[cantidadEntradas].caracter = caracter;

            cantidadEntradas = cantidadEntradas + 1;
        }
    }

    textoReconstruido[cantidadCaracteres] = '\0';

    delete[] diccionario;

    return textoReconstruido;
}

bool verificarTexto(const char* original, const char* reconstruido, int cantidadCaracteresOriginal, int cantidadCaracteresReconstruido)
{
    if (cantidadCaracteresOriginal != cantidadCaracteresReconstruido)
    {
        return false;
    }

    for (int i = 0; i < cantidadCaracteresOriginal; i++)
    {
        if (original[i] != reconstruido[i])
        {
            return false;
        }
    }

    return true;
}

void liberarPares(ParLZ78*& pares)
{
    delete[] pares;
    pares = nullptr;
}

void liberarTexto(char*& texto)
{
    delete[] texto;
    texto = nullptr;
}