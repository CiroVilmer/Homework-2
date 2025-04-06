#include "hw2ej2.cpp"

// Función para mostrar el menú y manejar la interacción con el usuario
void menu() {
    vector<shared_ptr<ClassRoom>> classes;
    vector<shared_ptr<Student>> students;

    int option;
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Crear nueva clase" << endl;
        cout << "2. Mostrar todas las clases" << endl; 
        cout << "3. Agregar alumno a una clase" << endl; 
        cout << "4. Mostrar alumnos de una clase (Órden alfabético)" << endl;
        cout << "5. Igualar clases" << endl;
        cout << "6. Mostrar promedio de un alumno" << endl;
        cout << "7. Desregistrar alumno de una clase" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch(option) {
            case 1: {
                auto classroom = make_shared<ClassRoom>();
                classes.push_back(classroom);
                cout << "Clase creada con ID: " << classes.size() - 1 << endl;
                break;
            }
            case 2: {
                if (classes.empty()) {
                    cout << "No hay clases creadas.\n";
                } else {
                    cout << "Lista de clases:\n";
                    for (size_t i = 0; i < classes.size(); ++i) {
                        cout << "Clase ID: " << i << " - Estudiantes: " << classes[i]->students.size() << endl;
                    }
                }
                break;
            }
            case 3: {
                if (classes.empty()) {
                    cout << "Primero crea una clase.\n";
                    break;
                }
            
                int classId;
                cout << "Ingrese ID de la clase (0 a " << classes.size() - 1 << "): ";
                cin >> classId;
            
                if (classId < 0 || classId >= (int)classes.size()) {
                    cout << "ID de clase inválido.\n";
                    break;
                }
            
                cout << "\nAlumnos registrados actualmente:" << endl;
                for (const auto& s : students) {
                    cout << "  - " << s->getName() << " (Legajo: " << s->getLegajo() << ")" << endl;
                }
            
                int legajo;
                cout << "\nIngrese legajo del alumno a agregar: ";
                cin >> legajo;
            
                shared_ptr<Student> selectedStudent = nullptr;
                for (auto& s : students) {
                    if (s->getLegajo() == legajo) {
                        selectedStudent = s;
                        break;
                    }
                }
            
                if (!selectedStudent) {
                    string name;
                    cout << "Alumno no encontrado. Ingrese nombre para crear nuevo alumno: ";
                    cin >> name;
                    cout << "Ingrese legajo: ";
                    cin >> legajo;
            
                    selectedStudent = make_shared<Student>(name, legajo);
                    students.push_back(selectedStudent);
                } else {
                    cout << "Alumno encontrado: " << selectedStudent->getName() << "\n";
                }
            
                int grade;
                cout << "Ingrese nota: ";
                cin >> grade;
            
                classes[classId]->register_student(selectedStudent, grade);
                cout << "Alumno agregado a la clase.\n";
                break;
            }
            
            case 4: {
                if (classes.empty()) {
                    cout << "No hay clases creadas.\n";
                    break;
                }

                int classId;
                cout << "Ingrese ID de la clase: ";
                cin >> classId;

                if (classId < 0 || classId >= (int)classes.size()) {
                    cout << "ID de clase invalido.\n";
                    break;
                }

                cout << "Alumnos en la clase " << classId << ":\n";
                classes[classId]->printStudentList();
                break;
            }
            case 5: {
                if (classes.size() < 2) {
                    cout << "Se necesitan al menos dos clases para igualar.\n";
                    break;
                }

                int classId1, classId2;
                cout << "Ingrese ID de la primera clase: ";
                cin >> classId1;
                cout << "Ingrese ID de la segunda clase: ";
                cin >> classId2;

                if (classId1 < 0 || classId1 >= (int)classes.size() || classId2 < 0 || classId2 >= (int)classes.size()) {
                    cout << "ID de clase invalido.\n";
                    break;
                }

                *classes[classId1] = *classes[classId2];
                cout << "Clases igualadas.\n";
                break;
            }
            case 6: {
                if (students.empty()) {
                    cout << "No hay alumnos registrados.\n";
                    break;
                }
                
                cout << "Lista de alumnos:\n";

                for (const auto& student : students) {
                    cout << *student << endl;
                }

                int legajo;
                cout << "Ingrese legajo del alumno: ";
                cin >> legajo;

                shared_ptr<Student> foundStudent = nullptr;
                for (auto& s : students) {
                    if (s->getLegajo() == legajo) {
                        foundStudent = s;
                        break;
                    }
                }

                if (!foundStudent) {
                    cout << "Alumno no encontrado.\n";
                } else {
                    cout << "Promedio de " << foundStudent->getName() << ": " << foundStudent->getAverage() << endl;
                }
                break;
            }
            case 7: {
                if (classes.empty()) {
                    cout << "No hay clases creadas.\n";
                    break;
                }

                int classId, legajo;
                cout << "Ingrese ID de la clase: ";
                cin >> classId;

                if (classId < 0 || classId >= (int)classes.size()) {
                    cout << "ID de clase invalido.\n";
                    break;
                }
                classes[classId]->printStudentList();
                cout << "Ingrese legajo del alumno a desregistrar: ";
                cin >> legajo;

                classes[classId]->unregister_student(legajo);
                break;
            }
            case 0: {
                cout << "Saliendo...\n";
                break;
            }
            default: {
                cout << "Opcion invalida.\n";
            }
        }
    } while(option != 0);
}

int main(){

    menu();

    return 0;
}