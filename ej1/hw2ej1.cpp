#include <iostream>
using namespace std;
#include <string>
#include <chrono>
#include <iomanip>
#include "hw2ej1.hpp"

// Función para convertir el tipo AMPM a string
// Recibe como parámetro el tipo AMPM y devuelve un string con el valor correspondiente.
string to_string(AMPM ampm){
    switch (ampm) {
    case AMPM::AM:
        return "AM";
    case AMPM::PM:
        return "PM";
    default:
        return "UNKNOWN";
    }
}

// Constructor de la clase Time
// Recibe como parámetros la hora, los minutos, los segundos y el tipo de tiempo (AM/PM).
// Parámetros:
//     int h: Hora (0-12)
//     int m: Minutos (0-59)
//     int s: Segundos (0-59)
//     AMpM ampm: Tipo de tiempo (AM/PM)
Time::Time(int h, int m, int s, AMPM ampm) {
    if(h < 0 || h > 12) {
        cout << "Invalid hour" << endl;
        h = 0;
    }
    if(m < 0 || m > 59) {
        cout << "Invalid minute" << endl;
        m = 0;
    }
    if(s < 0 || s > 59) {
        cout << "Invalid second" << endl;
        s = 0;
    }
    hours = h;
    minutes = m;
    seconds = s;
    timeOfDay = ampm;
}

// Método para imprimir la hora completa en formato "hh:mm:ss AM/PM"
void Time::printFullTime() {
    cout << setfill('0') << setw(2) << hours << "h, " << setw(2) << minutes << "m, " << setw(2) << seconds << "s " << to_string(timeOfDay) << endl;
}

// Método para imprimir la hora en formato de 24 horas
void Time::printHour24(){
    int h;
    if (timeOfDay == AMPM::AM){
        h = hours;
    } else {
        h = hours + 12;
    }

    cout << "Son las: "<< setfill('0') << setw(2) << h << "hs" << endl;
}