#include "User.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
int bas_bul(int pword);


int main()
{

	int size=5;
	User* user = new User[size];
	
	user[0].setmusName("Lale");
	user[1].setmusName("Buse");
	user[2].setmusName("Ali");
	user[3].setmusName("Mehmet");
	user[4].setmusName("Mila");
	
	user[0].setmusSname("Gundogan");
	user[1].setmusSname("Dogan");
	user[2].setmusSname("Albayrak");
	user[3].setmusSname("Koyun");
	user[4].setmusSname("Demir");
	
	user[0].setPw(12345);
	user[1].setPw(45678);
	user[2].setPw(41111);
	user[3].setPw(44444);
	user[4].setPw(67891);
	
	user[0].setmusNo(1);
	user[1].setmusNo(2);
	user[2].setmusNo(3);
	user[3].setmusNo(4);
	user[4].setmusNo(5);
	
	user[0].setHno(264571);
	user[1].setHno(264572);
	user[2].setHno(264573);
	user[3].setHno(264574);
	user[4].setHno(264575);
	
	user[0].d.setAboneno(78364291);
	user[1].d.setAboneno(78364292);
	user[2].d.setAboneno(78364293);
	user[3].d.setAboneno(78364294);
	user[4].d.setAboneno(78364295);
	
	user[0].e.setAboneno(67253181);
	user[1].e.setAboneno(67253182);
	user[2].e.setAboneno(67253183);
	user[3].e.setAboneno(67253184);
	user[4].e.setAboneno(67253185);
	
	user[0].i.setAboneno(56142071);
	user[1].i.setAboneno(56142072);
	user[2].i.setAboneno(56142072);
	user[3].i.setAboneno(56142074);
	user[4].i.setAboneno(56142075);
	
	user[0].s.setAboneno(45031961);
	user[1].s.setAboneno(45031962);
	user[2].s.setAboneno(45031963);
	user[3].s.setAboneno(45031964);
	user[4].s.setAboneno(45031965);

	user[0].pwordhak = 3;
	user[1].pwordhak = 3;
	user[2].pwordhak = 3;
	user[3].pwordhak = 3;
	user[4].pwordhak = 3;

	for(int i=0; i<size; i++){
		user[i].setBakiye(rand()%100000);
	}	
	for(int i=0; i<size;i++){
		user[i].d.setDsayac(rand()%100);
		user[i].e.setEsayac(rand()%100);
		user[i].i.setisayac(rand()%100);
		user[i].s.setSusayac(rand()%100);
	}
	for(int i=0; i<size;i++){
		user[i].d.setoTutar(user[i].d.getBirimf()*user[i].d.getdsayac());
		user[i].e.setOtutar(user[i].e.getBirimf()*user[i].e.getEsayac());
		user[i].i.setoTutar(user[i].i.getBirimf()*user[i].i.getisayac());
		user[i].s.setoTutar(user[i].s.getBirimf()*user[i].s.getSusayac());
	}	
	for (int i=0; i<size ; i++){
		user[i].setdBakiye(rand()%100);
		user[i].seteBakiye(rand()%100);
	}
	
	for(int i=0; i<3;i++)
	{
		user[i].k.setBorc(rand()%100);
		user[i].k.setLimit(rand()%1000);
	}

	int no,sifre,sec,sec2;
	int sec3=0;
	int sec4=0;
	int miktar2=0;
	int choice,flag;
	int sifre_status=99, pwordhak = 3;
	cout << "\n\n\t\t\t\t\t*****GEBZE BANKASI*****"<<endl;
	cout << "\n\t\t\t\tGebze Bankasi Internet Bankaciligina Hosgeldiniz!" << endl;
	

	while(flag=1){
		cout << "\n\n  Lutfen musteri numaranizi giriniz" << endl;
		cin >>no;
		if(no>0 && no <6){
			break;
		}
		else{
			cout << "Gecersiz musteri no girdiniz. Tekrar deneyiniz." << endl;
			flag=-1;
		}
	}
	gosifre:	

	for(int i=0; i<size; i++)
	{
		
		
		if(user[i].getmusNo()==no && &user[i].pwordhak)
		{	
			try
			{
			cout << "  Lutfen sifrenizi giriniz." << endl;
			cin >>sifre;
			sifre_status = bas_bul(sifre);
		
			if ( sifre_status == 0)
				throw 0;

			while(user[i].ispw(sifre) == 0  && user[i].pwordhak > 0 )
			{
				cout<<"\tYanlis sifre girdiniz, lutfen yeniden deneyin. \n" << " Kalan deneme hakkiniz " << user[i].pwordhak << endl;
				cin>>sifre;//anahtar dogru girilene kadar kullanicinin anahtari tekrar girmesi istenir
				sifre_status = bas_bul(sifre);
				if ( sifre_status == 0)
					throw 0;
			}
			if( user[i].pwordhak <= 0)
			{
				cout << "\tSifre hakkiniz bittigi icin hesabiniz kilitlenmistir. Lutfen musteri hizmetleri ile iletisime geciniz." << endl;
				goto hakbitti;
			}
			if(user[i].ispw(sifre) && user[i].pwordhak>0 )
			{
				system("cls");
				cout <<"\t\t\nSaglikli Gunler, " <<user[i].getmusName()<<" "<<user[i].getmusSname()<<"\n\n\t\t------------HOSGELDINIZ------------\n"<< endl;
				
			
				cout << "\n\t\tLutfen yapmak istediginiz islemi seciniz." << endl;
				flag = 1;
				while(flag == 1)
				{	
					cout<<endl<<" \t1.Banka hesabi bilgileri goruntule"<< endl<< "\t2.Kredi karti bilgileri goruntule"<<endl
					<< "\t3.Fatura ode "<<endl<< "\t4.Aylik ozet goruntule "<<endl<<"\t5.Para Transferi"<<endl<<"\t6.Doviz Islemleri"<<endl<<"\t7. Cikis"<<endl;
					cin >> choice;
					switch (choice)
					{
						case 1 ://banka hesabi
						system("cls");
							showKullaniciBilgi(user[i]);
							
							break;
						case 2 ://kredi karti
						system("cls");
							showKrediKartiBilgi(user[i]);
							
							break;
						case 3 ://fatura ode
						system("cls");
							cout<<user[i].e;
							cout<<user[i].s;
							cout<<user[i].s;
							cout<<user[i].i;
							cout << "\tLutfen hangi faturayi odemek istediginizi seciniz." << endl << "\t1-Elektrik\n\t2-Su\n\t3-Dogalgaz\n\t4-Internet" << endl;
							cin>>no;
							switch (no)
							{
								case 1 ://elektrik
								system("cls");
									cout << "\n\t\t---Elektrik Faturasi---" << endl;
									cout << "\tOdemeniz gereken tutar->  " << user[i].e.getOtutar() << endl;
									cout << "\tHangi odeme yontemini secersiniz?" << endl << "\t1-Kredi Karti\n\t2-Hesap Karti" << endl;
									cin >>sec;
									if(sec==1)
									{
										cout << "\t---Kredi Karti" << endl;
										if(user[i].e.getOtutar() > user[i].k.kullanilabilirTutar())
										{
											cout << "Fatura tutariniz kullanilabilir tutarinizdan fazladir." << endl;
										}
										else
										{
											int kalan;
											kalan =user[i].k.getLimit()-user[i].e.getOtutar();
											user[i].k.setLimit(kalan);
											cout << "Fatura odemeniz basariyla gerceklesti." << endl << "Kredi kartinizda kalan limit tutari: " << kalan << endl;
											user[i].e.setOtutar(0);
											user[i].e.setEsayac(0);
										}
									}
									else if(sec==2)
									{
										cout << "\t---Hesap karti" << endl;
										if(user[i].e.getOtutar() > user[i].getBakiye())
										{
											cout << "Fatura tutariniz kullanilabilir tutarinizdan fazladir." << endl;
										}
										else
										{
											int kalan;
											kalan =user[i].getBakiye()-user[i].e.getOtutar();
											user[i].setBakiye(kalan);
											cout << "Fatura odemeniz basariyla gerceklesti." << endl << "Hesabinizda kalan bakiye: " << kalan << endl;
											user[i].e.setOtutar(0);
											user[i].e.setEsayac(0);
										}
									}
									
									break;
								case 2 ://su
								system("cls");
									cout << "\n\t\t---Su Faturasi---" << endl;
									cout << "Odenemeniz gereken tutar  " << user[i].s.getOtutar() << endl;
									cout << "\tHangi odeme yontemini secersiniz?" << endl << "\t1-Kredi Karti\n\t2-Hesap Karti" << endl;
									cin >>sec;
									if(sec==1)
									{
										cout << "\t---Kredi karti" << endl;
										if(user[i].s.getOtutar() > user[i].k.kullanilabilirTutar())
										{
											cout << "Fatura tutariniz kullanilabilir tutarinizdan fazladir." << endl;
										}
										else
										{
											int kalan;
											kalan =user[i].k.getLimit()-user[i].s.getOtutar();
											user[i].k.setLimit(kalan);
											cout << "Fatura odemeniz basariyla gerceklesti." << endl << "kredi kartinizda kalan limit tutari: " << kalan << endl;
											user[i].s.setoTutar(0);
											user[i].s.setSusayac(0);
											
										}
									}
									else if(sec==2)
									{
										cout << "\t---Hesap karti" << endl;
										if(user[i].s.getOtutar() > user[i].getBakiye())
										{
											cout << "Fatura tutariniz kullanilabilir tutarinizdan fazladir." << endl;
										}
										else
										{
											int kalan;
											kalan =user[i].getBakiye()-user[i].s.getOtutar();
											user[i].setBakiye(kalan);
											cout << "Fatura odemeniz basariyla gerceklesti." << endl << "Hesabinizda kalan bakiye: " << kalan << endl;
											user[i].s.setoTutar(0);
											user[i].s.setSusayac(0);
										}
									}
									
									break;
								case 3 ://dogalgaz
								system("cls");
									cout << "\n\t\t---Dogalgaz Faturasi---" << endl;
									cout << "Odenemeniz gereken tutar  " << user[i].d.getOtutar() << endl;
									cout << "\tHangi odeme yontemini secersiniz?" << endl << "\t1-Kredi Karti\n\t2-Hesap Karti" << endl ;
									cin >>sec;
									if(sec==1)
									{
										cout << "\t---Kredi karti" << endl;
										if(user[i].d.getOtutar() > user[i].k.kullanilabilirTutar())
										{
											cout << "Fatura tutariniz kullanilabilir tutarinizdan fazladir." << endl;
										}
										else
										{
											int kalan;
											kalan =user[i].k.getLimit()-user[i].d.getOtutar();
											user[i].k.setLimit(kalan);
											cout << "Fatura odemeniz basariyla gerceklesti." << endl << "kredi kartinizda kalan limit tutari: " << kalan << endl;
												user[i].d.setoTutar(0);
												user[i].d.setDsayac(0);
										}
									}
									else if(sec==2)
									{
										cout << "\t---Hesap karti" << endl;
										if(user[i].d.getOtutar() > user[i].getBakiye())
										{
											cout << "fatura tutariniz kullanilabilir tutarinizdan fazladir." << endl;
										}
										else
										{
											int kalan;
											kalan =user[i].getBakiye()-user[i].d.getOtutar();
											user[i].setBakiye(kalan);
											cout << "Fatura odemeniz basariyla gerceklesti." << endl << "Hesabinizda kalan bakiye: " << kalan << endl;
												user[i].d.setoTutar(0);
												user[i].d.setDsayac(0);
										}
									}
									
									break;
								case 4 ://internet
								system("cls");
									cout << "\n\t\t---Internet Faturasi---" << endl;
									cout << "Odenemeniz gereken tutar  " << user[i].i.getOtutar() << endl;
									cout << "\tHangi odeme yontemini secersiniz?" << endl << "\t1-Kredi Karti\n\t2-Hesap Karti" << endl;
									cin >>sec;
									if(sec==1)
									{
										cout << "\t---Kredi karti" << endl;
										if(user[i].i.getOtutar() > user[i].k.kullanilabilirTutar())
										{
											cout << "Fatura tutariniz kullanilabilir tutarinizdan fazladir." << endl;
										}
										else
										{
											int kalan;
											kalan =user[i].k.getLimit()-user[i].i.getOtutar();
											user[i].k.setLimit(kalan);
											cout << "Fatura odemeniz basariyla gerceklesti." << endl << "kredi kartinizda kalan limit tutari: " << kalan << endl;
												user[i].i.setoTutar(0);
												user[i].i.setisayac(0);
										}
									}
									else if(sec==2)
									{
										cout << "\t---Hesap karti" << endl;
										if(user[i].i.getOtutar() > user[i].getBakiye())
										{
											cout << "Fatura tutariniz kullanilabilir tutarinizdan fazladir." << endl;
										}
										else
										{
											int kalan;
											kalan =user[i].getBakiye()-user[i].i.getOtutar();
											user[i].setBakiye(kalan);
											cout << "Fatura odemeniz basariyla gerceklesti." << endl << "Hesabinizda kalan bakiye: " << kalan << endl;
												user[i].i.setoTutar(0);
													user[i].i.setisayac(0);
										}
									}
									
									break;
								default :
									cout<<"Yanlis yada eksik tuslama yaptiniz."<< endl;
									flag = 1;
							}
							break;
						case 4 ://aylik ozet
						system("cls");
							cout<<user[i];
							operator+(user[i]);
						
							break;
						case 5 :
						system("cls");
							int x,sec,tutar;
							go_no:
							try{
								cout<<"\n\tPara transferi yapmak istediginiz alicinin numarasini giriniz."<<endl;
								cin>>x;
								if(x<1 || x>5) throw 1;
							}
							catch(int deger){
								cout<<"Bu musteri numarasina ait alici bulunamadi."<<endl;
								goto go_no;
								
							}	
							cout<<"Alici :"<<user[x].getmusName()<<" "<<user[x].getmusSname()<<endl;
							cout<<"Lutfen gondermek istediginiz tutari giriniz."<<endl;
							cin>>tutar;
							cout<<"hesap kartinizdaki kullanilabilir tutar: "<<user[i].getBakiye()<<endl;
							cout<<user[i].k<<endl;//ostream 
							cout<<"\nOdeme araci secin"<<endl<<"1.Hesap karti\n2.Kredi karti"<<endl;
							cin>>sec;
							if(sec==1){
								if(tutar >  user[i].getBakiye()){
									cout << "Gondermek istediginiz tutar kullanilabilir tutarinizdan fazladir. Isleminiz gerceklestirilemiyor." << endl;
								}
								else{
									int kalan;
									kalan =user[i].getBakiye()-tutar;
									user[i].setBakiye(kalan);
									cout << "Para transferiniz basariyla gerceklesti." << endl << "Hesabinizda kalan bakiye: " << kalan<<endl;
								}	
							}
							else if(sec==2){
								if(tutar > user[i].k.kullanilabilirTutar()){
									cout << "Gondermek istediginiz tutar kullanilabilir tutarinizdan fazladir. Isleminiz gerceklestirilemiyor." << endl;
								}
								else{
									int kalan;
									kalan =user[i].k.getLimit()-tutar;
									user[i].k.setLimit(kalan);
									cout << "Para transferiniz basariyla gerceklesti." << endl << "Kredi kartinizda kalan limit tutari: " << kalan<<endl;
								}
							}	
							break;
						case 6:
							system("cls");
				
							cout<<"\n\n\t\tDoviz Islemleri"<<endl;
							cout<<"\nLutfen yapmak istediginiz islemi giriniz."<<endl;cout<<"1.Doviz Hesabi Bilgi\n2.Doviz AL/SAT\n"<<endl;
							cout<<"->";cin>>sec2;cout<<endl;
							switch(sec2){
								case 1:
									showDovizBilgi(user[i]);
									break;
								case 2:
									cout<<"1.Euro Islemleri\n2.Dolar Islemleri\n"<<endl;
									cin>>sec3;
									if(sec3==1){
										cout<<"Guncel Euro Kuru ->"<<user[i].dov.geteuro()<<endl;
										cout<<"1.AL\n2.SAT\n"<<endl;
										cin>>sec4;
										if(sec4==1){
											
											int flagD=0;
											while(flagD==0){
												cout<<"Bakiyeniz-> "<<user[i].getBakiye();cout<<endl;
												cout<<"Ne kadar Almak Istiyorsunuz-> ";cin>>miktar2;cout<<endl;
												if(miktar2*user[i].dov.geteuro() <= user[i].getBakiye()){
													user[i].seteBakiye(user[i].getEurob()+miktar2);
													user[i].setBakiye(user[i].getBakiye()-miktar2*user[i].dov.geteuro());
													flagD++;
													cout<<"Islem Sonrasi Yeni Bakiyeniz-> "<<user[i].getBakiye();cout<<endl;
												}
												else{
													flagD++;
													cout<<"Yetersiz Bakiye veya Yanlis Girdi Lutfen Yeniden denemek icin 0 e cikmak icin 99 ye basin!!-> ";cin>>flagD;
													cout<<endl;
						
												}
												
											}	
										}
										else if(sec4==2){
											int flagD=0;
											while(flagD==0){
												cout<<"Bakiyeniz-> "<<user[i].getBakiye();cout<<endl;
												cout<<"Euro Bakiyeniz-> "<<user[i].getEurob();cout<<endl;
												cout<<"Ne kadar Satmak Istiyorsunuz-> ";cin>>miktar2;cout<<endl;
												if(miktar2 <= user[i].getEurob()){
													user[i].seteBakiye(user[i].getEurob()-miktar2);
													user[i].setBakiye(user[i].getBakiye()+miktar2*user[i].dov.geteuro());
													flagD++;
													cout<<"Islem Sonrasi Yeni Bakiyeniz-> "<<user[i].getBakiye();cout<<endl;
													cout<<"Islem Sonrasi Yeni Euro Bakiyeniz-> "<<user[i].getEurob();cout<<endl;
												}
												else{
													flagD++;
													cout<<"Yetersiz Bakiye veya Yanlis Girdi Lutfen Yeniden denemek icin 0 e cikmak icin 99 ye basin!!-> ";cin>>flagD;
													cout<<endl;
						
												}
												
											}											
										}
									}
									else if(sec3==2){
										cout<<"Guncel Dolar Kuru ->"<<user[i].dov.getdolar()<<endl;
										cout<<"1.AL\n2.SAT\n"<<endl;
										cin>>sec4;
										if(sec4==1){
											
											int flagD=0;
											while(flagD==0){
												system("cls");
												cout<<"Bakiyeniz-> "<<user[i].getBakiye();cout<<endl;
												cout<<"Ne kadar Almak Istiyorsunuz-> ";cin>>miktar2;cout<<endl;
												if(miktar2*user[i].dov.getdolar() <= user[i].getBakiye()){
													user[i].setdBakiye(user[i].getDolarb()+miktar2);
													user[i].setBakiye(user[i].getBakiye()-miktar2*user[i].dov.getdolar());
													flagD++;
													cout<<"Islem Sonrasi Yeni Bakiyeniz-> "<<user[i].getBakiye();
												}
												else{
													flagD++;
													cout<<"Yetersiz Bakiye veya Yanlis Girdi Lutfen Yeniden denemek icin 0 e cikmak icin 99 ye basin!!-> ";cin>>flagD;
													cout<<endl;
						
												}
												
											}	
										}
										else if(sec4==2){
											int flagD=0;
											while(flagD==0){
												system("cls");
												cout<<"Bakiyeniz-> "<<user[i].getBakiye();cout<<endl;
												cout<<"Dolar Bakiyeniz-> "<<user[i].getDolarb();cout<<endl;
												cout<<"Ne kadar Satmak Istiyorsunuz-> ";cin>>miktar2;cout<<endl;
												if(miktar2 <= user[i].getDolarb()){
													user[i].setdBakiye(user[i].getDolarb()-miktar2);
													user[i].setBakiye(user[i].getBakiye()+miktar2*user[i].dov.getdolar());
													flagD++;
													cout<<"Islem Sonrasi Yeni Bakiyeniz-> "<<user[i].getBakiye();
													cout<<"Islem Sonrasi Yeni Dolar Bakiyeniz-> "<<user[i].getDolarb();cout<<endl;
												}
												else{
													flagD++;
													cout<<"Yetersiz Bakiye veya Yanlis Girdi Lutfen Yeniden denemek icin 0 e cikmak icin 99 ye basin!!-> ";cin>>flagD;
													cout<<endl;
						
												}
												
											}	
										}
																					
																				
									}
									break;
							}
							break;
						case 7:
							hakbitti:
							cout<<"Cikis yapildi..";
							flag=0;
							break;
						default :
							cout<<"Gecersiz giris yaptiniz.!!!!!!"<< endl ;
							flag=1;
					}
				}
			}
			}
			catch( int hata )
			{
				cout << "Eksik tuslama yaptiniz.\n "<< endl;
				goto gosifre;
			}
		} 
		
		
	}
	
	
		delete [] user;
	return 0 ;
}


int bas_bul(int pword)
{
	int temp1;
	int basamak1=1;
	temp1=pword;

	while(temp1 > 10)
	{	
		temp1 /=10;
		basamak1++;
	}
	if( basamak1 != 5){
		return 0;
	}
	return 99;
}
