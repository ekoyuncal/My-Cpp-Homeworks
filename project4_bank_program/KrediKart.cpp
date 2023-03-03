#include "KrediKart.h"

	ostream& operator<<(ostream& os,Kart& obj ){
    	os<<"kredi kartinizdaki kullanilabilir tutar: "<<obj.kullanilabilirTutar();
    	return os;
	}
	
    int Kart::kullanilabilirTutar(){
    	return  this->getLimit() - this->getBorc() ;
	}

	Kart::Kart(){
		borc=0;
		limit=0;
	}
	Kart::~Kart(){}
	Kart::Kart(int borc, int limit){
		this->borc=borc;
		this->limit=limit;
	}
	
	Kart::Kart(const Kart &oth){
		borc=oth.borc;
		limit=oth.limit;
	}
	
	Kart& Kart::operator=(const Kart &oth){
		borc=oth.borc;
		limit=oth.limit;
		return *this;
	} 
	
	Kart Kart::operator+(const Kart &oth){
		Kart temp;
		temp.borc=borc+ oth.borc;
		return temp;
	}
	
	void Kart::setBorc(int yeniBorc){
		borc=yeniBorc;
	}
	
	int Kart::getBorc(){
		return borc;
	}
	
	void Kart::setLimit(int limit){
		this->limit=limit;
	}
	
	int Kart::getLimit(){
		return limit;
	}
