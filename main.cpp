#include <iostream>

using namespace std;

class Library {
private:
    string book_name;
    string book_autor;

protected:
    unsigned int value_of_security;
public:
    unsigned int shits_value = 50;
    string adress;  //Отсутствие инкапсуляции

    Library(string adress) {
        this->adress = adress;
    }

    string getName() {   //Геттер
        return book_name;
    }

    void setName(string book_name) {  //Сеттер
        this->book_name = book_name;
    }

    virtual void setShits_value(unsigned int value) {    //Позднее связывание
        this->shits_value = value;
        cout << shits_value;
    }


    void say_Vezhlivo() {    //Расширение поведения
        cout << "Можно мне пожалуйста книжечку неизвестного мне автора, которая называется " << getName();
    }

    virtual void talk() {
        cout << "...";
    }



};

class Librarian : public Library {   //Инкапсуляция при помощи абстракций
private:
    string name;
    unsigned int age;
    unsigned int experience;
public:
    Librarian(string adress, string name, unsigned int age, unsigned int experience) : Library(adress) {
        this->name = name;
        this->age = age;
        this->experience = experience;
    }

    void talk() override {  //Замена поведения
        cout << "Hello";
    }
};

void abstraction(Library* lib){
    lib->talk();
}


int main() {

    Library lib{"Lugovaya"};
    Librarian vasya{"Lugovaya", "Vasya", 20, 2};

    lib.adress = "Ne Lugovaya";
    lib.setName("It");
    lib.getName();
    lib.setShits_value(40);
    lib.say_Vezhlivo();
    vasya.talk();
    vasya.say_Vezhlivo();
    vasya.getName();
    vasya.adress = "Pereezhau...";

    cout << endl << endl;
    abstraction(&lib);
    cout<<endl;
    abstraction(&vasya);

    return 0;
}