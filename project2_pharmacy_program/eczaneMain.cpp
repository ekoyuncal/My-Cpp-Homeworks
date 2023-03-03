#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;

class Ilac{
	private:
		int ilac_id;
		int ilac_stock;
		double ilac_price;
		char ilac_name[20];

	public:
		Ilac()
		{
			//Default constructor
			ilac_id=0;
			ilac_stock=0;
			ilac_price=0;
			strcpy(ilac_name,"Isimlendirilmedi");
		}
		Ilac(int id, int stock, double price, char name[20])
		{
			//Constructor w parameter
			ilac_id= id;
			ilac_stock=stock;
			ilac_price=price;
			strcpy(ilac_name,name);
		}
		Ilac(const Ilac& other)
		{
			//Copy constructor
			ilac_id=other.ilac_id;
			ilac_stock=other.ilac_stock;
			ilac_price=other.ilac_price;
			strcpy(ilac_name,other.ilac_name);
		}
		Ilac& operator= (const Ilac& other)
		{
			//Assignment operator
			this->ilac_id=other.ilac_id;
			this->ilac_stock=other.ilac_stock;
			this->ilac_price=other.ilac_price;
			strcpy(this->ilac_name,other.ilac_name);
			return *this;
		}
		~Ilac()
		{

		}

		void setIlacId(int id)
		{
			ilac_id=id;
		}
		void setIlacStock(int stock)
		{
			ilac_stock=stock;
		}
		void setIlacPrice(double price)
		{
			ilac_price=price;
		}
		void setIlacName(char name[20])
		{
			strcpy(ilac_name,name);
		}

		int getIlacId()
		{
			return ilac_id;
		}
		int getIlacStock()
		{
			return ilac_stock;
		}
		double getIlacPrice()
		{
			return ilac_price;
		}
		string getIlacName()
		{
			return ilac_name;
		}

		void PrintIlac()
		{
			cout<<"->"<<ilac_id<<" "<<ilac_name<<" "<<ilac_price<<" \t"<<ilac_stock<<endl;
		}

		//void createIlac();
		void showIlac();
		void changeIlac();
        void showAllIlac();
        void showIlacwParameter(string givenName,string givenIlacName);
        void searchIlacs();
};


class Eczane
{
	private:

		int eczn_id;
		char eczn_name[20];
		char eczn_adres[20];

	public:
		Eczane()
		{
			//Default constructor
			eczn_id=0;
			strcpy(eczn_name,"EmptyName");
			strcpy(eczn_adres,"EmptyAddress");
		}
		Eczane(int id, char name[20], char adres[20])
		{
			//Constructor w parameter
			eczn_id=id;
			strcpy(eczn_name,name);
			strcpy(eczn_adres,adres);
		}
		Eczane(const Eczane& other)
		{
			//Copy Constructor
			eczn_id=other.eczn_id;
			strcpy(eczn_name,other.eczn_name);
			strcpy(eczn_adres,other.eczn_adres);
		}
		Eczane& operator = (const Eczane& other)
		{
			//Assignment operator
			this->eczn_id=other.eczn_id;
			strcpy(this->eczn_name,other.eczn_name);
			strcpy(this->eczn_adres,other.eczn_adres);
			return *this;
		}
		~Eczane()
		{

		}

		void setEczaneId(int id)
		{
			eczn_id=id;
		}
		void setEczaneName(char name[20])
		{
			strcpy(eczn_name,name);
		}
		void setEczaneAdres(char adres[20])
		{
			strcpy(eczn_adres,adres);
		}

		int getEczaneId()
		{
			return eczn_id;
		}
		string getEczaneName()
		{
			return eczn_name;
		}
		string getEczaneAdres()
		{
			return eczn_adres;
		}
		void getFromUser()
		{
			cout<<"\nEnter ID: ";
			cin>>eczn_id;

			cout<<"\nEnter Name: ";
			//cin.ignore();
			//getline(cin,eczn_name);//cin>>eczn_name;
            scanf(" %[^\n]", eczn_name);
            cout<<eczn_name<<endl;
			cout<<"\nEnter Address: ";
			//cin.ignore();
			//getline(cin,eczn_adres);//cin>>eczn_adres;
            scanf(" %[^\n]", eczn_adres);
            cout<<eczn_adres<<endl;
		}


		void PrintEczane()
		{
			cout<<"\n\t"<<eczn_id<<"\t"<<eczn_name<<"\t"<<eczn_adres;
		}

