#include <string> 
#include <iostream>
#include <iomanip>
using namespace std;

#define FR 0
#define SO 1
#define JU 2
#define SR 3

/* structures -- similar to the collection of instance variables
* for a Java class */ 
class Student {
    private:
        unsigned int id; 
        string  name; 
        double gpa; 
        int year;
    public:
        Student();
        Student(int, string);
        Student(int, string, double, int);
        void update_gpa(double new_gpa);

        int class_inc();
        double get_gpa();

        void print_student();
        void print_student_concise();
};

void print_roster(Student roster[], int len);