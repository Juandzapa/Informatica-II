#include <iostream>
#include "Funciones.h"

using namespace std;

int ejercicio1(){
    int dinero;

    const int denominaciones[10] = {
        50000, 20000, 10000, 5000, 2000,
        1000, 500, 200, 100, 50
    };

    int cantidades[10] = {0};

    cout << "Ingrese la cantidad de dinero: " << endl;
    cin >> dinero;

    calcularcambio(&dinero, denominaciones, cantidades, 10);

    cout << "Combinacion de billetes y monedas:" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << denominaciones[i] << " : " << cantidades[i] << endl;
    }

    cout << "Faltante: " << dinero << endl;

    return 0;
}

int ejercicio3(){
    char cadena1[100];
    char cadena2[100];

    cout << "Ingrese la primera cadena: ";
    cin >> cadena1;

    cout << "Ingrese la segunda cadena: ";
    cin >> cadena2;

    int longitud1 = 0;
    int longitud2 = 0;

    char *p1 = cadena1, *p2 = cadena2;

    while (*p1 != '\0')
    {
        longitud1 = longitud1 + 1;
        p1 = p1 +1;
    }

    while (*p2 != '\0')
    {
        longitud2 = longitud2 + 1;
        p2 = p2 + 1;
    }

    bool iguales = compararcadenas(cadena1, cadena2, longitud1, longitud2);

    if (iguales)
    {
        cout << "Las cadenas son iguales." << endl;
    }
    else
    {
        cout << "Las cadenas son diferentes." << endl;
    }

    return 0;
}

int ejercicio5(){
    int numero;

    cout << "Ingrese un numero entero: ";
    cin >> numero;

    char *cadena = nullptr;

    convertircadena(numero, cadena);

    cout << "El numero convertido a cadena es: " << cadena << endl;

    delete[] cadena;

    return 0;
}

int ejercicio7(){
    char cadena[100];

    cout << "Ingrese una cadena: ";
    cin >> cadena;

    cout << "Original: ";
    imprimircadena(cadena);

    eliminarrepetidos(cadena);

    cout << "Sin repetidos: ";
    imprimircadena(cadena);

    return 0;
}

int ejercicio9(){
    int n;
    char cadena[100];

    cout << "Ingrese el numero de cifras n: ";
    cin >> n;

    cout << "Ingrese la cadena de caracteres numericos: ";
    cin >> cadena;

    cout << "Original: ";
    imprimircadena(cadena);

    int suma = sumarnumeros(cadena, n);

    cout << "Suma: " << suma << endl;

    return 0;
}


int ejercicio11(){
    char sala[15][20];

    iniciarsala(sala);

    int opcion;
    char fila;
    int asiento;

    do
    {
        cout << "RESERVAS CINE" << endl;
        cout << "1. Mostrar sala" << endl;
        cout << "2. Reservar asiento" << endl;
        cout << "3. Cancelar reserva" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: " << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            mostrarsala(sala);
            break;

        case 2:
            cout << "Ingrese la fila (A-O): ";
            cin >> fila;

            if (fila >= 'a' && fila <= 'o')
            {
                fila = fila - 'a' + 'A';
            }

            cout << "Ingrese el numero del asiento (1-20): ";
            cin >> asiento;

            reservarasiento(sala, fila, asiento);
            break;

        case 3:
            cout << "Ingrese la fila (A-O): ";
            cin >> fila;

            if (fila >= 'a' && fila <= 'o')
            {
                fila = fila - 'a' + 'A';
            }

            cout << "Ingrese el numero del asiento (1-20): ";
            cin >> asiento;

            cancelarasiento(sala, fila, asiento);
            break;

        case 4:
            cout << "Programa finalizado" << endl;
            break;

        default:
            cout << "Opcion no valida" << endl;
        }

    } while (opcion != 4);

    return 0;
}


int ejercicio13(){
        const int filas = 6;
        const int columnas = 8;

        int matriz[filas][columnas] =
            {
                {0, 3, 4, 0, 0, 0, 6, 8},
                {5, 13, 6, 0, 0, 0, 2, 3},
                {2, 6, 2, 7, 3, 0, 10, 0},
                {0, 0, 4, 15, 4, 1, 6, 0},
                {0, 0, 7, 12, 6, 9, 10, 4},
                {5, 0, 6, 10, 6, 4, 8, 0}
            };

        int cantidadestrellas = contarestrellas(matriz);

        cout << "Numero de estrellas encontradas: "
             << cantidadestrellas << endl;

        return 0;
}


int ejercicio15(){
    int A[4];
    int B[4];
    int C[4];

    cout << "Ingrese el rectangulo A:" << endl;

    cout << "Coordenada x: ";
    cin >> A[0];

    cout << "Coordenada y: ";
    cin >> A[1];

    cout << "Ancho: ";
    cin >> A[2];

    cout << "Alto: ";
    cin >> A[3];


    cout << endl;

    cout << "Ingrese el rectangulo B:" << endl;

    cout << "Coordenada x: ";
    cin >> B[0];

    cout << "Coordenada y: ";
    cin >> B[1];

    cout << "Ancho: ";
    cin >> B[2];

    cout << "Alto: ";
    cin >> B[3];


    interseccion(A, B, C);


    cout << endl;

    cout << "Rectangulo A: {"
         << A[0] << ", "
         << A[1] << ", "
         << A[2] << ", "
         << A[3] << "}" << endl;

    cout << "Rectangulo B: {"
         << B[0] << ", "
         << B[1] << ", "
         << B[2] << ", "
         << B[3] << "}" << endl;

    cout << "Rectangulo interseccion C: {"
         << C[0] << ", "
         << C[1] << ", "
         << C[2] << ", "
         << C[3] << "}" << endl;


    cout << &C[0] << endl;

    return 0;
}



int ejercicio17(){
    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    int resultado = sumaamigables(&numero);

    cout << "El resultado de la suma es: " << resultado << "." << endl;

    return 0;
}

int main()
{
    int x;

        while(true){
        cout << "Ingrese un numero impar desde el 1 " << endl;
        cin >> x;
        switch(x){
        case 1: ejercicio1();
        break;
        case 3: ejercicio3();
        break;
        case 5: ejercicio5();
        break;
        case 7: ejercicio7();
        break;
        case 9: ejercicio9();
        break;
        case 11: ejercicio11();
        break;
        case 13: ejercicio13();
        break;
        case 15: ejercicio15();

        break;
        case 17: ejercicio17();
        break;
        }
    }
        return 0;
}