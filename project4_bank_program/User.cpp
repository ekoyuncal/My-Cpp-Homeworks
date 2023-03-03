#include "User.h"
User::User()
{
	this->musNo=0;
	this->musName="Emptyn";
	this->musSname="Emptys";
	this->hesapNo=0;
	this->password=4444;
	this->bakiye=0;
	dolar_bakiye = 0;
	euro_bakiye = 0;
	pwordhak = 3;
	
}
User::User(int musNo, string musName, string musSname, int hesapNo, int password, double bakiye, int hak, double dolar, double euro)
{
	this->musNo=musNo;
	this->musName=musName;
	this->musSname=musSname;
	this->hesapNo=hesapNo;
	this->password=password;
	this->bakiye=bakiye;
	dolar_bakiye = dolar;
	euro_bakiye = euro;
	pwordhak = hak;
}
User::~User(){}
User::User(const User& oth)
{
	this->musNo=oth.musNo;
	this->musName=oth.musName;
	this->musSname=oth.musSname;
	this->hesapNo=oth.hesapNo;
	this->password=oth.password;
	this->bakiye=oth.bakiye;
	dolar_bakiye = oth.dolar_bakiye;
	euro_bakiye = oth.euro_bakiye;
	pwordhak = oth.pwordhak;		
}
User& User::operator=(const User& oth)
{
	if(this != &oth){
		this->musNo=oth.musNo;
		this->musName=oth.musName;
		this->musSname=oth.musSname;
		this->hesapNo=oth.hesapNo;
		this->password=oth.password;
		this->bakiye=oth.bakiye;
		dolar_bakiye = oth.dolar_bakiye;
		euro_bakiye = oth.euro_bakiye;
		pwordhak = oth.pwordhak;		
		
	}
	return *this;
}
void operator+( User& oth)
{
	//User temp;
	//oth.toplamFatura= oth.e.getOtutar() + oth.d.getOtutar() + oth.s.getOtutar()+ oth.i.getOtutar();
	oth.setToplamFatura(oth.e.getOtutar() + oth.d.getOtutar() + oth.s.getOtutar()+ oth.i.getOtutar());
	cout <<"\n\n\tBu ay icerisinde yapmaniz gereken toplam fatura tutari:  " << oth.getToplamFatura() <<endl;
}
void User::setToplamFatura(double fatura){this->toplamFatura=fatura;}
void User::setmusNo(int yeniNo){this->musNo=yeniNo;}
void User::setmusName(string yeniName){this->musName=yeniName;}
void User::setmusSname(string yeniSname){this->musSname=yeniSname;}
void User::setHno(int yeniNo){this->hesapNo=yeniNo;}
void User::setPw(int yenipw){this->password=yenipw;}

void User::setBakiye(double yenib){this->bakiye=yenib;}
void User::ekleBakiye(int ekleb){this->bakiye+=ekleb;}
void User::cekBakiye(int cekb){
	if(this->bakiye > cekb){
		this->bakiye -=cekb;
	}
}
void User::setdBakiye(double yenid){this->dolar_bakiye=yenid;}
void User::seteBakiye(double yenie){this->euro_bakiye=yenie;}
int User::getmusNo(){return this->musNo;}
string User::getmusName(){return this->musName;}
string User::getmusSname(){return this->musSname;}
int User::getHno(){return this->hesapNo;}
int User::getPw(){return this->password;}
double User::getBakiye(){return this->bakiye;}
double User::getDolarb(){return this->dolar_bakiye;}
double User::getEurob(){return this->euro_bakiye;}
double User::getToplamFatura(){return this->toplamFatura;}

