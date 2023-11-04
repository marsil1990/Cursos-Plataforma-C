#include <iostream>
using namespace std;
#ifndef DTFECHA
#define DTFECHA
class DTFecha
{
private:
    int Ano;
    int Mes;
    int Dia;
public:
    DTFecha (int Ano, int Mes, int Dia);
    int getAno();
    int getMes();
    int getDia();
    ~DTFecha();
};

#endif
