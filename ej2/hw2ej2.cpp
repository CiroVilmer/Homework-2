using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "hw2ej2.hpp"

// Constructor de la clase Student
// Crea un objeto Student con nombre, legajo e inicializa un vector de shared_ptr<ClassGrade> vacío
// Parametros:
// string n: nombre del estudiante
// int l: legajo del estudiante
Student::Student(string n, int l): name(n), legajo(l), grades(vector<shared_ptr<ClassGrade>>()) {
    cout << "Student created: " << name << " with legajo: " << legajo << endl;
}

// Constructor de la clase ClassRoom
// Crea un objeto ClassRoom con un vector de shared_ptr<Student> vacío, una cantidad máxima de estudiantes y un contador de estudiantes actuales
ClassRoom::ClassRoom(): students(vector<shared_ptr<Student>>()), maxStudentAmount(20), curr_students(0) {};

// Constructor de la clase ClassGrade
// Crea un objeto ClassGrade con una calificación y un puntero a un objeto ClassRoom.
// Funciona como una tupla para guardar las notas, que contiene la calificación y el aula.
// Parametros:
// int g: calificación del estudiante
// ClassRoom* c: puntero a un objeto ClassRoom
ClassGrade::ClassGrade(int g, ClassRoom* c): grade(g), classroom(c) {}


// Método para registrar un estudiante en el aula
// Si el aula está llena, imprime un mensaje indicando que no se puede registrar más estudiantes.
// Si no está llena, agrega el estudiante al vector de estudiantes y le asigna una calificación.
// Parametros:
// shared_ptr<Student> s: puntero compartido al objeto Student que se va a registrar
// int grade: calificación del estudiante
void ClassRoom::register_student(shared_ptr<Student> s, int grade) {
    if (curr_students == 20) {
        cout << "Class is full" << endl;
    }
    else {
        students.push_back(s);
        s->grades.push_back(make_shared<ClassGrade>(grade, this));
        curr_students++;
    }
}

// Método para desregistrar un estudiante del aula
// Busca al estudiante por su legajo y lo elimina del vector de estudiantes.
// Si el estudiante no se encuentra, imprime un mensaje indicando que no se encontró.
// Parametros:
// int l: legajo del estudiante que se va a desregistrar
void ClassRoom::unregister_student(int l) {
    bool found = false;
    Student* foundStudent;
    for(const auto &student: students){
        if(student.get()->getLegajo() == l){
            foundStudent = student.get();
            students.erase(remove(students.begin(), students.end(), student), students.end());
            curr_students--;
            found = true;
            break;
        }
    }

    if(found){
        cout << "Student with legajo " << l << " unregistered successfully." << endl;
    } else {
        cout << "Student with legajo " << l << " not found." << endl;
    }

}

// Método para verificar si el aula está llena
// Imprime un mensaje indicando si el aula está llena o no, junto con la cantidad actual de estudiantes.
// Si el aula está llena, imprime un mensaje indicando que no se pueden registrar más estudiantes.
// Si no está llena, imprime un mensaje indicando que se pueden registrar más estudiantes.
void ClassRoom::isFull()
{
    if (curr_students == maxStudentAmount) {
        cout << "Class is full. Current student count is = " << curr_students << endl;
    }
    else {
        cout << "Class is not full, current student count is = " << curr_students << endl;
    }
}

// Método para imprimir la lista de estudiantes en el aula
// Si no hay estudiantes, imprime un mensaje indicando que la cantidad actual de estudiantes es 0.
// Si hay estudiantes, ordena la lista de estudiantes en órden alfabetico con sort y la imprime.
void ClassRoom::printStudentList() {
    if (curr_students == 0) {
        cout << "Current student count is 0" << endl;
        return;
    }

    vector<shared_ptr<Student>> sortedStudents = students;
    sort(sortedStudents.begin(), sortedStudents.end(), [](const shared_ptr<Student>& a, const shared_ptr<Student>& b) {
        return *a < *b;
    });
    
    for (const auto& student : sortedStudents) {
        cout << *student << endl;
    }
}

