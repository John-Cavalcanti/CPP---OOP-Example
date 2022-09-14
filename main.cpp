#include <iostream>

using namespace std;
using std::string;

// creating classes

// abstract class
class AbstractEmployee{
    virtual void AskForPromotion() = 0;
};

// normal class
class Employee:AbstractEmployee {
    
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

        // constructor
        Employee(string name, string company, int age){
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
class Developer:public Employee {
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

    dev1.fixBug();
    dev1.AskForPromotion();
    return 0;
}
