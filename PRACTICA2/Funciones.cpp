#include "Funciones.h"
#include <iostream>
using namespace std;
void calcularcambio(int *dinero, const int denominaciones[], int cantidades[], int tamano){

    for (int i = 0; i < tamano; i++)
    {
        cantidades[i] = *dinero / denominaciones[i];

        *dinero = *dinero % denominaciones[i];
    }
}

bool compararcadenas(const char *cadena1, const char *cadena2,int longitud1, int longitud2)
{
    if (longitud1 != longitud2)
    {
        return false;
    }

    for (int i = 0; i < longitud1; i++)
    {
        if (*(cadena1 + i) != *(cadena2 + i))
        {
            return false;
        }
    }

    return true;
}

void convertircadena(int numero, char *&cadena)
{
    bool negativo = false;

    if (numero < 0)
    {
        negativo = true;
        numero = -numero;
    }

    int cantidad = 0;
    int temporal = numero;

    if (temporal == 0)
    {
        cantidad = 1;
    }
    else
    {
        while (temporal > 0)
        {
            cantidad = cantidad + 1;
            temporal = temporal / 10;
        }
    }

    if (negativo)
    {
        cantidad = cantidad + 1;
    }

    cadena = new char[cantidad + 1];

    int posicion = 0;

    if (negativo)
    {
        cadena[0] = '-';
        posicion = 1;
    }

    if (numero == 0)
    {
        cadena[0] = '0';
        cadena[1] = '\0';
        return;
    }

    while (numero > 0)
    {
        int digito = numero % 10;

        cadena[posicion] = '0' + digito;

        posicion = posicion + 1;
        numero = numero / 10;
    }

    cadena[posicion] = '\0';

    int inicio = 0;
    int fin = posicion - 1;

    if (negativo)
    {
        inicio = 1;
    }

    while (inicio < fin)
    {
        char temporalCaracter = cadena[inicio];

        cadena[inicio] = cadena[fin];

        cadena[fin] = temporalCaracter;

        inicio = inicio + 1;
        fin = fin - 1;
    }
}


void eliminarrepetidos(char *cadena)
{
    char *actual = cadena;

    while (*actual != '\0')
    {
        char *comparar = actual + 1;

        while (*comparar != '\0')
        {
            if (*actual == *comparar)
            {
                char *mover = comparar;

                while (*mover != '\0')
                {
                    *mover = *(mover + 1);
                    mover = mover + 1;
                }
            }
            else
            {
                comparar = comparar + 1;
            }
        }

        actual = actual + 1;
    }
}

void imprimircadena(const char *cadena){
    cout << cadena << " " << endl;
}

int longitudcadena(const char *cadena)
{
    int longitud = 0;

    const char *p = cadena;

    while (*p != '\0')
    {
        longitud = longitud + 1;
        p = p + 1;
    }

    return longitud;
}

int convertirnumero(const char *cadena, int inicio, int cantidad)
{
    int numero = 0;

    const char *p = cadena + inicio;

    for (int i = 0; i < cantidad; i++)
    {
        numero = numero * 10 + (*p - '0');
        p = p + 1;
    }

    return numero;
}