// Método para buscar un estudiante por su legajo
// Recorre la lista de estudiantes y devuelve un puntero al estudiante si se encuentra.
// Si no se encuentra, devuelve nullptr.
// Parametros:
// int l: legajo del estudiante que se va a buscar
// Retorna:
// Student*: puntero al objeto Student si se encuentra, nullptr si no se encuentra
Student* ClassRoom::lookForStudent(int l) {
    for (auto &student : students) {
        if (student.get()->getLegajo() == l) {
            return student.get();
        }
    }
    return nullptr;
}

// Sobrecarga del operador " = " para la clase ClassRoom
// Permite asignar un objeto ClassRoom a otro.
// Copia los atributos y el vector de estudiantes del objeto original al objeto actual.
// Si el objeto actual es el mismo que el objeto original, no hace nada y retorna una referencia al objeto actual. 
// Parametros:
// const ClassRoom& original: objeto ClassRoom original que se va a asignar
// Retorna:
// ClassRoom&: referencia al objeto ClassRoom actual
ClassRoom& ClassRoom::operator=(const ClassRoom& original) {
    if(this == &original){
        return *this;
    }

    this->students.clear();

    maxStudentAmount = original.maxStudentAmount;
    curr_students = original.curr_students;

    for(const auto &student: original.students){
        this->students.push_back(student);
    }

    return *this;
}
//JUSTIFICACIÓN DE LA COPIA: En esta función hago una shallow copy de los atributos del objeto original al objeto actual.
// Esto es suficiente porque los cursos y los estudiantes son objetos compartidos. Es decir, como un estudiante puede estar en varios cursos,
// es necesario que los cursos compartan la misma referencia al estudiante.
// Esto evita la duplicación de estudiantes y asegura que cualquier cambio en un estudiante se refleje en todos los cursos donde está registrado.
// Es decir, si, por ejemplo, se desinscribe a un estudiante de un curso, su vector notas solo saca ese curso, para que el estudiante pueda seguir
// estando en otros cursos.


//Implementacion student

// Método para obtener el nombre del estudiante
// Retorna:
// string: nombre del estudiante
string Student::getName() {
    return name;
}

// Método para obtener el legajo del estudiante
// Retorna:
// int: legajo del estudiante
int Student::getLegajo() {
    return legajo;
}

// Método para obtener el promedio de las calificaciones del estudiante
// Recorre el vector de calificaciones y calcula el promedio.
// Retorna:
// float: promedio de las calificaciones del estudiante
float Student::getAverage() {
    float sum = 0;
    for (const auto& grade : grades) {
        sum += grade->grade;
    }
    return sum / grades.size();
}

// Método para eliminar una calificación del estudiante
// Busca la calificación en el vector de calificaciones y la elimina si se encuentra.
// Recorre el vector de calificaciones y compara cada calificación con la calificación a eliminar. Si encuentra una coincidencia, elimina la calificación del vector.
// Parametros:
// ClassRoom* c: puntero a un objeto ClassRoom que contiene la calificación a eliminar
void Student::deleteGrade(ClassRoom* c) {
    for (auto it = grades.begin(); it != grades.end(); ++it) {
        if ((*it)->classroom == c) {
            grades.erase(it);
            break;
        }
    }
}

// Método para mostrar las calificaciones del estudiante
// Recorre el vector de calificaciones y las imprime.
// Si no hay calificaciones, imprime un mensaje indicando que no hay calificaciones.
// Si hay calificaciones, imprime cada calificación en una nueva línea.
void Student::showGrades() {
    cout << "Grades for student " << name << ":" << endl;
    for (const auto& grade : grades) {
        cout << grade->grade << endl;
    }
}

// Sobrecarga del operador " < " para la clase Student
// Permite comparar dos objetos Student por su nombre.
// Retorna true si el nombre del objeto actual es menor que el nombre del otro objeto, false en caso contrario.
// Parametros:
// const Student& other: objeto Student con el que se va a comparar
bool Student::operator<(const Student& other) {
    return this->name < other.name;
}

// Sobrecarga del operador " << " para la clase Student
// Imprime el nombre y el legajo del estudiante.
ostream& operator<<(ostream& os, const Student& s) {
    os << "Alumno: " << s.name << ", Legajo: " << s.legajo;
    return os;
}