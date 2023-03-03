#include <iostream>
#include <string>
#include "Fatura.h"

//ELEKTRÝK
Elektrik::Elektrik(){
	this->oTutar=0.0;
	this->eSayac=0;
	this->aboneNo=0;
	this->birimf=2.1;//SABIT
}
Elektrik::Elektrik(double oTutar, int eSayac, int aboneNo, double birimf){
	this->oTutar=oTutar;
	this->eSayac=eSayac;
	this->aboneNo=aboneNo;
	this->birimf=birimf;
}
Elektrik::Elektrik(const Elektrik& oth){
	oTutar=oth.oTutar;
	eSayac=oth.eSayac;
	aboneNo=oth.aboneNo;
	birimf=oth.birimf;
}
Elektrik& Elektrik::operator=(const Elektrik& oth){
	if(this!=&oth){
		oTutar=oth.oTutar;
		eSayac=oth.eSayac;
		aboneNo=oth.aboneNo;
		birimf=oth.birimf;	
	}
	return *this;
}
Elektrik& Elektrik::operator+(const Elektrik& oth){
	Elektrik temp;
	temp.oTutar=oTutar+oth.oTutar;
	return temp;
}
void Elektrik::setOtutar(double oTutar){
	this->oTutar=oTutar;
}
void Elektrik::setEsayac(int eSayac){
	this->eSayac=eSayac;
}
void Elektrik::setAboneno(int aboneNo){
	this->aboneNo=aboneNo;
}
void Elektrik::setBirimf(double birimf){
	this->birimf=birimf;
}

double Elektrik::getOtutar(){
	return this->oTutar;
}
int Elektrik::getEsayac(){
	return this->eSayac;
}
int Elektrik::getAboneno(){
	return this->aboneNo;
}
double Elektrik::getBirimf(){
	return this->birimf;
}
ostream& operator<<(ostream& out,Elektrik &oth){
	cout<<"\n>Fatura Bilgileri<"<<endl;
	cout<<oth.getAboneno()<<" Numarali Abone\nElektrik Faturasi Guncel Durum"<<endl;
	cout<<"Kullanilan Elektrik -> "<<oth.getEsayac()<<"kw "<<endl;
	cout<<"Odenecek Tutar -> "<<oth.getOtutar()<<endl;cout<<endl;
}

//SU
Su::Su(){
	this->oTutar=0.0;;
	this->suSayac=0;
	this->aboneNo=0;
	this->birimf=5.1;//SABIT
	
}
Su::Su(double oTutar, int suSayac, int aboneNo, double birimf){
	this->oTutar=oTutar;
	this->suSayac=suSayac;
	this->aboneNo=aboneNo;
	this->birimf=birimf;
}
Su::Su(const Su& oth){
	oTutar=oth.oTutar;
	suSayac=oth.suSayac;
	aboneNo=oth.aboneNo;
	birimf=oth.birimf;
}
Su& Su::operator=(const Su& oth){
	if(this!=&oth){
		oTutar=oth.oTutar;
		suSayac=oth.suSayac;
		aboneNo=oth.aboneNo;
		birimf=oth.birimf;	
	}
	return *this;
}
Su& Su::operator+(const Su& oth){
	Su temp;
	temp.oTutar=oTutar+oth.oTutar;
	return temp;
}

void Su::setoTutar(double oTutar){
	this->oTutar=oTutar;
}
void Su::setSusayac(int suSayac){
	this->suSayac=suSayac;
}
void Su::setAboneno(int aboneNo){
	this->aboneNo=aboneNo;
}
void Su::setBirimf(double birimf){
	this->birimf=birimf;
}

double Su::getOtutar(){
	return oTutar;
}
int Su::getSusayac(){
	return this->suSayac;
}
int Su::getAboneno(){
	return this->aboneNo;
}
double Su::getBirimf(){
	return this->birimf;
}
ostream& operator<<(ostream& out,Su &oth){
	cout<<oth.getAboneno()<<" Numarali Abone\nSu Faturasi Guncel Durum"<<endl;
	cout<<"Kullanilan Su -> "<<oth.getSusayac()<<"L "<<endl;
	cout<<"Odenecek Tutar -> "<<oth.getOtutar()<<endl;cout<<endl;
}

