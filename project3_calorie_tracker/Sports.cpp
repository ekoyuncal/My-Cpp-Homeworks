#include "Sports.h"

//-------------Basketball functions--------------

Basketball::Basketball()
{
    kalori=6;
}
Basketball::Basketball(const Basketball& other)
{
    this->kalori=other.kalori;
}
Basketball& Basketball::operator=(const Basketball& other)
{
    if(this != &other){
        this->kalori=other.kalori;
    }
    return *this;
}
Basketball& Basketball::operator+(const Basketball& other)
{
    this->kalori = this->kalori + other.kalori;
    return *this;
}
int Basketball::getBKalori()
{
    return kalori;
}
ostream& operator<<(ostream& out, Basketball& other)
{
    out<<"Basketbol sporu ile yakilan kalori ->"<<other.kalori<<endl;
    return out;
}

//-------------Football functions--------------
Football::Football()
{
    this->kalori=5;
}
Football::Football(const Football& other)
{
    this->kalori=other.kalori;
}
Football& Football::operator=(const Football& other)
{
    if(this != &other){
        this->kalori=other.kalori;
    }
    return *this;
}
Football& Football::operator+(const Football& other)
{
    this->kalori=this->kalori+other.kalori;
    return *this;
}
int Football::getFKalori()
{
    return kalori;
}
ostream& operator<<(ostream& out, Football& other)
{
    out<<"Futbol sporu ile yakilan kalori ->"<<other.kalori;
    return out;
}

//-------------Tennis functions--------------
Tennis::Tennis()
{
    this->kalori=5;
}
Tennis::Tennis(const Tennis& other)
{
    this->kalori=other.kalori;
}
Tennis& Tennis::operator=(const Tennis& other)
{
    if(this != &other){
        this->kalori=other.kalori;
    }
    return *this;
}
Tennis& Tennis::operator+(const Tennis& other)
{
    this->kalori=this->kalori+other.kalori;
    return *this;
}
int Tennis::getTKalori()
{
    return kalori;
}
ostream& operator<<(ostream& out, Tennis& other)
{
    out<<"Tennis sporu ile yakilan kalori ->"<<other.kalori;
    return out;
}

//-------------Swimming functions--------------
Swimming::Swimming()
{
    this->kalori=7;
}
Swimming::Swimming(const Swimming& other)
{
    this->kalori=other.kalori;
}
Swimming& Swimming::operator=(const Swimming& other)
{
    if(this != & other){
        this->kalori=other.kalori;
    }
    return *this;
}
Swimming& Swimming::operator+(const Swimming& other)
{
    this->kalori=this->kalori+other.kalori;
    return *this;
}
int Swimming::getSKalori()
{
    return kalori;
}
ostream& operator<<(ostream& out, Swimming& other)
{
    out<<"Yuzme spor ile yakilan kalori ->"<<other.kalori;
    return out;
}