		//void createEczane();
		void writeEczane();
		void showEczane();
		void showAllEczane();
		void createEczaneIlac(int ilacid, int ilacstok, double ilacprice, char ilacname[20]);
		void eczaneList();
		/*
		void printData()
		{
			cout<<"\n\t"<<eczn_id<<"\t"<<eczn_name<<"\t"<<eczn_adres;
		}*/

};
/*void Eczane::createEczane()
{
	fstream liste;
	Eczane ecz;

	liste.open("eczane_listesi.dat",ios::out|ios::binary);

	if(!liste.is_open())
	{
		cout<<"Opening failed please shut down system and try again\n";
		exit(0);
	}

	ecz.getFromUser();
	liste.write((char*)&ecz, sizeof(ecz));

	liste.close();

}*/
void Eczane::writeEczane()
{
	ofstream liste;
	liste.seekp(0);
	liste.open("eczane_listesi.dat",  ios::in | ios::out | ios::app | ios::binary);
	liste.write((char*)this, sizeof(Eczane));

	liste.close();


}
void Eczane::showEczane()
{
	fstream liste;
	int sayac=0;
	string givenName;
	liste.open("eczane_listesi.dat",ios::in|ios::binary);

	if(!liste.is_open())
	{
		cout<<"Opening failed please shut down system and try again\n";
		exit(0);
	}
	cout<<"Please Enter Pharmacy's Name ->";
	cin>>givenName;
	cout<<"\n";
	cout<<"\n\tID\tName\tAddress\n";
	while(liste.peek() != EOF)
	{
		liste.read((char*)this, sizeof(Eczane));
		if(this->eczn_name== givenName)
		{
			this->PrintEczane();
			liste.close();
			sayac=1;
		}

	}
	if(sayac==0)
	{
		cout<<givenName<<" isimli Eczane bulunamadi"<<endl;
	}

}
void Eczane::showAllEczane()
{
	fstream liste;
	liste.open("eczane_listesi.dat",ios::in|ios::binary);

	if(!liste.is_open())
	{
		cout<<"Opening failed please shut down system and try again\n";
		exit(0);
	}
	cout<<"\n\tID\tName\tAddress\n";
	while(liste.peek() != EOF)
	{
		liste.read((char*)this, sizeof(*this));
		this->PrintEczane();
	}
	cout<<endl;
}
void Eczane::createEczaneIlac(int ilacid, int ilacstok, double ilacprice, char ilacname[20])
{
    Eczane ecz;
    string isim;
    int sayac;
    string givenName;//this->getEczaneName();
    char* ilacListeName=&isim[0];//this->getEczaneName();
    int secim=0;

    fstream liste;
    liste.open("eczane_listesi.dat",ios::in|ios::binary);

    cout<<"Lutfen eklemek istediginiz eczaneyi giriniz->";cin>>givenName;cout<<endl;


    if(!liste.is_open())
	{
		cout<<"Opening failed please shut down system and try again\n";
		exit(0);
	}
    while(liste.peek() != EOF)
	{
		liste.read((char*)&ecz, sizeof(Eczane));
		if(ecz.getEczaneName()== givenName)
		{
		    isim=ecz.getEczaneName();
		    char* ilacListeName=&isim[0];
			liste.close();
			sayac=1;
		}

	}
    if(sayac==0)
	{
		cout<<givenName<<" isimli Eczane bulunamadi"<<endl;
		liste.close();
	}
	else{
        strcat(ilacListeName,"_ilac.dat");
        ofstream ilacListe;
        ilacListe.seekp(0);
        ilacListe.open(ilacListeName,  ios::in | ios::out | ios::app | ios::binary);

        Ilac tempIlac(ilacid,ilacstok,ilacprice,ilacname);

        ilacListe.write((char*)&tempIlac, sizeof(Ilac));

        ilacListe.close();
	}

}