int sumarnumeros(const char *cadena, int n)
{

        int longitud = longitudcadena(cadena);

        int sobrantes = longitud % n;

        int suma = 0;

        int posicion = 0;

        if (sobrantes != 0)
        {
            int numero = convertirnumero(cadena, 0, sobrantes);

            suma = suma + numero;

            posicion = sobrantes;
        }

        while (posicion < longitud)
        {
            int numero = convertirnumero(cadena, posicion, n);

            suma = suma + numero;

            posicion = posicion + n;
        }

        return suma;
    }


    // Ejercicio 11


 void iniciarsala(char (*sala)[20])
{
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                *(*(sala + i) + j) = '-';
            }
        }
 }


 void mostrarsala(const char (*sala)[20])
 {
     cout << "  ";

     for (int j = 0; j < 20; j++)
     {
         cout << j + 1 << " ";
     }

     cout << endl;

     for (int i = 0; i < 15; i++)
     {
         cout << char('A' + i) << " ";

         for (int j = 0; j < 20; j++)
         {
             cout << *(*(sala + i) + j) << "  ";
         }

         cout << endl;
     }
 }


 void reservarasiento(char (*sala)[20], char fila, int asiento)
 {
     int indicefila = fila - 'A';
     int indiceasiento = asiento - 1;

     if (indicefila < 0 || indicefila >= 15 || indiceasiento < 0 || indiceasiento >= 20)
     {
         cout << "La fila o el asiento no son validos" << endl;
         return;
     }

     char *p = *(sala + indicefila) + indiceasiento;

     if (*p == '+')
     {
         cout << "El asiento ya reservado" << endl;
     }
     else
     {
         *p = '+';
         cout << "Reserva realizada" << endl;
     }
 }

 void cancelarasiento(char (*sala)[20], char fila, int asiento)
 {
     int indicefila = fila - 'A';
     int indiceasiento = asiento - 1;

     if (indicefila < 0 || indicefila >= 15 ||indiceasiento < 0 || indiceasiento >= 20)
     {
         cout << "La fila o el asiento no son validos" << endl;
         return;
     }

     char *p = *(sala + indicefila) + indiceasiento;

     if (*p == '-')
     {
         cout << "El asiento ya estaba disponible" << endl;
     }
     else
     {
         *p = '-';
         cout << "Cancelacion realizada" << endl;
     }
 }



 int contarestrellas(const int (*matriz)[8])
 {
     int estrellas = 0;

     for (int i = 1; i < 5; i++)
     {
         for (int j = 1; j < 7; j++)
         {
             int suma = *(*(matriz + i) + j) + *(*(matriz + i) + (j - 1)) + *(*(matriz + i) + (j + 1))
                        + *(*(matriz + (i - 1)) + j) + *(*(matriz + (i + 1)) + j);

             double promedio = suma / 5.0;

             if (promedio > 6)
             {
                 estrellas = estrellas + 1;
             }
         }
     }

     return estrellas;
 }



 void interseccion(const int *A, const int *B, int (&C)[4])
 {
     int izquierda = (A[0] > B[0]) ? A[0] : B[0];
     int arriba = (A[1] > B[1]) ? A[1] : B[1];

     int derechaA = A[0] + A[2];
     int derechaB = B[0] + B[2];

     int abajoA = A[1] + A[3];
     int abajoB = B[1] + B[3];

     int derecha = (derechaA < derechaB) ? derechaA : derechaB;
     int abajo = (abajoA < abajoB) ? abajoA : abajoB;

     if (izquierda < derecha && arriba < abajo)
     {
         C[0] = izquierda;
         C[1] = arriba;
         C[2] = derecha - izquierda;
         C[3] = abajo - arriba;
     }
     else
     {
         C[0] = 0;
         C[1] = 0;
         C[2] = 0;
         C[3] = 0;
     }
 }


 // Ejercicio 17
 int sumadivisores(const int *numero)
 {
     int suma = 0;

     for (int i = 1; i < *numero; i++)
     {
         if (*numero % i == 0)
         {
             suma = suma + i;
         }
     }

     return suma;
 }

 bool sonamigables(const int *a, const int *b)
 {
     if (*a == *b)
     {
         return false;
     }

     int sumaA = sumadivisores(a);
     int sumaB = sumadivisores(b);

     return sumaA == *b && sumaB == *a;
 }

 int sumaamigables(const int *limite)
 {
     int suma = 0;

     for (int i = 1; i < *limite; i++)
     {
         int sumadedivisores = sumadivisores(&i);

         if (sumadedivisores > i && sumadedivisores < *limite)
         {
             int pareja = sumadedivisores;

             if (sonamigables(&i, &pareja))
             {
                 suma = suma + i;
                 suma = suma + pareja;
             }
         }
     }

     return suma;
 }

