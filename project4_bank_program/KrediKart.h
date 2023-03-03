#ifndef KREDIKART_H
#define KREDIKART_H
#include <iostream>
using namespace std;

class Kart{
	friend ostream& operator<<(ostream& os,Kart& obj );
	private:
		int borc;
		int limit;//kredi kartinin limiti - kullanilabilir bakiye tutari hesaplamak icin 
		
	public:
		Kart();
		Kart(int borc,int limit);
		~Kart();
		Kart(const Kart& oth);
		Kart& operator=(const Kart& oth);
		Kart operator+(const Kart& oth);
		
		void setBorc(int yeniBorc);
		int getBorc();
		
	
		int kullanilabilirTutar();
		void setLimit(int limit);
		int getLimit();		
	
};
#endif
