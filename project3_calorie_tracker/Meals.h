#ifndef MEALS_H
#define MEALS_H

#include <iostream>

using namespace std;

class Breakfast{
    friend ostream& operator<<(ostream& out, Breakfast& other);
    private:
        int small;
        int medium;
        int large;
    public:
        Breakfast();
        Breakfast(const Breakfast& other);
        Breakfast& operator=(const Breakfast& other);

        Breakfast& operator+(const Breakfast& other);

        int getSmallB();
        int getMediumB();
        int getLargeB();


};
//ostream& operator<<(ostream& out, const Breakfast& other);

class Lunch{
    friend ostream& operator<<(ostream& out, Lunch& other);
    private:
        int small;
        int medium;
        int large;
    public:
        Lunch();
        Lunch(const Lunch& other);
        Lunch& operator=(const Lunch& other);

        Lunch& operator+(const Lunch& other);

        int getSmallL();
        int getMediumL();
        int getLargeL();


};
//ostream& operator<<(ostream& out, const Lunch& other);

class Dinner{
    friend ostream& operator<<(ostream& out, Dinner& other);
    private:
        int small;
        int medium;
        int large;
    public:
        Dinner();
        Dinner(const Dinner& other);
        Dinner& operator=(const Dinner& other);

        Dinner& operator+(const Dinner& other);

        int getSmallD();
        int getMediumD();
        int getLargeD();


};
//ostream& operator<<(ostream& out, const Dinner& other);

#endif // MEALS_H
