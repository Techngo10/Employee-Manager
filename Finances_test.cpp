#include "Finances.h"

#include <string.h>

#include <iostream>

#include "Person.h"
using namespace std;

int main() {
  Finances staff1;
  int staff1_bugdet = 0;
  int staff1_expense = 0;
  int staff1_profit = 0;
  int staff1_turnover = 0;
  string staff1_position = "none";

  cout << staff1.get_budget() << endl;
  cout << staff1.get_expense() << endl;
  cout << staff1.get_position() << endl;
  cout << staff1.get_profit() << endl;
  cout << staff1.get_turnover() << endl;

  cout << "enter bugdet: " << endl;
  cin >> staff1_bugdet;
  staff1.set_budget(staff1_bugdet);

  cout << "enter expense: " << endl;
  cin >> staff1_expense;
  staff1.set_expense(staff1_expense);

  cout << "enter position: " << endl;
  cin >> staff1_position;
  staff1.set_position(staff1_position);
  cout << staff1.get_budget() << endl;
  cout << staff1.get_expense() << endl;
  cout << staff1.get_position() << endl;

  Finances staff2("Financial planner", 12000, 80000, 100000, 1000);
  staff2.check_turnover_profit(staff2.get_turnover(), staff2.get_profit());
  cout << staff2.get_budget() << endl;
  cout << staff2.get_expense() << endl;
  cout << staff2.get_position() << endl;
  cout << staff2.get_profit() << endl;
  cout << staff2.get_turnover() << endl;

  return 0;
}