void Ilac::showIlac()
{
    Eczane ecz;
    fstream liste;
    int sayac=0;
    string givenName;
    string givenIlacName;
    cout<<"Lutfen Hangi eczanede ilac aramak istediginizi giriniz!";
    cin>>givenName;cout<<endl;
    char* ilacListeName=&givenName[0];
    liste.open("eczane_listesi.dat",ios::in|ios::binary);

    if(!liste.is_open())
	{
		cout<<"Opening failed please shut down system and try again\n";
		exit(0);
	}
    while(liste.peek() != EOF)
	{
		liste.read((char*)&ecz, sizeof(Eczane));
		if(ecz.getEczaneName()== givenName)
		{

			liste.close();
			sayac=1;
		}

	}
    if(sayac==0)
	{
		cout<<givenName<<" isimli Eczane bulunamadi"<<endl;
		liste.close();
	}
	else if(sayac ==1)
    {
        strcat(ilacListeName,"_ilac.dat");
        int sayac2=0;
        fstream iListe;
        iListe.open(ilacListeName,ios::in|ios::binary|ios::app);
        cout<<"Aradiginiz ilacin ismini giriniz!..";
        cin>>givenIlacName;cout<<endl;
        if(!iListe.is_open())
        {
		cout<<"Opening failed please shut down system and try again\n";
		exit(0);
        }
        cout<<"\nID\tName\tPrice\tStock\t\n";
        while(iListe.peek() != EOF)
        {
            iListe.read((char*)this, sizeof(Ilac));
            if(this->ilac_name== givenIlacName)
            {
                this->PrintIlac();
                liste.close();
                sayac2=1;
            }

        }
        if(sayac2==0)
        {
            cout<<givenIlacName<<" isimli ilac bulunamadi"<<endl;

        }
    }
}
void Ilac::changeIlac()
{
    int sayac=0;
    int flag=0;
    int secim=0;
    Eczane ecz;
    string givenName;
    string givenIlacName;
    cout<<"Lutfen Hangi eczanede ilac aramak istediginizi giriniz!"<<endl;
    cin>>givenName;cout<<endl;
    char* ilacListeName=&givenName[0];
    fstream liste;
    liste.open("eczane_listesi.dat",ios::in|ios::binary);

    if(!liste.is_open())
	{
		cout<<"Opening failed please shut down system and try again\n";
		exit(0);
	}
    while(liste.peek() != EOF)
	{
		liste.read((char*)&ecz, sizeof(Eczane));
		if(ecz.getEczaneName()== givenName)
		{
			liste.close();
			sayac=1;
		}

	}
    if(sayac==0)
	{
		cout<<givenName<<" isimli Eczane bulunamadi"<<endl;
		liste.close();
	}
	else if(sayac ==1)
    {
        strcat(ilacListeName,"_ilac.dat");
        int sayac2=0;
        string givenIlacName;
        cout<<"Degistirmek istediginiz ilacin ismini giriniz!..";
        cin>>givenIlacName;cout<<endl;

        ifstream ifs;
        ifs.open(ilacListeName, ios::in | ios::binary);

        ofstream ofs;
        ofs.open("Temp.dat",ios::out | ios::binary);

        while(ifs.peek() != EOF)
        {
            ifs.read((char*)this, sizeof(Ilac));

            if(this->ilac_name == givenIlacName && flag == 0)
            {
                flag=1;
                int altSecim=99;
                cout<<"Duzeltmek istediginiz alani seciniz.."<<endl;
                cout<<"1.ID Degisikligi\n2.Stok Sayisi Degisikligi\n3.Fiyat Degisikligi\n4.Listeden Kaldirma\n\n";
                cin>>secim;cout<<endl;

                if(secim==1){
                    cout<<"Yeni ID yi giriniz";cin>>altSecim;cout<<endl;
                    this->ilac_id=altSecim;
                    ofs.write((char*)this, sizeof(Ilac));
                }
                if(secim==2){
                    cout<<"Yeni stok sayisini giriniz";cin>>altSecim;cout<<endl;
                    this->ilac_stock=altSecim;
                    ofs.write((char*)this, sizeof(Ilac));
                }
                if(secim==3){
                    cout<<"Yeni fiyati giriniz";cin>>altSecim;cout<<endl;
                    this->ilac_price=altSecim;
                    ofs.write((char*)this, sizeof(Ilac));
                }
                if(secim==4){

                }
                cout<<"Degisiklik gerceklesti!.."<<endl;
                this->PrintIlac();
            }
            else if(this->ilac_name != givenIlacName){
                ofs.write((char*)this, sizeof(Ilac));

            }

        }
        ifs.close();
        ofs.close();

        remove(ilacListeName);
        rename("Temp.dat",ilacListeName);

    }
}
void Ilac::showAllIlac()
{
    int sayac=0;
    int sayac2=0;
    Eczane ecz;
    fstream liste;
    char givenName[20];
    cout<<"Lutfen Hangi eczanede aramak istediginizi giriniz!->";
    scanf(" %[^\n]", givenName);/*cin>>givenName;*/cout<<endl;
    //char* ilacListeName=&givenName[0];
    char ilacListeName[20];
    strcpy(ilacListeName,givenName);
    strcat(ilacListeName,"_ilac.dat");
    liste.open(ilacListeName,ios::in|ios::binary|ios::app);

    fstream eliste;
    eliste.open("eczane_listesi.dat",ios::in|ios::binary);

    if(!eliste.is_open())
	{
		cout<<"Opening failed please shut down system and try again\n";
		exit(0);
	}
    while(eliste.peek() != EOF)
	{
		eliste.read((char*)&ecz, sizeof(ecz));
		if(ecz.getEczaneName()== givenName)
		{
		    //cout<<ecz.getEczaneName()<<endl;
			eliste.close();
			sayac=1;
		}

	}
    if(sayac==0)
	{
		cout<<givenName<<" isimli Eczane bulunamadi"<<endl;
		exit(0);
	}

    if(!liste.is_open())
	{
		cout<<"Opening failed please shut down system and try again\n";
		exit(0);
	}
	cout<<"\nID\tName\tPrice\tStock\t\n";
	while(liste.peek() != EOF)
	{
		liste.read((char*)this, sizeof(*this));

        this->PrintIlac();
        sayac2++;
	}
	cout<<endl;
	liste.close();
	if(sayac2==0){

        cout<<"Kayitli ilac bulunamadi"<<endl;
	}
}
void Ilac::showIlacwParameter(string givenName,string givenIlacName)
{
    int sayac2=0;
    fstream iListe;
    string eczAdi;
    iListe.open(givenName.c_str(),ios::in|ios::binary|ios::app);

    if(!iListe.is_open())
    {
        cout<<"Opening failed please shut down system and try again\n";
        exit(0);
    }
    eczAdi=givenName.erase(givenName.size()-9);//_ilac.dat
    cout<<"Eczane Adi-> "<<eczAdi;

    while(iListe.peek() != EOF)
    {
        iListe.read((char*)this, sizeof(Ilac));
        if(this->ilac_name== givenIlacName)
        {
            cout<<"\nID\tName\tPrice\tStock\t\n";
            this->PrintIlac();
            iListe.close();
            sayac2=1;
        }

    }
    if(sayac2==0)
    {
        cout<<"\n"<<givenIlacName<<" isimli ilac bulunamadi"<<endl;

    }
    cout<<"\n"<<endl;
}
void Ilac::searchIlacs()
{
    Eczane ecz;
    Ilac ilac;
    int i=0;
    string eczIsimleri[5];
    ifstream liste;
    //ifstream iListe;
    int sayac=0;
    int iSize=0;
    string eczName;
    string givenIlacName;
    cout<<"Aradiginiz ilacin ismini giriniz!..";
    cin>>givenIlacName;cout<<endl;

    liste.open("eczane_listesi.dat",ios::in|ios::binary);

    if(!liste.is_open())
	{
		cout<<"Opening failed please shut down system and try again\n";
		exit(0);
	}

    while(liste.peek() != EOF)
	{
		liste.read((char*)&ecz, sizeof(Eczane));
        eczName=ecz.getEczaneName();


        char* ilacListeName=&eczName[0];

        strcat(ilacListeName,"_ilac.dat");
        eczIsimleri[i]=ilacListeName;
        iSize++;

        i++;
	}


    for(i=0;i<iSize;i++)
    {
        ilac.showIlacwParameter(eczIsimleri[i],givenIlacName);
    }

}




