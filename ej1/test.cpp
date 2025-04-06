#include "hw2ej1.cpp"

// Método para imprimir la hora en el formato que quiera el usuario
// El usuario puede elegir entre imprimir la hora completa, en formato de 24 horas, solo la hora, solo los minutos, solo los segundos o solo AM/PM
// El método utiliza un bucle while para permitir al usuario elegir varias opciones de impresión en un solo llamado.
// El bucle se detiene cuando el usuario elige la opción de salir del printer.
// El método utiliza un switch para manejar las diferentes opciones de impresión.
// El método utiliza la función setfill y setw para mostrar bien la salida de la hora, los minutos y los segundos con ceros a la izquierda.
void Time::printTime(){

    bool continuePrinting = true;
    while (continuePrinting) {
        cout << "Que desea imprimir?" << endl;
        cout << "1. Hora completa" << endl;
        cout << "2. Hora en formato 24h" << endl;
        cout << "3. Solo la hora" << endl;
        cout << "4. Solo los minutos" << endl;
        cout << "5. Solo los segundos" << endl;
        cout << "6. Solo AM/PM" << endl;
        cout << "7. Salir del printer" << endl;

        int option;
        cin >> option;

        switch(option) {
            case 1:
                printFullTime();
                break;
            case 2:
                printHour24();
                break;
            case 3:
                cout << setfill('0') << setw(2) << hours << "h"<< endl;
                break;
            case 4:
                cout << setfill('0') << setw(2) << minutes << "m" << endl;
                break;
            case 5:
                cout << setfill('0') << setw(2) << seconds << "s" << endl;
                break;
            case 6:
                cout << to_string(timeOfDay) << endl;
                break;
            case 7:
                continuePrinting = false;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    }

}

// Método para editar la hora, los minutos, los segundos y el tipo de tiempo (AM/PM).
// El método utiliza un bucle while para permitir al usuario elegir varias opciones de edición en un solo llamado.
// El bucle se detiene cuando el usuario elige la opción de salir de la edición.
// El método utiliza un switch para manejar las diferentes opciones de edición.
// El método utiliza la función input_error para manejar los errores de entrada del usuario.
void Time::edit_time() {
    int h, m, s;
    AMPM ampm;
    bool continueEditing = true;

    while (continueEditing) {
        cout << "Que desea editar?" << endl;
        cout << "1. Hora" << endl;
        cout << "2. Minutos" << endl;
        cout << "3. Segundos" << endl;
        cout << "4. AM/PM" << endl;
        cout << "5. Salir de la edición" << endl;
        int option;
        cin >> option;

        switch(option) {
            case 1: {
                cout << "Ingrese la nueva hora: ";
                cin >> h;
                if(h < 0 || h > 12) {
                    if (!input_error("La hora")) continueEditing = false;
                    break;
                }
                hours = h;
                break;
            }
            case 2: {
                cout << "Ingrese los nuevos minutos: ";
                cin >> m;
                if(m < 0 || m > 59) {
                    if (!input_error("Los minutos")) continueEditing = false;
                    break;
                }
                minutes = m;
                break;
            }
            case 3: {
                cout << "Ingrese los nuevos segundos: ";
                cin >> s;
                if(s < 0 || s > 59) {
                    if (!input_error("Los segundos")) continueEditing = false;
                    break;
                }
                seconds = s;
                break;
            }
            case 4: {
                cout << "Ingrese AM o PM: ";
                string ampm_str;
                cin >> ampm_str;
                if(ampm_str == "AM" || ampm_str == "am") {
                    ampm = AMPM::AM;
                } else if(ampm_str == "PM" || ampm_str == "pm") {
                    ampm = AMPM::PM;
                } else {
                    if (!input_error("AM/PM")) continueEditing = false;
                    break;
                }
                timeOfDay = ampm;
                break;
            }

            case 5: {
                continueEditing = false;
                break;
            }

            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    }
}

// Método para manejar los errores de entrada del usuario.
// El método recibe un string con el error de entrada y pregunta al usuario si desea volver a intentar o cancelar la edición, dependiendo de la respuesta del usuario, el método devuelve true o false.
// Parámetros:
//     string err: Error de entrada del usuario
// Retorna:
//     bool: true si el usuario desea volver a intentar, false si desea cancelar la edición
bool Time::input_error(string err) {
    cout << err << " ingresadas/os son invalidas/os. ¿Desea volver a intentar (s) o cancelar la edición (n)? ";
    char ans;
    cin >> ans;
    return ans == 's';
}

// Método para probar la clase Time.
// El método utiliza un bucle while para permitir al usuario elegir varias opciones de prueba en un solo llamado.
// El bucle se detiene cuando el usuario elige la opción de salir de la prueba.
// El método utiliza un switch para manejar las diferentes opciones de prueba.
void Time::test_time() {
    bool continueTesting = true;

    while (continueTesting) {
        cout << "Que desea probar?" << endl;
        cout << "1. Opciones de impresión" << endl;
        cout << "2. Opciones de edición" << endl;
        cout << "3. Salir" << endl;
        int option;
        cin >> option;
        switch(option) {
            case 1:
                printTime();
                break;
            case 2:
                edit_time();
                break;
            case 3:
                continueTesting = false;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    }
}

// Función para crear un objeto Time a partir de la entrada del usuario.
// La función pregunta al usuario qué tipo de creación desea hacer.
// Se utiliza los parametros por defecto del constructor de la clase Time para crear el objeto querido.
// La función utiliza un switch para manejar las diferentes opciones de creación.
// Retorna:
//     Time: Objeto Time creado a partir de la entrada del usuario
Time create_time(){
    cout << "Ingrese la creación que quiere:" << endl;
    cout << "1. Solo hora" << endl;
    cout << "2. Solo hora y minutos" << endl;
    cout << "3. Solo hora, minutos y segundos" << endl;
    cout << "4. Hora, minutos, segundos y AM/PM" << endl;
    int option;
    cin >> option;
    int h, m, s;
    AMPM ampm;
    switch(option) {
        case 1:
            cout << "Ingrese la hora: ";
            cin >> h;
            if(h < 0 || h > 12) {
                cout << "La hora ingresada es invalida" << endl;
                return Time();
            }
            return Time(h);
        case 2:
            cout << "Ingrese la hora: ";
            cin >> h;
            if(h < 0 || h > 12) {
                cout << "La hora ingresada es invalida" << endl;
                return Time();
            }
            cout << "Ingrese los minutos: ";
            cin >> m;
            if(m < 0 || m > 59) {
                cout << "Los minutos ingresados son invalidos" << endl;
                return Time();
            }
            return Time(h, m);
        case 3:
            cout << "Ingrese la hora: ";
            cin >> h;
            if(h < 0 || h > 12) {
                cout << "La hora ingresada es invalida" << endl;
                return Time();
            }
            cout << "Ingrese los minutos: ";
            cin >> m;
            if(m < 0 || m > 59) {
                cout << "Los minutos ingresados son invalidos" << endl;
                return Time();
            }
            cout << "Ingrese los segundos: ";
            cin >> s;
            if(s < 0 || s > 59) {
                cout << "Los segundos ingresados son invalidos" << endl;
                return Time();
            }
            return Time(h, m, s);
        case 4:
            cout << "Ingrese la hora: ";
            cin >> h;
            if(h < 0 || h > 12) {
                cout << "La hora ingresada es invalida" << endl;
                return Time(0, 0, 0, AMPM::AM);
            }
            cout << "Ingrese los minutos: " << endl;
            cin >> m;
            if(m < 0 || m > 59) {
                cout << "Los minutos ingresados son invalidos" << endl;
                return Time(0, 0, 0, AMPM::AM);
            }
            cout << "Ingrese los segundos: ";
            cin >> s;
            if(s < 0 || s > 59) {
                cout << "Los segundos ingresados son invalidos" << endl;
                return Time(0, 0, 0, AMPM::AM);
            }
            cout << "Ingrese AM o PM: ";
            string ampm_str;
            cin >> ampm_str;
            if(ampm_str == "AM" || ampm_str == "am") {
                ampm = AMPM::AM;
            } else if(ampm_str == "PM" || ampm_str == "pm") {
                ampm = AMPM::PM;
            } else {
                cout << "AM/PM ingresados son invalidos" << endl;
                return Time(0, 0, 0, AMPM::AM);
            }
            return Time(h, m, s, ampm);
    };
};

int main() {
    Time t = create_time();

    t.test_time();
    return 0;
}

