#ifndef FATURA_H
#define FATURA_H
#include <iostream>
using namespace std;
class Elektrik{
	friend ostream& operator<<(ostream& out,Elektrik &oth);
	private:
		double oTutar;
		int eSayac;//Ne kadar Elektrik kullandigini tutsun
		int aboneNo;
		double birimf;
	public:
		Elektrik();
		Elektrik(double oTutar, int eSayac, int aboneNo, double birimf);
		~Elektrik();
		Elektrik(const Elektrik& oth);
		Elektrik& operator=(const Elektrik& oth);
		Elektrik& operator+(const Elektrik& oth);//faturalarý toplar
		
		void setOtutar(double oTutar);
		void setEsayac(int eSayac);
		void setAboneno(int aboneNo);
		void setBirimf(double birimf);
		
		double getOtutar();
		int getEsayac();
		int getAboneno();
		double getBirimf();
};
class Su{
	friend ostream& operator<<(ostream& out,Su &oth);
	private:
		double oTutar;
		int suSayac;
		int aboneNo;
		double birimf;
	public:
		Su();
		Su(double oTutar, int suSayac, int aboneNo, double birimf);
		~Su();
		Su(const Su& oth);
		Su& operator=(const Su& oth);
		Su& operator+(const Su& oth);
		
		void setoTutar(double oTutar);
		void setSusayac(int suSayac);
		void setAboneno(int aboneNo);
		void setBirimf(double birimf);
		
		double getOtutar();
		int getSusayac();
		int getAboneno();
		double getBirimf();		
		
};		
class Dogalgaz{
	friend ostream& operator<<(ostream& out,Dogalgaz &oth);
	private:
		double oTutar;
		int dSayac;
		int aboneNo;
		double birimf;
	public:
		Dogalgaz();
		Dogalgaz(double oTutar, int dSayac, int aboneNo, double birimf);
		~Dogalgaz();
		Dogalgaz(const Dogalgaz& oth);
		Dogalgaz& operator+(const Dogalgaz &oth);
		
		void setoTutar(double oTutar);
		void setDsayac(int dSayac);
		void setAboneno(int aboneNo);
		void setBirimf(double birimf);
		
		double getOtutar();
		int getdsayac();
		int getAboneno();		
		double getBirimf();
	
};
class Internet{
	friend ostream& operator<<(ostream& out,Internet &oth);
	private:
		double oTutar;
		int iSayac;
		int aboneNo;
		double birimf;
	public:
		Internet();
		Internet(double oTutar, int iSayac, int aboneNo, double birimf);
		~Internet();
		Internet(const Internet& oth);
		Internet& operator+(const Internet &oth);
		
		void setoTutar(double oTutar);
		void setisayac(int iSayac);
		void setAboneno(int aboneNo);
		void setBirimf(double birimf);
		
		double getOtutar();
		int getisayac();
		int getAboneno();		
		double getBirimf();
	
};

#endif
