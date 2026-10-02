#ifndef LZ78_H
#define LZ78_H

struct EntradaDiccionario{int prefijo; char caracter;
};


struct ParLZ78 {int indice; char caracter;};

ParLZ78* comprimirLZ78(const char* texto, int cantidadCaracteres, int& cantidadPares);

char* descomprimirLZ78(const ParLZ78* pares, int cantidadPares, int& cantidadCaracteres);

bool verificarTexto(const char* original, const char* reconstruido, int cantidadCaracteresOriginal, int cantidadCaracteresReconstruido);

void liberarPares(ParLZ78*& pares);

void liberarTexto(char*& texto);


#endif // LZ78_H
