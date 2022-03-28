#include <iostream>
using namespace std;

struct Smartphone {
    string name;
    int storageSpace;
    string color;
    float price;
};

struct Person {
    string name;
    int age;
    Smartphone smartphone;
};

void printSmartphoneInfo(Smartphone currentSmartphone){
    cout << "name: " << currentSmartphone.name << endl;
    cout << "storage: " << currentSmartphone.storageSpace << endl;
    cout << "color: " << currentSmartphone.color << endl;
    cout << "price: " << currentSmartphone.price << endl;
}

void printPersonInfo(Person person){
    cout << "name: " << person.name << endl;
    cout << "age: " << person.age << endl;
    cout << "smartphone: " << endl;
    printSmartphoneInfo(person.smartphone);
}

int main() {

    Smartphone s1;
    s1.name = "Iphone 13 pro max";
    s1.storageSpace = 128;
    s1.color = "space Grey";
    s1.price = 1400;

    Smartphone s2;
    s2.name = "Galaxy S212 Ultra";
    s2.storageSpace = 68;
    s2.color = "Black";
    s2.price = 888.88;
    
    Person p;
    p.name = "Jordi";
    p.age = 36;
    p.smartphone = s1;

    printPersonInfo(p);

    system("pause");
    return 0;
}