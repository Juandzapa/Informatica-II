#ifndef FUNCIONES_H
#define FUNCIONES_H

void calcularcambio(int *dinero, const int denominaciones[], int cantidades[], int tamano); //Ejericio 1

bool compararcadenas(const char *cadena1, const char *cadena2,int longitud1, int longitud2); //Ejercicio 3

void convertircadena(int numero, char *&cadena); //Ejercicio 5

void eliminarrepetidos(char *cadena); //Ejercicio 7
void imprimircadena(const char *cadena);  //Ejercicio 7 y 9

int longitudcadena(const char *cadena); //Ejercicio 9
int convertirnumero(const char *cadena, int inicio, int cantidad); //Ejercicio 9
int sumarnumeros(const char *cadena, int n); //Ejercicio 9

void iniciarsala(char (*sala)[20]);  // Ejercicio 11
void mostrarsala(const char (*sala)[20]);  // Ejercicio 11
void reservarasiento(char (*sala)[20], char fila, int asiento);  // Ejercicio 11
void cancelarasiento(char (*sala)[20], char fila, int asiento);  // Ejercicio 11

int contarestrellas(const int (*matriz)[8]);  // Ejercicio 13


void interseccion(const int *A, const int *B, int (&C)[4]); //Ejercicio 15

int sumadivisores(const int *numero);  // Ejercicio 17
bool sonamigables(const int *a, const int *b);  // Ejercicio 17
int sumaamigables(const int *limite);  // Ejercicio 17

#endif
