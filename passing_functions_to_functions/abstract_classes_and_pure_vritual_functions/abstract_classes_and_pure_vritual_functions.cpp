#include <iostream>

class Animal
{
public:
    virtual void run() = 0;
    virtual void speak() = 0;
};

class Dog : public Animal
{
public:
    virtual void speak()
    {
        std::cout << "Woof" << std::endl;
    }
};

class Labrador : public Dog
{
public:
    virtual void run()
    {
        std::cout << "Labrador running" << std::endl;
    }
};

void func(Animal& a)
{
    a.run();
}

int main()
{
    //Animal animal; // Wrong
    //Dog dog; // Wrong

    Labrador labrador;
    labrador.speak();
    labrador.run();

    //Animal animals[5]; // Wrong
    Animal* animals[5];
    animals[0] = &labrador;
    animals[0]->speak();
    animals[0]->run();

    func(labrador);
}
