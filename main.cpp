#include <iostream>
using namespace std;

class Company{
    private:
        string founder = "Two";
        string address = "Bangkok";
        friend void showCompany();
        friend class Employee;
    public:
        static int count;
};

int Company::count = 0;

class Employee{
    private:
        string name;
        int salary = 0; 
    public :
        Employee(){ // Construtor
            cout << "Create Employee Object" << endl;
        }
        Employee(string n){ // Construtor Parameter
            name = n;
        }
        Employee(string n, int s){ // Construtor Parameter
            name = n;
            salary = s;
            Company::count++;
        }
        // setter medthod
        void setName(string n){
            name = n;
        }
        void setSalary(int s){
            salary = s;
        }

        //getter medthod
        string getName(){
            return name;
        }
        int getSalary(){
            return salary;
        }

        void showdata(){
            cout << "Name : " << name << endl;
            cout << "Salary : " << salary << endl;
        }  
        // virtual void about()=0; // Pure virsual method
        void showFounder(){
            Company c;
            cout << c.founder << endl;
            cout << c.address << endl;
        }
};

class IT : public Employee{
    public:
        IT(){
            cout << "Create IT Object" << endl;   
        }
        IT(string n) : Employee (n){ // Construtor Parameter
            Company::count++;
        }
        IT(string n, int s) : Employee (n,s){ // Construtor Parameter

        }
        
        void showdata(){
            cout << "Name : " << getName() << endl;
            cout << "Salary : " << getSalary() << endl;
            cout << "IT Department" << endl;
        }  
        // void about(){
        //     cout << "Dev Product" << endl;
        // }

};

class Sale : public Employee{
    public:
        Sale(){
            cout << "Create Sale Object" << endl;   
        }
        void showdata(){
            cout << "Name : " << getName() << endl;
            cout << "Salary : " << getSalary() << endl;
            cout << "Sale Department" << endl;
        } 

        // void about(){
        //     cout << "Dev Sale" << endl;
        // }
};

void call_opEmployee(){
    Employee emp1;
    Employee emp2 ("Two");
    Employee emp3 ("Two",100000);
    // emp1.name = "Tanawin";
    // emp1.salary = 200,000;
    // cout << emp2.name() << endl;
    // cout << emp1.salary << endl;
    emp1.setName("Tanawin");
    emp1.setSalary(200000);

    cout << emp1.getName() << endl;
    cout << emp1.getSalary() << endl;

    emp1.showdata();
    emp2.showdata();
    emp3.showdata();

}

void call_inherEmp(){
    IT emp1;
    emp1.setName("Tanawin");
    emp1.setSalary(200000);
    cout << emp1.getName() << endl;
    cout << emp1.getSalary() << endl;
    emp1.Employee::showdata();
    emp1.showdata();
    cout << "-------------------------" << endl;

    Sale emp2;
    emp2.setName("Two");
    emp2.setSalary(100000);
    cout << emp2.getName() << endl;
    cout << emp2.getSalary() << endl;
    emp2.Employee::showdata();
    emp2.showdata();
    cout << "-------------------------" << endl;
}

void showCompany(){
    Company c;
    Employee emp1("a",100);;
    Employee emp2("b",200);
    Employee emp3("c",300);
    cout << c.founder << endl;
    cout << c.address << endl;
    cout << c.count << endl;
}

int main(int, char**) {
    // call_opEmployee();
    // call_inherEmp();
    showCompany();
    return 0;
}
