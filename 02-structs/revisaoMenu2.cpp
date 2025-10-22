//struct é um recurso para que programadores possam criar tipos artificiais

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#include "meusIncludesG.h"

int main() {
    Glicemia medicaoLucas;
    medicaoLucas.valorGlicemia = 133;
    medicaoLucas.data = "11/08/2025";
    medicaoLucas.hora = "19:02";


    Glicemia ano2025[365];
    ano2025[0].valorGlicemia = 98;
    ano2025[0].data = "11/07/2025";
    ano2025[0].hora = "12:34";

    cout << "ola lucas\n";




    return 1;
}