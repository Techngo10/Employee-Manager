#include <iostream>
#include "Employee.h"
#include <string>
using namespace std;
  
int main() {
    // Test Employee class
    cout << "Testing Employee class:" << endl;
    Employee emp1(23.33, 10.11, "01-01-2024", 20, 112233, "Jone", "Terrace");
    cout << "Employee 1 ID: " << emp1.get_ID() << ", Salary (hourly): $" << emp1.get_salary_hourly() << ", Hours (weekly): " << emp1.get_hours_weekly() << ", Date Joined: " << emp1.get_date_joined() << endl;
    cout << "Employee 1 performance: " << emp1.get_performance() << endl;

    // Test attendance
    cout << "Employee 1 attendance:" << endl;
    for (int i = 0; i < 7; ++i) {
        cout << "Day " << i << ": " << (emp1.get_attendance(i) ? "Present" : "Absent") << endl;
    }

    // Test setting attendance
    emp1.set_attendance(true, 5); // Set Saturday as present
    cout << "Employee 1 attendance after setting Saturday present:" << endl;
    for (int i = 0; i < 7; ++i) {
        cout << "Day " << i << ": " << (emp1.get_attendance(i) ? "Present" : "Absent") << endl;
    }

    return 0;
}