int main(){
    int SuperPassword=265432;
    int givenPassword=0;
    int givenID;
    int sayac=0;
    string givenName;
    string givenAdres;
	int secim=0;

	Ilac ilac;

	Eczane ecz;
	/*
    Eczane ecz1(1,"Faruk","Tepebasi");
	Eczane ecz2(2,"Emir","Eskisehir");
	Eczane ecz3(3,"Damla","Visnelik");
    {
    ecz1.createEczaneIlac(1,8,7.99,"Roaccutane");
	ecz1.createEczaneIlac(2,99,11.29,"Selectra");
	ecz1.createEczaneIlac(3,46,48.49,"Epizonya");
	ecz1.createEczaneIlac(4,22,29.29,"Majezik");
	ecz1.createEczaneIlac(5,12,3.25,"Zolonic");
	ecz1.createEczaneIlac(6,45,37.99,"Yondelis");
	ecz1.createEczaneIlac(7,67,78.78,"Calpol");

    ecz2.createEczaneIlac(1,66,55.55,"Vidaptin");
	ecz2.createEczaneIlac(2,40,11.29,"Selectra");
	ecz2.createEczaneIlac(3,11,3.49,"Magnorm");
	ecz2.createEczaneIlac(4,90,29.29,"Majezik");
	ecz2.createEczaneIlac(5,20,456.89,"Dodex");
	ecz2.createEczaneIlac(6,60,2000.10,"Arveles");

	ecz3.createEczaneIlac(1,17,7.99,"Roaccutane");
	ecz3.createEczaneIlac(2,8,11.29,"Selectra");
	ecz3.createEczaneIlac(3,11,3.49,"Magnorm");
	ecz3.createEczaneIlac(4,3,29.29,"Majezik");
	ecz3.createEczaneIlac(5,1,12.25,"Metpamid");
	ecz3.createEczaneIlac(6,45,229.99,"Tetradox");
	ecz3.createEczaneIlac(7,67,78.78,"Calpol");
	ecz3.createEczaneIlac(8,2,456.89,"Dodex");
	ecz3.createEczaneIlac(9,0,2000.10,"Arveles");
    }
    */
	while(secim != 99)
	{
		cout<<"Eczane Programina Hosgeldiniz\n"<<endl;
		cout<<"1.Eczane Girisi\n2.Musteri Girisi"<<endl<<endl;
		cout<<"Eczane Girisi icin 1 Musteri Girisi icin 2 yi tuslayiniz\n";
		cin>>secim;
		if(secim==1 and sayac==0){
            cout<<"Yonetici girisi icin size verilen sifreyi giriniz->";cin>>givenPassword;cout<<endl;
            while(givenPassword!=SuperPassword){
                cout<<"Yanlis Sifre Lutfen Yeniden deneyiniz!!!.."<<endl;
                cout<<"Yonetici girisi icin size verilen sifreyi giriniz->";cin>>givenPassword;cout<<endl;
            }
            sayac++;
		}
		switch(secim)
		{
			case 1:
				cout<<"1.Eczane Girisi\n\n1.1Eczane Listesi Olustur\n1.2Eczane Ekle\n1.3Ilac Ekle\n1.4Ilac Duzenle"<<endl<<endl;
				cout<<"Yapmak istediginiz islemin numarasini tuslayiniz"<<endl;
				cin>>secim;
				switch(secim)
				{
					case 1:{
					    cout<<"Sistemde kayitli eczaneler eczane listesine eklendi!"<<endl;
                        //Zaten olusturup odevi size attigim icin tekrar yazdirmadim
                        //ecz1.writeEczane();
                        //ecz2.writeEczane();
                        //ecz3.writeEczane();

						}break;
					case 2:{
                        ecz.getFromUser();
                        ecz.writeEczane();
                        cout<<"Yeni Eczane basariyla eklendi!"<<endl;

                        cout<<"Kayitli Eczanelerin guncel hali"<<endl;
                        ecz.showAllEczane();
						}break;
					case 3:{
					    cout<<"Eklemek istediginiz ilacin bilgilerini giriniz"<<endl;
					    int ilacid;cout<<"Ilacin ID numarasini giriniz->";cin>>ilacid;cout<<endl;
					    int ilacstok;cout<<"Ilacin Stok sayisini giriniz->";cin>>ilacstok;cout<<endl;
					    double ilacprice;cout<<"Ilacin Fiyatini giriniz->";cin>>ilacprice;cout<<endl;
					    char ilacname[20];cout<<"Ilacin Adini giriniz->";cin>>ilacname;cout<<endl;
						ecz.createEczaneIlac(ilacid, ilacstok, ilacprice, ilacname);
						cout<<"Yeni ilac basariyla eklendi!"<<endl;

						}break;
					case 4:{
						ilac.changeIlac();
						}break;
				}
				break;
			case 2:
				cout<<"2.Musteri Girisi\n\n2.1Ilac Ara\n2.2Eczaneleri Listele\n2.3Bir Eczane Goster\n2.4Bir Eczanenin Ilac Listesi "<<endl<<endl;
				cout<<"Yapmak istediginiz islemin numarasini tuslayiniz"<<endl;
				cin>>secim;
				switch(secim){
					case 1:{
					    ilac.searchIlacs();
						}break;
					case 2:{
						//eczaneleri listele
						ecz.showAllEczane();
						}break;
					case 3:{
						//eczaneleri once listele girilen isme gore o eczaneyi goster
						ecz.showAllEczane();
						ecz.showEczane();
						}break;
					case 4:{
						//eczaneleri listele girilen isme gore o eczanenin ilaclarini goster
						ecz.showAllEczane();
						ilac.showAllIlac();
						//isim al o eczanenin ilac listesini bas
						}break;
				}
				break;
		}
		cout<<"\n\nIslemlere devam etmek istemiyorsaniz 99, devam ediyorsaniz 0 i tuslayiniz\n";
		cin>>secim;
		if(secim==0){system("cls");}
	}

	return 0;

}

