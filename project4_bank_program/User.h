#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "KrediKart.h"
#include "Fatura.h"
#include "Doviz.h"

using namespace std;

class User{
	friend ostream& operator<<(ostream& out,User &oth);
	friend void showKullaniciBilgi(User &oth);
	friend void showKrediKartiBilgi(User &oth);
	friend void showDovizBilgi(User &oth);
	friend void operator+( User& oth);
	private:
		int musNo;
		string musName;
		string musSname;
		int hesapNo;
		int password;
		double bakiye;
		double dolar_bakiye;
		double euro_bakiye;
		double toplamFatura;
		
	public:
		int pwordhak;
		User();
		User(int musNo, string musName, string musSname, int hesapNo, int password, double bakiye, int hak, double dolar, double euro);
		~User();
		User(const User& oth);
		User& operator=(const User& oth);
		
		
		void setmusNo(int yeniNo);
		void setmusName(string yeniName);
		void setmusSname(string yeniSname);
		void setHno(int yeniNo);
		void setPw(int yenipw);	
		void setToplamFatura(double );	
		
		void setBakiye(double yenib);
		void ekleBakiye(int ekleb);
		void cekBakiye(int cekb);
		void setdBakiye(double yenid);
		void seteBakiye(double yenie);
		
		
		int getmusNo();
		string getmusName();
		string getmusSname();
		int getHno();
		int getPw();
		double getBakiye();
		int ispw(int sifre);
		double getDolarb();
		double getEurob();
		double getToplamFatura();
		
		Kart k;
		Elektrik e;
		Su s;
		Dogalgaz d;
		Internet i;
		doviz dov;
};

#endif
