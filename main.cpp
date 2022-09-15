#include <iostream>

using namespace std;
using std::string;

// creating classes

// abstract class
class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

// normal class
class Employee:AbstractEmployee
{

    // variaveis private podem ser acessadas apenas em sua classe
private :

    string Company;
    int Age;

    // caso queira acessar variaveis em classes herancas declarar "como protected"
protected:
    string Name;

    // public variables
public:

    // getters and setters
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }
    void setAge(int age)
    {
        Age = age;
    }
    int getAge()
    {
        return Age;
    }

    // methods in classes
    void introducing()
    {
        cout << "Meu nome eh " << getName() << endl ;
        cout << "Eu trabalho na "<< getCompany() << endl ;
        cout << "Tenho "<< getAge() << " anos " << endl;
    }

    // implementaçõa de metodo da classe abstrata
    void AskForPromotion()
    {
        if(Age > 30) cout << Name << " got promoted!!" << endl;
        else cout << Name << ", sorry no promotion for you" << endl;
    }

    // checar diferenças de comportamento se adicionar "virtual" antes de void
    void work()
    {
        cout << Name << " is checking email" << endl;
    }

    // constructor
    Employee(string name, string company, int age)
    {
        setName(name);
        setCompany(company);
        setAge(age);

        // Name = name;
        // Company = company;
        // Age = age;
    }
};


// herança:
// public necessario para herdar todos os metodos da classe parent
class Developer:public Employee
{
public:
    string favProLang;

    void setLanguage(string language)
    {
        favProLang = language;
    }
    string getLanguage()
    {
        return favProLang;
    }

    // construtor herança:
    Developer(string name, string company, int age, string language)
        :Employee(name,company,age)
    {
        setLanguage(language);
    }

    void fixBug()
    {
        cout << Name << " fix bug using " << getLanguage() << endl;
    }

    // Polymorphism
    void work()
    {
        cout << Name << " is writing " << favProLang << " code" << endl;
    }
};

class Teacher:public Employee
{
public:
    string Subject;

    void setSubject(string subject)
    {
        Subject = subject;
    }
    string getSubject()
    {
        return Subject;
    }

    // construtor herança:
    Teacher(string name, string company, int age, string subject)
        :Employee(name,company,age)
    {
        setSubject(subject);
    }

    void work()
    {
        cout << Name << " is teaching" << Subject<< endl;
    }

};


int main()
{
    // Construindo objeto
    Employee employee1 = Employee("John", "Microsoft", 21);
    Employee employee2 = Employee("Maria", "Amazon", 36);

    // Caso variaveis sejam publicas:
    // employee1.Name = "John";
    // employee1.Company = "Microsoft";
    // employee1.age = 21;


    employee1.introducing();
    employee1.AskForPromotion();
    employee2.AskForPromotion();

    Developer dev1 = Developer("Mendes", "microsoft", 25, "C++");
    Teacher t1 = Teacher("Marcos", "university", 42, "history");

    dev1.fixBug();
    dev1.AskForPromotion();

    Employee* e1 = &dev1;
    Employee* e2 = &t1;

    // exemplos de funcionamentos do polimorfismo
    dev1.work();
    t1.work();
    e1->work();
    e2->work();

    return 0;
}
