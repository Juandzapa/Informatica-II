#include <iostream>

using namespace std;


int cambio(){
    int cantidad, faltante;

cout << "Ingrese la cantidad de dinero: ";
cin >> cantidad;

    cout << "50000: " << cantidad / 50000 << endl;
    cantidad = cantidad % 50000;

    cout << "20000: " << cantidad / 20000 << endl;
    cantidad = cantidad % 20000;

    cout << "10000: " << cantidad / 10000 << endl;
    cantidad = cantidad % 10000;

    cout << "5000: " << cantidad / 5000 << endl;
    cantidad = cantidad % 5000;

    cout << "2000: " << cantidad / 2000 << endl;
    cantidad = cantidad % 2000;

    cout << "1000: " << cantidad / 1000 << endl;
    cantidad = cantidad % 1000;

    cout << "500: " << cantidad / 500 << endl;
    cantidad = cantidad % 500;

    cout << "200: " << cantidad / 200 << endl;
    cantidad = cantidad % 200;

    cout << "100: " << cantidad / 100 << endl;
    cantidad = cantidad % 100;

    cout << "50: " << cantidad / 50 << endl;
    cantidad = cantidad % 50;

    faltante = cantidad;

    cout << "Faltante: " << faltante << endl;

    return 0;
}



int hora_reloj(){

    int hora,duracion;

    cout << "Ingrese la hora: ";
    cin >> hora;

    cout << "Ingrese la duracion: ";
    cin >> duracion;

    int horas = hora / 100;
    int minutos = hora % 100;

    if(horas > 23 || minutos > 59){

        cout << hora << " Es una hora invalida" << endl;
    }

    else{
        int minutosduracion = duracion % 100;
        int horasduracion = duracion / 100;

        if(minutosduracion > 59){

        cout << duracion << " Es una duracion invalida" << endl;
        }

        else{
            int minutostotal,horafinal,minutosfinal;
            minutostotal = horas * 60 + minutos + horasduracion * 60 + minutosduracion;

            minutostotal = minutostotal % 1440;

            horafinal = minutostotal / 60;
            minutosfinal = minutostotal % 60;

            cout << "La hora es: " << horafinal*100 + minutosfinal << endl;
        }
    }

    return 0;
}


int valor_euler(){
    int x;
    float euler = 0, facto = 1;

    cout << "Ingrese el numero de elementos para la aproximacion: ";
    cin >> x;

    for(int i = 0; i < x; ++i){
        if(i > 0){
            facto = facto * i;
        }

        euler = euler + 1/facto;
    }

    cout << "euler es aproximadamente: " << euler << endl;
    return 0;
}

int suma_a_b_c(){
    int a,b,c,suma = 0;
    bool pri = true;

    cout << "Ingrese el valor para A: ";
    cin >> a;

    cout << "Ingrese el valor para b: ";
    cin >> b;

    cout << "Ingrese el valor para C: ";
    cin >> c;

    for(int i = 1; i < c; ++i){
        if(i % a == 0){
            if(pri == false){
                cout << "+";
            }
            cout << i;
            suma = suma + i;
            pri = false;
        }
    }

    for(int j = 1; j < c; ++j){
        if(j % b == 0 && !(j % a == 0)){
            if(pri == false){
                cout << "+";
            }
            cout << j;
            suma = suma + j;
        }
    }
    cout << " = " << suma << endl;
    return 0;
}

int primo(){

        int x,contador = 0, numero = 2;

        cout << "Ingrese el numero primo a saber: ";
        cin >> x;

        while (contador < x)
        {
            bool primo = true;

            for (int divisor = 2; divisor < numero; divisor++)
            {
                if (numero % divisor == 0)
                {
                    primo = false;
                    break;
                }
            }

            if (primo)
            {
                contador = contador + 1;
            }

            if (contador == x)
            {
                cout << "El primo numero " << x << " es: " << numero << endl;
            }

            numero = numero + 1;
        }

        return 0;
 }


 int factor_primo(){

     int n, origi, mayor = 2;

     cout << "Ingrese un numero: ";
     cin >> n;

     origi = n;

     for (int i = 2; i <= n; i++) {
         while (n % i == 0) {
             mayor = i;
             n = n / i;
         }
     }

     cout << "El mayor factor primo de " << origi << " es: " << mayor << endl;

     return 0;
 }


 int palindromo(){
     int mayor, n1 = 0 , n2 = 0;

     for (int i = 100; i <= 999; i++) {

         for (int j = 100; j <= 999; j++) {

             int producto = i * j;
             int original = producto;
             int invertido = 0;

             while (producto > 0) {
                 int digito = producto % 10;
                 invertido = invertido * 10 + digito;
                 producto = producto / 10;
             }

             if (original == invertido && original > mayor) {
                 mayor = original;
                 n1 = i;
                 n2 = j;
             }
         }
     }

     cout << n1 << "*" << n2 << " = " << mayor << endl;

     return 0;
 }


 int semilla_collazt(){
     int k, semillamayo = 0, terminosmayo = 0;

     cout << "Ingrese el valor para k: ";
     cin >> k;

     for (int semilla = 1; semilla < k; semilla++) {

         int n = semilla;
         int terminos = 1;

         while (n != 1) {

             if (n % 2 == 0) {
                 n = n / 2;
             }
             else {
                 n = 3 * n + 1;
             }

             terminos = terminos + 1;
         }

         if (terminos > terminosmayo) {
             terminosmayo = terminos;
             semillamayo = semilla;
         }
     }

     cout << "La serie mas larga es con la semilla: " << semillamayo << " teniendo " << terminosmayo << " terminos" << endl;

     cout << "Su serie: ";

     int n = semillamayo;

     cout << n;

     while (n != 1) {

         if (n % 2 == 0) {
             n = n / 2;
         }
         else {
             n = 3 * n + 1;
         }

         cout << ", " << n;
     }

     cout << endl;
     return 0;
 }

int main()
{
    while(true){

    int variable;
    cout << "Ingresa un numero par que comience desde el 2: ";
    cin >> variable;


    switch(variable)
    {
    case 2: cambio();
    break;
    case 4: hora_reloj();
    break;
    case 6: valor_euler();
    break;
    case 8: suma_a_b_c();
    break;
    case 10: primo();
    break;
    case 12: factor_primo();
    break;
    case 14: palindromo();
    break;
    case 16: semilla_collazt();
    break;
    }
    }
}
