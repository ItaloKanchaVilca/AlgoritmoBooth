#include <vector>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

#define k 10 

bitset<k>suma(bitset<k>a, bitset<k>b)
{
    bitset<k>respuesta;
    int acarreo = 0;

    for (int iterador = 0; iterador < k; iterador++) 
    {
        if (a[iterador] == 0 && b[iterador] == 0 && acarreo == 0)
        {
            respuesta[iterador] = 0;
            acarreo = 0;
        }
        if (a[iterador] == 1 && b[iterador] == 0 && acarreo == 0)
        {
            respuesta[iterador] = 1;
            acarreo = 0;
        }
        if (a[iterador] == 0 && b[iterador] == 1 && acarreo == 0)
        {
            respuesta[iterador] = 1;
            acarreo = 0;
        }
        if (a[iterador] == 0 && b[iterador] == 0 && acarreo == 1)
        {
            respuesta[iterador] = 1;
            acarreo = 0;
        }
        if (a[iterador] == 1 && b[iterador] == 1 && acarreo == 0) 
        {
            respuesta[iterador] = 0;
            acarreo = 1;
        }
        if (a[iterador] == 1 && b[iterador] == 1 && acarreo == 1) 
        {
            respuesta[iterador] = 1;
            acarreo = 1;
        }
    }
    return respuesta;
}

bitset<k>complementoA2(bitset<k>a) 
{
    return suma(~a, 1);
}

bitset<k>resta(bitset<k>a, bitset<k>b)
{
    return suma(a, complementoA2(b));
}

void shiftadd(bitset<k>& A, bitset<k>& Q, int& Q1) 
{
    int auxiliar1;
    int auxiliar2;
    int auxiliar3;

    auxiliar1 = A.test(k - 1);
    auxiliar2 = A.test(0);

    (A >>= 1);
    A.set(k - 1, auxiliar1);
    auxiliar3 = Q.test(0);
    (Q >>= 1);
    Q.set(k - 1, auxiliar2);
    Q1 = auxiliar3;
}

void booth(bitset<k> a, bitset<k> b) 
{
    bitset <k> Multiplicador = a;
    bitset <k> Multiplicando = b;
    bitset <k> tem = 0;

    int aux = 0;

    cout << "     A" << "  " << "         Q" << "  " << "   Q-1" << "  " << "    M" << endl;

    for (int i = 0; i < k; i++) 
    {
        cout << tem << "  " << Multiplicador << "  " << aux << "  " << Multiplicando << "   " << " ciclo " << i + 1 << endl;

        if (Multiplicador.test(0) == 1 and aux == 0)
        {
            tem = resta(tem, Multiplicando);
        }
        else if (Multiplicador.test(0) == 0 and aux == 1)
        {
            tem = suma(tem, Multiplicando);
        }
        shiftadd(tem, Multiplicador, aux);
    }
    cout << tem << "  " << Multiplicador << endl;
}

int main() 
{
    cout << "ALGORITMO DE BOOTH" << endl;
    cout << endl;

    system("color E4");
    bitset <k> a = 30;
    bitset <k> b = 60;

    booth(a, b);
    return 0;
}