void showKullaniciBilgi(User &oth)
{
	cout<<oth.getmusNo()<<" Numarali Musteri Bilgileri\n"<<endl;
	cout<<"Ad-Soyad -> "<<oth.getmusName()<<" "<<oth.getmusSname()<<endl;
	cout<<"Hesap Numarasi ->"<<oth.getHno()<<endl;
	cout<<"Guncel Bakiye -> "<<oth.getBakiye()<<endl;cout<<endl;	
}
void showKrediKartiBilgi(User &oth)
{
	cout<<"Kredi Karti Guncel Durum\n"<<endl;
	cout<<"Kart Limiti -> "<<oth.k.getLimit()<<endl;
	cout<<"Guncel Borc -> "<<oth.k.getBorc()<<endl;
	cout<<"Kullanilabilir Tutar -> "<<oth.k.kullanilabilirTutar()<<endl;	
}
void showDovizBilgi(User &oth)
{
	cout<<"Doviz Hesabi Guncel Durum\n"<<endl;
	cout<<"Dolar Bakiyesi -> "<<oth.getDolarb()<<endl;
	cout<<"Guncel Dolar Kuru -> "<<oth.dov.getdolar()<<endl;cout<<endl;
	cout<<"Euro Bakiyesi -> "<<oth.getEurob()<<endl;
	cout<<"Guncel Euro Kuru -> "<<oth.dov.geteuro()<<endl;
	
}

ostream& operator<<(ostream& out, User& oth)
{
	out<<oth.getmusNo()<<" Numarali Musteri Bilgileri\n"<<endl;
	out<<"Ad-Soyad -> "<<oth.getmusName()<<" "<<oth.getmusSname()<<endl;
	out<<"Hesap Numarasi ->"<<oth.getHno()<<endl;
	out<<"Guncel Bakiye -> "<<oth.getBakiye()<<endl;cout<<endl;
	
	out<<"Kredi Karti Guncel Durum\n"<<endl;
	out<<"Kart Limiti -> "<<oth.k.getLimit()<<endl;
	out<<"Guncel Borc -> "<<oth.k.getBorc()<<endl;
	out<<"Kullanilabilir Tutar -> "<<oth.k.kullanilabilirTutar()<<endl;
	
	out<<"\n>Fatura Bilgileri<"<<endl;
	out<<oth.e.getAboneno()<<" Numarali Abone\nElektrik Faturasi Guncel Durum"<<endl;
	out<<"Kullanilan Elektrik -> "<<oth.e.getEsayac()<<"kw "<<endl;
	out<<"Odenecek Tutar -> "<<oth.e.getOtutar()<<endl;cout<<endl;
	
	out<<oth.s.getAboneno()<<" Numarali Abone\nSu Faturasi Guncel Durum"<<endl;
	out<<"Kullanilan Su -> "<<oth.s.getSusayac()<<"L "<<endl;
	out<<"Odenecek Tutar -> "<<oth.s.getOtutar()<<endl;cout<<endl;
	
	out<<oth.d.getAboneno()<<" Numarali Abone\nDogalgaz Faturasi Guncel Durum"<<endl;
	out<<"Kullanilan Dogalgaz -> "<<oth.d.getdsayac()<<"mkup "<<endl;
	out<<"Odenecek Tutar -> "<<oth.d.getOtutar()<<endl;cout<<endl;
	
	out<<oth.i.getAboneno()<<" Numarali Abone\nInternet Faturasi Guncel Durum"<<endl;
	out<<"Kullanilan Internet -> "<<oth.i.getisayac()<<"gb "<<endl;
	out<<"Odenecek Tutar -> "<<oth.i.getOtutar()<<endl;cout<<endl;
	
	out<<"Doviz Hesabi Guncel Durum\n"<<endl;
	out<<"Dolar Bakiyesi -> "<<oth.getDolarb()<<endl;
	out<<"Guncel Dolar Kuru -> "<<oth.dov.getdolar()<<endl;cout<<endl;
	out<<"Euro Bakiyesi -> "<<oth.getEurob()<<endl;
	out<<"Guncel Euro Kuru -> "<<oth.dov.geteuro()<<endl;cout<<endl;
	
	return out;
}

int User::ispw(int sifre)
{
	if ( password == sifre)
	{
		return 1;
	}
	else{
		pwordhak--;
		return 0;
	}
}
