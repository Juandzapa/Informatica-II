#ifndef ENCRIPTACION_H
#define ENCRIPTACION_H

#include <vector>

using namespace std;

unsigned char rotar_izquierda(unsigned char byte, int n);

unsigned char rotar_derecha(unsigned char byte, int n);

vector<unsigned char> encriptar(const vector<unsigned char>& datos, int n, unsigned char clave);

vector<unsigned char> desencriptar(const vector<unsigned char>& datos, int n,unsigned char clave);

#endif // ENCRIPTACION_H
