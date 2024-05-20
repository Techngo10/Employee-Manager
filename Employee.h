#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

using namespace std;

class Employee: public Person{
    private:
        int ID;
        float salary_hourly;
        float hours_weekly;
        bool attendance[7];
        std::string date_joined;
        int performance;
    
    public:
        //Initialisation
        Employee();
        Employee(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address);

        //Getters
        int get_ID();
        int get_counter();
        bool get_attendance(int day);
        int get_performance();
        std::string get_date_joined();
        float get_salary_hourly();
        float get_hours_weekly();

        //Setters
        void set_ID(int ID);
        void set_counder(int counter);
        void set_attendance(bool attending, int day);
        void set_performance(int performance);
        void set_date_joined(std::string date_joined);
        void set_salary_hourly(float salary_hourly);
        void set_hours_weekly(float hours_weekly);

        // Static counter for ID variable
        static int _counter;
};


 
#endif // EMPLOYEE_H
 