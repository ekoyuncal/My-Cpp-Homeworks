#ifndef Doviz_H
#define Doviz_H
#include <iostream>
using namespace std;

class doviz{
	private: 
		double dolar;	
		double euro;
	public:
		doviz();
		doviz(double _dolar, double _euro);
		doviz(const doviz& y);
		doviz& operator =(const doviz& y);
		doviz& operator +(doviz& y);
		
		void set();
		doviz& get();
		double getdolar();
		double geteuro();
};
#endif
