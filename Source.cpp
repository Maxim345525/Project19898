#include <iostream>
#include <cstring>
using namespace std;
class Person {
private:
    char* name;
public:
    Person() : name(nullptr) {}
    Person(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    Person(const Person& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    ~Person() {
        delete[] name;
    }
    void display() const {
        cout << "Person: " << name << endl;
    }
};
class Apartment {
private:
    Person* residents;
    int numberOfResidents;
public:
    Apartment() : residents(nullptr), numberOfResidents(0) {}
    Apartment(const Person people[], int num) : numberOfResidents(num) {
        residents = new Person[num];
        for (int i = 0; i < num; ++i) {
            residents[i] = people[i];
        }
    }
    Apartment(const Apartment& other) : numberOfResidents(other.numberOfResidents) {
        residents = new Person[numberOfResidents];
        for (int i = 0; i < numberOfResidents; ++i) {
            residents[i] = other.residents[i];
        }
    }
    ~Apartment() {
        delete[] residents;
    }
    void display() const {
        cout << "Apartment residents:" << endl;
        for (int i = 0; i < numberOfResidents; ++i) {
            residents[i].display();
        }
    }
};
class House {
private:
    Apartment* apartments;
    int numberOfApartments;
public:
    House() : apartments(nullptr), numberOfApartments(0) {}
    House(const Apartment flats[], int num) : numberOfApartments(num) {
        apartments = new Apartment[num];
        for (int i = 0; i < num; ++i) {
            apartments[i] = flats[i];
        }
    }
    House(const House& other) : numberOfApartments(other.numberOfApartments) {
        apartments = new Apartment[numberOfApartments];
        for (int i = 0; i < numberOfApartments; ++i) {
            apartments[i] = other.apartments[i];
        }
    }
    ~House() {
        delete[] apartments;
    }
    void display() const {
        cout << "House residents:" << endl;
        for (int i = 0; i < numberOfApartments; ++i) {
            apartments[i].display();
        }
    }
};
int main() {
    Person person1("John Doe");
    Person person2("Jane Smith");
    Person residentsOfApartment[] = { person1, person2 };
    Apartment apartment(residentsOfApartment, 2);
    Apartment apartmentsInHouse[] = { apartment };
    House house(apartmentsInHouse, 1);
    house.display();
    return 0;
}