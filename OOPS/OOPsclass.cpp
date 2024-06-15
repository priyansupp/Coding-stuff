#include <iostream>
using std::string;


class employee{
public:
    string name;    //attribute
    string company; //attribute
    int age;        //attribute
    void introduction(){            // method of the class "employee"
        std::cout<<"Name is "<<name<<std::endl;
        std::cout<<"Company is "<<company<<std::endl;
        std::cout<<"Age is "<<age<<std::endl;
    }
    void sayHello(string n) {
        std::cout << "HELLO " << n;
    }
    employee(string N, string C, int A){       //constructor is always the same name as that of class and declared under public domain.
        name=N;
        company=C;
        age=A;
    }
};

int main()
{
    int number;       //variable of type int
    // employee emp1;    //variable of type employee, object of class employee
    // emp1.sayHello("Priyanshu");
    // emp1.name="pkj";
    // emp1.company="iitg";
    // emp1.age=19;
    // employee emp2;
    // emp2.name="abc";
    // emp2.company="iitb";
    // emp2.age=22;
    // emp2.introduction();
    // emp1.introduction();
    // employee emp3=employee("hehe","amazon", 33);
    // emp3.introduction();

}