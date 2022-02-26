#include <iostream>
#include <string>
using namespace std;

class Employee{
  string organization;
  string position;
  double experience;
  string name;
  char gender;
  int age;
  double salary;
  static int i;

public:

      Employee(string organization, string position, double experience,string name, char gender, int age, double salary) { // конструктор

            i++; // увеличиваем количество созданных объектов
            this->organization = organization;
            this->position = position;
            this->experience = experience;
            this->name = name;
            this->gender = gender;
            this->age = age;
            this->salary = salary;
            
      }

      ~Employee() { // деструктор

            i--; // уменьшаем количество созданных объектов

      }

      /* …. */

      static void showCount() {

            cout << "Count: " << i << endl;
      }
    string GetOrganization() {
      return organization;
    }
    string GetPosition() {
      return position;
    }
    double GetExperience() {
      return experience;
    }
    double GetSalary() {
      return salary;
    }
    void SetPosition(string position) {
      this->position = position;
    }
    void PayrollSalary(double salary) {
      this->salary +=  salary;
    }
    char GetGender() {
      return gender;
    }
    string GetName() {
      return name;
    }
    int GetAge() {
      return age;
    }
    void EmployeeInfo () {
      cout << "Name " << name << endl;
      cout << "Gender " << gender << endl;
      cout << "Age " << age << endl;
    }
    bool operator<(Employee a){
        if(this->experience < a.GetExperience()) {
            return true;
        }
     return false;
    }
};

// инициализация статического члена класса

// (обязательно вне класса!!! Так как под него не выделена память!)

int Employee::i = 0;

 

int main() {

      
  
Employee::showCount();         // 0

      Employee *a = new Employee("ВТБ", "Аналитик данных", 3, "Вадим", 'M', 19, 1500000);

      Employee::showCount();         // 1

      Employee *b = new Employee("Сбербанк", "Менеджер по продажам", 2, "Дима", 'M', 18, 1000000);
      cout << (a < b) << endl;//
      Employee::showCount();         // 2

      delete b;

      Employee::showCount();         // 1

 

      return 0;

}
