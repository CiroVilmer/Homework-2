#include <iostream>
using namespace std;
#include <string>
#include <chrono>
#include <iomanip>

enum class AMPM {AM,PM};
string to_string(AMPM ampm);

class Time
{
private:
    int hours;
    int minutes;
    int seconds;
    AMPM timeOfDay;

    bool input_error(string err);

public:
    Time(int h = 0, int m = 0, int s = 0, AMPM ampm = AMPM::AM);
    void printFullTime();
    void printTime();
    void printHour24();
    void edit_time();
    void test_time();
};