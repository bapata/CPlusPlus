// demo of void pointer usage
#include <iostream>
#include <stdlib.h>

using namespace std;

// global
static int student_counter=1;

typedef struct {
  string name;
  string ssn;
  int zip_code;
} Student;


void modify_student(void *student_ptr) {
  Student *st_ptr = (Student *)student_ptr;
  char tmp_cnt[20];
  sprintf(tmp_cnt,"%d",student_counter++);
  st_ptr->name = "student_number" + string(tmp_cnt);
  st_ptr->ssn= "123-45-667" + string(tmp_cnt);
  st_ptr->zip_code = 12345;
}

void print_student(void *student_ptr) {
  Student *st_ptr = (Student *)student_ptr;
  cout << st_ptr->name << endl;
  cout << st_ptr->ssn << endl;
  cout << st_ptr->zip_code<< endl;
}



int main() {
  Student student1; // memory allocated from main function's stack

  Student *pstudent2 = new Student; // memory allocated from heap

  cout << "Before calling modify_student\n";
  print_student(&student1);
  print_student(pstudent2);

  cout << "\nAfter calling modify_student\n";
  modify_student(&student1);
  modify_student(pstudent2);
  print_student(&student1);
  print_student(pstudent2);
}
