#include <iostream>
#include <vector>
#include <string>

class Employee{
protected:
    int m_id;
    std::string m_name;

public:
    Employee():m_id(0), m_name(" "){};
    Employee(int id, std::string name):m_id(id), m_name(name){};
    virtual double calculateSalary() = 0;
    virtual void displayInfo(){
        std::cout<<"ID: " << m_id << ", Name: " << m_name << std::endl;
    };
    int getID(){
        return m_id;
    }
    std::string getName(){
        return m_name;
    }

};

class BonusEligible{
private:
    
public:
    virtual double calculateBonus() = 0;
};

class FullTimeEmployee : public Employee, public BonusEligible{
private:
    double monthlySalary;
public:
    FullTimeEmployee():monthlySalary(0){};
    FullTimeEmployee(int id, std::string name, double salary)
    :Employee(id, name), monthlySalary(salary){};
    double calculateSalary()override{
        return monthlySalary + calculateBonus();
    };
    double calculateBonus()override{
        return monthlySalary * 0.1; 
    };

    void displayInfo(){
        Employee::displayInfo();
        std::cout<<"monthlySalary: " << monthlySalary <<std::endl;
        std::cout<<"Selary with Bonus: " << calculateSalary() <<std::endl;
    };
};

class PartTimeEmployee: public Employee{
private:
    double hourlyRate;
    int hoursWorked;
public:
    PartTimeEmployee():hourlyRate(0), hoursWorked(0){};
    PartTimeEmployee(int id, std::string name, double rate, int hours)
    :Employee(id, name), hourlyRate(rate), hoursWorked(hours){};
    double calculateSalary()override{
        return hourlyRate * hoursWorked;
    };
    void displayInfo(){
        Employee::displayInfo();
        std::cout<<"Salary: " << calculateSalary() << std::endl;
    };
};

class Freelancer : public Employee{
private:
    int projectsCompleted;
    double paymentPerProject;
public:
    Freelancer():projectsCompleted(0), paymentPerProject(0){};
    Freelancer(int id, std::string name, int projects, double payment)
    :Employee(id, name), projectsCompleted(projects), paymentPerProject(payment){};
    double calculateSalary()override{
        return projectsCompleted * paymentPerProject;
    };
    void displayInfo(){
        Employee::displayInfo();
        std::cout<<"Salary: " << calculateSalary() << std::endl;
    };
};

class PayrollSystem{
private:
    std::vector<Employee*> employees;
public:
    void addEmployee(Employee* employee){
        employees.push_back(employee);
    };
    void displayEmployees(){
        for(Employee* element: employees){
            element->displayInfo();
        }
    };
    void calculateAllSalaries(){
        double lav= 0;
        for(Employee* element: employees){
            lav  += element->calculateSalary();
        }
        std::cout<<"----------------------------------------"<<std::endl;
        std::cout<<"All Salaries: " << lav << std::endl;
            std::cout<< "Sum :" <<lav<<std::endl;
    };
    void findEmployeeByID(int id){
        std::cout<<"________________________________________"<<std::endl;
        std::cout<<"Your Search Person: " << std::endl;
        for(Employee* element: employees){
            if(element->getID() == id){
                element->displayInfo();
                return;
            }
        }
    };
    ~PayrollSystem(){
        for(Employee* element: employees){
            delete element;
        }
    };

};

int main(){

    PayrollSystem pay;
    pay.addEmployee(new FullTimeEmployee(1, "Gev", 5000));
    pay.addEmployee(new PartTimeEmployee(2, "Samo", 20, 1600));
    pay.addEmployee(new Freelancer(3, "Artur", 5, 5000));

    pay.displayEmployees();
    pay.findEmployeeByID(2);
    pay.calculateAllSalaries();
    return 0;
}


