#include "Doviz.h"
doviz::doviz(){
	dolar = 9.0;
	euro = 10.0;
}
doviz::doviz(double _dolar, double _euro)
{
	dolar = _dolar;
	euro = _euro;
}
doviz::doviz(const doviz& y){
	dolar = y.dolar;
	euro = y.euro;
}
doviz& doviz::operator = (const doviz& y)
{
	dolar = y.dolar;
	euro = y.euro;
	return *this;
}
doviz& doviz::operator + (doviz& y)
{
	dolar += y.dolar;;
	euro += y.euro;
	*this;
}

void doviz::set()
{
	cout << "dolar fiyati giriniz" << endl;
	cin >> dolar;
	cout << "euro fiyati giriniz" << endl;
	cin >> euro;
}
double doviz::getdolar(){ return dolar ; }
double doviz::geteuro(){ return euro ; }
