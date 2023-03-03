#include "Meals.h"

//-------------Breakfast functions--------------

Breakfast::Breakfast()
{
    this->small=200;
    this->medium=400;
    this->large=600;
}
Breakfast::Breakfast(const Breakfast& other)
{
    this->small=other.small;
    this->medium=other.medium;
    this->large=other.large;
}
Breakfast& Breakfast::operator=(const Breakfast& other)
{
    if(this != &other){
        this->small=other.small;
        this->medium=other.medium;
        this->large=other.large;
    }
    return *this;
}
Breakfast& Breakfast::operator+(const Breakfast& other)
{
    this->small=this->small+other.small;
    this->medium=this->medium+other.medium;
    this->large=this->large+other.large;

    return *this;
}
int Breakfast::getSmallB(){return this->small;}
int Breakfast::getMediumB(){return this->medium;}
int Breakfast::getLargeB(){return this->large;}

ostream& operator<<(ostream& out, Breakfast& other)
{
    out<<"Kucuk Porsiyon: "<<other.getSmallB()<<"Orta Porsiyon: "<<other.getMediumB()<<"Buyuk Porsiyon"<<other.getLargeB()<<endl;

    return out;
}
//-------------Lunch functions--------------

Lunch::Lunch()
{
    this->small=400;
    this->medium=600;
    this->large=800;
}
Lunch::Lunch(const Lunch& other)
{
    this->small=other.small;
    this->medium=other.medium;
    this->large=other.medium;
}
Lunch& Lunch::operator=(const Lunch& other)
{
    if(this != &other){
        this->small=other.small;
        this->medium=other.medium;
        this->large=other.medium;
    }
    return *this;
}
Lunch& Lunch::operator+(const Lunch& other)
{
    this->small=this->small+other.small;
    this->medium=this->medium+other.medium;
    this->large=this->large+other.large;

    return *this;
}
int Lunch::getSmallL(){return this->small;}
int Lunch::getMediumL(){return this->medium;}
int Lunch::getLargeL(){return this->large;}

ostream& operator<<(ostream& out, Lunch& other)
{
    out<<"Kucuk Porsiyon: "<<other.getSmallL()<<"Orta Porsiyon: "<<other.getMediumL()<<"Buyuk Porsiyon"<<other.getLargeL()<<endl;

    return out;
}
//-------------Dinner functions--------------

Dinner::Dinner()
{
    this->small=400;
    this->medium=600;
    this->large=800;
}
Dinner::Dinner(const Dinner& other)
{
    this->small=other.small;
    this->medium=other.medium;
    this->large=other.large;
}
Dinner& Dinner::operator=(const Dinner& other)
{
    if(this != &other){
        this->small=other.small;
        this->medium=other.medium;
        this->large=other.medium;
    }
    return *this;
}
Dinner& Dinner::operator+(const Dinner& other)
{
    this->small=this->small+other.small;
    this->medium=this->medium+other.medium;
    this->large=this->large+other.large;

    return *this;
}
int Dinner::getSmallD(){return this->small;}
int Dinner::getMediumD(){return this->medium;}
int Dinner::getLargeD(){return this->large;}

ostream& operator<<(ostream& out, Dinner& other)
{
    out<<"Kucuk Porsiyon: "<<other.getSmallD()<<"Orta Porsiyon: "<<other.getMediumD()<<"Buyuk Porsiyon"<<other.getLargeD()<<endl;

    return out;
}
