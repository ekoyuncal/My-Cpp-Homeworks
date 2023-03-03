#ifndef SPORTS_H
#define SPORTS_H

#include <iostream>

using namespace std;

class Basketball{
    friend ostream& operator<<(ostream& out, Basketball& other);
    private:
        int kalori;
        //int sure;
    public:
        Basketball();
        Basketball(const Basketball& other);
        Basketball& operator=(const Basketball& other);

        Basketball& operator+(const Basketball& other);

        int getBKalori();


};
//ostream& operator<<(ostream& out, Basketball& other);

class Football{
    friend ostream& operator<<(ostream& out, Football& other);
    private:
        int kalori;
        //int sure;
    public:
        Football();
        Football(const Football& other);
        Football& operator=(const Football& other);

        Football& operator+(const Football& other);

        int getFKalori();


};
//ostream& operator<<(ostream& out, Football& other);

class Tennis{
    friend ostream& operator<<(ostream& out, Tennis& other);
    private:
        int kalori;
        //int sure;
    public:
        Tennis();
        Tennis(const Tennis& other);
        Tennis& operator=(const Tennis& other);

        Tennis& operator +(const Tennis& other);

        int getTKalori();



};
//ostream& operator<<(ostream& out, Tennis& other);

class Swimming{
    friend ostream& operator<<(ostream& out, Swimming& other);
    private:
        int kalori;
        //int sure;
    public:
        Swimming();
        Swimming(const Swimming& other);
        Swimming& operator=(const Swimming& other);

        Swimming& operator +(const Swimming& other);

        int getSKalori();


};
//ostream& operator<<(ostream& out, Swimming& other);

#endif // SPORTS_H
