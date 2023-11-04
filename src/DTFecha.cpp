#include "../include/DTFecha.h"

    
DTFecha::DTFecha (int ano, int mes, int dia){
    this->Ano = ano;
    this->Mes = mes;
    this->Dia = dia;
};

int DTFecha::getAno(){
    return this->Ano;
};

int DTFecha::getMes(){
    return this->Mes;
};

int DTFecha::getDia(){
    return this->Dia;
};

DTFecha::~DTFecha(){};