//DOÐALGAZ
Dogalgaz::Dogalgaz(){
	oTutar=0.0;
	dSayac=0;
	aboneNo=0;
	birimf=11.3;
}
Dogalgaz::Dogalgaz(double oTutar, int dSayac, int aboneNo,double birimf){
	this->oTutar=oTutar;
	this->dSayac=dSayac;
	this->aboneNo=aboneNo;
	this->birimf=birimf;
}
Dogalgaz::Dogalgaz(const Dogalgaz& oth){
	oTutar=oth.oTutar;
	dSayac=oth.dSayac;
	aboneNo=oth.aboneNo;
	birimf=oth.birimf;
}
Dogalgaz& Dogalgaz::operator+(const Dogalgaz &oth){
	Dogalgaz temp;
	temp.oTutar=oTutar+oth.oTutar;
	return temp;
}
void Dogalgaz::setoTutar(double oTutar){
	this->oTutar=oTutar;
}
void Dogalgaz::setDsayac(int dSayac){
	this->dSayac=dSayac;
}
void Dogalgaz::setAboneno(int aboneNo){
	this->aboneNo=aboneNo;
}
void Dogalgaz::setBirimf(double birimf){
	this->birimf=birimf;
}

double Dogalgaz::getOtutar(){
	return this->oTutar;
}
int Dogalgaz::getdsayac(){
	return this->dSayac;
}
int Dogalgaz::getAboneno(){
	return this->aboneNo;
}
double Dogalgaz::getBirimf(){
	return this->birimf;
}
ostream& operator<<(ostream& out,Dogalgaz &oth){
	cout<<oth.getAboneno()<<" Numarali Abone\nDogalgaz Faturasi Guncel Durum"<<endl;
	cout<<"Kullanilan Dogalgaz -> "<<oth.getdsayac()<<"mkup "<<endl;
	cout<<"Odenecek Tutar -> "<<oth.getOtutar()<<endl;cout<<endl;
}

//ÝNTERNET
Internet::Internet(){
	oTutar=0.0;
	iSayac=0;
	aboneNo=0;
	birimf=6.2;//SABIT
}
Internet::Internet(double oTutar, int iSayac, int aboneNo, double birimf){
	this->oTutar=oTutar;
	this->iSayac=iSayac;
	this->aboneNo=aboneNo;
	this->birimf=birimf;
}
Internet::Internet(const Internet& oth){
	oTutar=oth.oTutar;
	iSayac=oth.iSayac;
	aboneNo=oth.aboneNo;
	birimf=oth.birimf;
}
Internet& Internet::operator+(const Internet &oth){
	Internet temp;
	temp.oTutar=oTutar+oth.oTutar;
	return temp;
}

void Internet::setoTutar(double oTutar){
	this->oTutar=oTutar;
}
void Internet::setisayac(int iSayac){
	this->iSayac=iSayac;
}
void Internet::setAboneno(int aboneNo){
	this->aboneNo=aboneNo;
}
void Internet::setBirimf(double birimf){
	this->birimf=birimf;
}

double Internet::getOtutar(){
	return this->oTutar;
}
int Internet::getisayac(){
	return this->iSayac;
}
int Internet::getAboneno(){
	return this->aboneNo;
}
double Internet::getBirimf(){
	return this->birimf;
}
ostream& operator<<(ostream& out,Internet &oth){
	cout<<oth.getAboneno()<<" Numarali Abone\nInternet Faturasi Guncel Durum"<<endl;
	cout<<"Kullanilan Internet -> "<<oth.getisayac()<<"gb "<<endl;
	cout<<"Odenecek Tutar -> "<<oth.getOtutar()<<endl;cout<<endl;	
}

Internet::~Internet(){}
Elektrik::~Elektrik(){}
Dogalgaz::~Dogalgaz(){}
Su::~Su(){}
