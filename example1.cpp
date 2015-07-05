#include <iostream>
class Employee {
  public:
    Employee(int sal) { 
      std::cout << "\nIn Constructor method\n";
      salary=(sal>0)?sal:75000;
    }
    ~Employee() { 
      std::cout << "\nIn destructor method\n";
    }
    int getSalary(void) { return salary; }
  private:
    int salary;
    void _add_bonus(void) { salary+=20000; }
};

int main() {
  Employee emp1(80000);
  std::cout << "\nCurrent Salary is " << emp1.getSalary() << "\n";
}
