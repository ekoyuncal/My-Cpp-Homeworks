#ifndef USER_H
#define USER_H

#include <iostream>

#include "Sports.h"
#include "Meals.h"

using namespace std;

class User{
    friend ostream& operator<<(ostream& out, User& other);
    private:
        //static int hafta;

        string name;
        string sname;
        int id;
        int yas;
        int weight;
        int alinank;
        int verilenk;

        int bSure;
        int fSure;
        int tSure;
        int sSure;

        int brTime;
        int lTime;
        int dTime;
    public:
        Basketball b;
        Football f;
        Tennis t;
        Swimming s;

        Breakfast br;
        Lunch l;
        Dinner d;

        User();
        User(string name, string sname, int id, int yas, int weight);
        User(const User& other);
        User& operator=(const User& other);

        User& operator+(const User& other);

        void addAlinanK();//ogun sor boyut sor alinana ekle
        void addVerilenK();//spor sor  suresor  verilene ekle

        void setAlinanK(int yeniKalori);
        void setVerilenK(int yeniKalori);


        int getAlinanK();
        int getVerilenK();

        string getName();
        string getSname();

        void setbSure(int sayi);
        void setfSure(int sayi);
        void settSure(int sayi);
        void setsSure(int sayi);

        void setbrTime(int sayi);
        void setlTime(int sayi);
        void setdTime(int sayi);

        int getbSure();
        int getfSure();
        int gettSure();
        int getsSure();

        int getbrTime();
        int getlTime();
        int getdTime();


};

//ostream& operator<<(ostream& out, User& other);

#endif // USER_H
