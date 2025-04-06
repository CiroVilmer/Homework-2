using namespace std;
#include <string>
#include <iostream>
#include <memory>
#include <vector>

/*
Respuesta punto c)
La relación entre los objetos ClassRoom y Student es una relación de agregación. Ya que los objetos estan bastante relacionados
pero el ciclo de vida de uno no depende del otro.

Cada ClassRoom mantiene un vector de shared_ptr<Student>, lo que implica que no es dueño exclusivo de los estudiantes.
Varios cursos pueden compartir los mismos estudiantes, gracias al uso de shared_ptr.
*/

class ClassGrade;
class ClassRoom;
class Student;

class Student {
    private:
    string name = "";
    int legajo = 0;

    public:
    vector<shared_ptr<ClassGrade>> grades;

    Student(string n, int l);
    string getName();
    int getLegajo();
    float getAverage();
    void deleteGrade(ClassRoom* c);
    void showGrades();
    bool operator<(const Student& other);
    friend ostream& operator<<(ostream& os, const Student& s);
};

class ClassRoom {
private:
    int maxStudentAmount;
    int curr_students;

public:
    vector<shared_ptr<Student>> students;
    
    ClassRoom();
    void register_student(shared_ptr<Student> s, int grade);
    void unregister_student(int l);
    void isFull();
    Student* lookForStudent(int l) ;
    ClassRoom& operator=(const ClassRoom& original);
    void printStudentList();
};

class ClassGrade {
    public:
    int grade;
    ClassRoom* classroom;

    ClassGrade(int g, ClassRoom* c);
};