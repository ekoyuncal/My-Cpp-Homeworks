#include "Sports.h"
#include "Meals.h"
#include "User.h"

using namespace std;

int main(){
    int secimx;
    int secimy;
    int wControl=0;
    cout<<"Kalori Takibi Programina Hosgeldiz !!"<<endl;

    while(wControl==0)
    {
        cout<<"Developer Mode icin 1 User Mode icin 2 yi seciniz ->";cin>>secimy;cout<<endl;
        if(secimy == 1){
            cout<<"Developer Mode Secildi !!\nHangi header file fonksiyonlarini test etmek istiyorsunuz\n1.User\n2.Sports\n3.Meals"<<endl;
            cin>>secimx;cout<<endl;
            if(secimx==1){
                cout<<"User Header Fonksiyonlari Testi"<<endl;
                User testU("Emir", "Demir", 34, 21, 84);
                User testU2;
                testU.setAlinanK(2000);
                testU.setVerilenK(1400);

                testU2=testU;

                User testU3(testU2);

                if(testU.getName() == testU3.getName()){
                    cout<<"TestUser1 name: "<<testU.getName()<<" Kopyalanan TestUser3 name: "<<testU3.getName()<<endl;;
                    cout<<"Copy constuctor basariyla calisti!!\n"<<endl;
                }


                cout<<"Assignment operator testi\n"<<endl;
                if(testU.getAlinanK()== testU2.getAlinanK()){
                    cout<<"Alinan Kaloriler Esit\n"<<endl;
                }
                else if(testU.getAlinanK() != testU2.getAlinanK()){
                    cout<<"Alinan Kaloriler Esit Degil \n"<<endl;
                }
                cout<<"+ operatoru testi\n"<<endl;
                cout<<"Hesaplanmasi gereken yeni degerler -> "<<2*testU.getAlinanK()<<" - "<<2*testU.getVerilenK()<<endl;
                testU=testU+testU3;
                cout<<"Hesaplanan yeni degerler -> "<<testU.getAlinanK()<<" - "<<testU.getVerilenK()<<endl;

                User testU4("Emir", "Malayk", 26, 30, 84);
                testU4.setAlinanK(100);
                cout<<"\nAlinan Kalori ekleme fonksiyonu testi\n"<<endl;
                testU4.addAlinanK();

                cout<<"\nVerilen Kalori ekleme fonksiyonu testi\n"<<endl;
                testU4.addVerilenK();

                cout<<"Set ve Get testleri\n"<<endl;
                cout<<"Alinan kaloriyi 400 Verilen Kaloriyi 600 Yapalim"<<endl;
                testU4.setAlinanK(400);testU4.setVerilenK(600);
                cout<<"Get fonksiyonlariyla Degeri alma testi"<<endl;
                cout<<"Alinan -> "<<testU4.getAlinanK()<<" Verilen -> "<<testU4.getVerilenK()<<endl;;

                cout<<"\nOgun sayaclarinin Set ve Get testleri"<<endl;
                testU4.setbrTime(2);
                testU4.setlTime(1);
                testU4.setdTime(3);

                cout<<"Kahvalti Sayaci -> "<<testU4.getbrTime()<<endl;
                cout<<"Oglen Yemegi Sayaci -> "<<testU4.getlTime()<<endl;
                cout<<"Aksam Yemegi Sayaci -> "<<testU4.getdTime()<<endl;

                cout<<"\nSpor Sure Sayaclarinin Set ve Get testleri"<<endl;
                testU4.setbSure(20);
                testU4.setfSure(12);
                testU4.settSure(30);
                testU4.setsSure(60);

                cout<<"Yapilan Basketbol Suresi -> "<<testU4.getbSure()<<endl;
                cout<<"Yapilan Futbol Suresi -> "<<testU4.getfSure()<<endl;
                cout<<"Yapilan Tenis Suresi -> "<<testU4.gettSure()<<endl;
                cout<<"Yapilan Yuzme Suresi -> "<<testU4.getsSure()<<endl;

                cout<<"\nSon olarak << Operatoru Testi"<<endl;
                cout<<testU4<<endl;

            }
            else if(secimx == 2){
                cout<<"Sports Header Fonksiyonlari Testi"<<endl;
                Basketball b1;
                Basketball b2;
                Football f1;
                Football f2;
                Tennis t1;
                Tennis t2;
                Swimming s1;
                Swimming s2;

                cout<<"\nSpor Siniflarinin Get Testi\n"<<endl;
                cout<<"Dakikada Basketbolda Yakilan Kalori ->"<<b1.getBKalori()<<endl;
                cout<<"Dakikada Futbolda Yakilan Kalori ->"<<f1.getFKalori()<<endl;
                cout<<"Dakikada Teniste Yakilan Kalori ->"<<t1.getTKalori()<<endl;
                cout<<"Dakikada Yuzme ile Yakilan Kalori ->"<<s1.getSKalori()<<endl;

                cout<<"\n+ Operatoru Testi"<<endl;
                cout<<"Eski Kaloriler ->"<<b1.getBKalori()<<" - "<<f1.getFKalori()<<" - "<<t1.getTKalori()<<" - "<<s1.getSKalori()<<endl;
                b1=b1+b2;
                f1=f1+f2;
                t1=t1+t2;
                s1=s1+s2;
                cout<<"Yeni Kaloriler ->"<<b1.getBKalori()<<" - "<<f1.getFKalori()<<" - "<<t1.getTKalori()<<" - "<<s1.getSKalori()<<endl;

                cout<<"\n<< Operatoru Testleri\n"<<endl;
                cout<<b1<<endl;
                cout<<f1<<endl;
                cout<<t1<<endl;
                cout<<s1<<endl;
                cout<<"\n"<<endl;
            }
            else if(secimx == 3){
                cout<<"Meals Header Fonksiyonlari Testi\n\n"<<endl;
                Breakfast br1;
                Breakfast br2;
                Lunch l1;
                Lunch l2;
                Dinner d1;
                Dinner d2;

                cout<<"Kalori verileri Get Testi\n"<<endl;
                cout<<"Kahvalti ogununun Yemek Kalorileri: Kucuk-> "<<br1.getSmallB()<<" Orta-> "<<br1.getMediumB()<<" Buyuk-> "<<br1.getLargeB()<<endl;
                cout<<"Ogle Yemeginin Yemek Kalorileri: Kucuk-> "<<l1.getSmallL()<<" Orta-> "<<l1.getMediumL()<<" Buyuk-> "<<l1.getLargeL()<<endl;
                cout<<"Aksam Yemeginin Yemek Kalorileri: Kucuk-> "<<d1.getSmallD()<<" Orta-> "<<d1.getMediumD()<<" Buyuk-> "<<d1.getLargeD()<<endl;
                cout<<endl;

                cout<<"+ operatoru testi"<<endl;
                cout<<"Eski kaloriler ->"<<br1.getSmallB()<<" - "<<br1.getMediumB()<<" - "<<br1.getLargeB()<<endl;
                br1=br1+br2;
                //l1=l1+l2;
                //d1=d1+d2;
                cout<<"Yeni kaloriler ->"<<br1.getSmallB()<<" - "<<br1.getMediumB()<<" - "<<br1.getLargeB()<<endl;

                cout<<"\n<< Operatoru Testi"<<endl;
                cout<<br1<<endl;
                cout<<l1<<endl;
                cout<<d1<<endl;

            }
        }
        else if(secimy ==2){
            cout<<"User Mode Secildi !!\n"<<endl;
            int wControl2=0;
            int secimz=0;
            int ghafta;
            string isim;
            string sisim;
            int num;
            int yas;
            int kilo;
            cout<<"Kullanici olarak Degerlerinizi Asagidaki Sirayla Giriniz"<<endl;
            cout<<"Hafta->";cin>>ghafta;cout<<endl;
            cout<<"Isim->";cin>>isim;cout<<endl;
            cout<<"Soyisim->";cin>>sisim;cout<<endl;
            cout<<"ID->";cin>>num;cout<<endl;
            cout<<"Yas->";cin>>yas;cout<<endl;
            cout<<"Kilo->";cin>>kilo;cout<<endl;
            cout<<endl;
            User u1(isim, sisim, num, yas, kilo);
            while(wControl2==0){
                cout<<"Ogun Girmek icin 1\nSpor Girmek icin 2\n"<<endl;
                cin>>secimz;

                if(secimz==1){
                        u1.addAlinanK();

                }
                if(secimz==2){
                    u1.addVerilenK();
                }
                wControl2++;
                cout<<"Tekrar Ogun veya Spor Girmek Istiyorsaniz 0 a devam etmek icin 99 a basiniz";cin>>wControl2;cout<<endl;
            }
            cout<<"Girdiginiz Veriler Kaydedildi..\n"<<endl;

            cout<<ghafta<<". Haftanin Kayitli Verileri"<<endl;
            cout<<u1<<endl;
            /*
            cout<<"Ogun Sayilari"<<endl;
            cout<<"Kahvalti: "<<u1.getbrTime()<<endl;
            cout<<"Ogle Yemegi:"<<u1.getlTime()<<endl;

            cout<<"Sporlar Ve Yapilma Sureleri"<<endl;
            cout<<"Basketbol: "<<u1.getbSure()<<endl;
            cout<<"Futbol: "<<u1.getfSure()<<endl;
            cout<<"Tenis: "<<u1.gettSure()<<endl;
            cout<<"Yuzme: "<<u1.getsSure()<<endl;

            cout<<"Toplam Alinan Kalori: "<<u1.getAlinanK()<<endl;
            cout<<"Toplam Verilen Kalori: "<<u1.getVerilenK()<<endl;
            */

        }

        wControl++;
        cout<<"Sistemi Tekrar kullanmak istiyorsaniz 0i Tuslayiniz";cin>>wControl;cout<<endl;
    }





	return 0;
}
