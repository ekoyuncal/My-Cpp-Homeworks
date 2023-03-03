#include "User.h"

User::User()
{
    this->name="Empty";
    this->sname="Empty2";
    this->id=0;
    this->yas=0;
    this->weight=0;

    this->alinank=0;
    this->verilenk=0;

    this->bSure=0;
    this->fSure=0;
    this->tSure=0;
    this->sSure=0;

    this->brTime=0;
    this->lTime=0;
    this->dTime=0;
}
User::User(string name, string sname, int id, int yas, int weight)
{
    this->name=name;
    this->sname=sname;
    this->id=id;
    this->yas=yas;
    this->weight=weight;

    this->alinank=0;
    this->verilenk=0;

    this->bSure=0;
    this->fSure=0;
    this->tSure=0;
    this->sSure=0;

    this->brTime=0;
    this->lTime=0;
    this->dTime=0;
}
User::User(const User& other)
{
    this->name=other.name;
    this->sname=other.sname;
    this->id=other.id;
    this->yas=other.yas;
    this->weight=other.weight;

    this->alinank=other.alinank;
    this->verilenk=other.verilenk;

    this->bSure=other.bSure;
    this->fSure=other.fSure;
    this->tSure=other.tSure;
    this->sSure=other.sSure;

    this->brTime=other.brTime;
    this->lTime=other.lTime;
    this->dTime=other.dTime;

}
User& User::operator=(const User& other)
{
    if(this != &other){
        this->name=other.name;
        this->sname=other.sname;
        this->id=other.id;
        this->yas=other.yas;
        this->weight=other.weight;

        this->alinank=other.alinank;
        this->verilenk=other.verilenk;

        this->bSure=other.bSure;
        this->fSure=other.fSure;
        this->tSure=other.tSure;
        this->sSure=other.sSure;

        this->brTime=other.brTime;
        this->lTime=other.lTime;
        this->dTime=other.dTime;

    }
    return *this;
}
User& User::operator+(const User& other)
{
    this->alinank=this->alinank+other.alinank;
    this->verilenk=this->verilenk+other.verilenk;

    return *this;
}
void User::addAlinanK()
{
    int secim;
    int secim2;
    cout<<"Hangi Ogunu girmek istiyorsunuz\n"<<"1.Kahvalti\n"<<"2.Lunch\n"<<"3.Dinner\n"<<endl;
    cin>>secim;
    switch(secim)
    {
        case 1:
            this->brTime++;
            cout<<"Yediginiz yemegin buyuklugu nedir\n"<<"1.Kucuk\n"<<"2.Orta\n"<<"3.Buyuk\n"<<endl;
            cin>>secim2;
            if(secim2==1){alinank=alinank+br.getSmallB();}
            else if(secim2==2){alinank=alinank+br.getMediumB();}
            else if(secim2==3){alinank=alinank+br.getLargeB();}
            break;
        case 2:
            this->lTime++;
            cout<<"Yediginiz yemegin buyuklugu nedir\n"<<"1.Kucuk\n"<<"2.Orta\n"<<"3.Buyuk\n"<<endl;
            cin>>secim2;
            if(secim2==1){alinank=alinank+l.getSmallL();}
            else if(secim2==2){alinank=alinank+l.getMediumL();}
            else if(secim2==3){alinank=alinank+l.getLargeL();}
            break;
        case 3:
            this->dTime++;
            cout<<"Yediginiz yemegin buyuklugu nedir\n"<<"1.Kucuk\n"<<"2.Orta\n"<<"3.Buyuk\n"<<endl;
            cin>>secim2;
            if(secim2==1){alinank=alinank+d.getSmallD();}
            else if(secim2==2){alinank=alinank+d.getMediumD();}
            else if(secim2==3){alinank=alinank+d.getLargeD();}
            break;


    }
    cout<<"Yeni Ogun Basariyla eklendi.."<<endl;
}
void User::addVerilenK()
{
    int secim1;
    int secim2;
    cout<<"Hangi Sporu yaptiniz\n"<<"1.Basketbol\n"<<"2.Futbol\n"<<"3.Tenis\n"<<"4.Yuzme\n"<<endl;
    cin>>secim1;
    switch(secim1)
    {
        case 1:
            cout<<"Sporu ne kadar sure yaptiniz\n"<<endl;
            cin>>secim2;
            this->bSure +=secim2;
            verilenk=verilenk+(secim2*b.getBKalori());
            break;
        case 2:
            cout<<"Sporu ne kadar sure yaptiniz\n"<<endl;
            cin>>secim2;
            this->fSure +=secim2;
            verilenk=verilenk+(secim2*f.getFKalori());
            break;
        case 3:
            cout<<"Sporu ne kadar sure yaptiniz\n"<<endl;
            cin>>secim2;
            this->tSure +=secim2;
            verilenk=verilenk+(secim2*t.getTKalori());
            break;
        case 4:
            cout<<"Sporu ne kadar sure yaptiniz\n"<<endl;
            cin>>secim2;
            this->sSure +=secim2;
            verilenk=verilenk+(secim2*s.getSKalori());
            break;


    }
    cout<<"Yeni spor ve suresi eklendi.."<<endl;
}

int User::getAlinanK(){return alinank;}
int User::getVerilenK(){return verilenk;}

void User::setAlinanK(int yeniKalori){this->alinank=yeniKalori;}
void User::setVerilenK(int yeniKalori){this->verilenk=yeniKalori;}

string User::getName(){return this->name;}
string User::getSname(){return this->sname;}

void User::setbSure(int sayi){this->bSure=sayi;}
void User::setfSure(int sayi){this->fSure=sayi;}
void User::settSure(int sayi){this->tSure=sayi;}
void User::setsSure(int sayi){this->sSure=sayi;}

void User::setbrTime(int sayi){this->brTime=sayi;}
void User::setlTime(int sayi){this->lTime=sayi;}
void User::setdTime(int sayi){this->dTime=sayi;}


int User::getbSure(){return bSure;}
int User::getfSure(){return fSure;}
int User::gettSure(){return tSure;}
int User::getsSure(){return sSure;}


int User::getbrTime(){return brTime;}
int User::getlTime(){return lTime;}
int User::getdTime(){return dTime;}

ostream& operator<<(ostream& out, User& other)
{
    out<<"\nKullanici Adi: "<<other.name<<" "<<other.sname<<" ID: "<<other.id<<" Yas: "<<other.yas<<" Kilo: "<<other.weight<<endl;
    out<<"Alinan Kalori: "<<other.alinank<<" Verilen Kalori: "<<other.verilenk<<endl;
    out<<"Kaydedilen Kahvalti Sayisi: "<<other.brTime<<endl;
    out<<"Kaydedilen Ogle Yemegi Sayisi: "<<other.lTime<<endl;
    out<<"Kaydedilen Aksam Yemegi Sayisi: "<<other.dTime<<endl;
    out<<"Kaydedilen Basketbol Suresi: "<<other.bSure<<endl;
    out<<"Kaydedilen Futbol Suresi: "<<other.fSure<<endl;
    out<<"Kaydedilen Tenis Suresi: "<<other.tSure<<endl;
    out<<"Kaydedilen Yuzme Suresi: "<<other.sSure<<endl;

    return out;
}
