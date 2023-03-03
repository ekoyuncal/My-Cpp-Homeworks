#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sale.h"
//headPurchased,headCustomer,headProduct
int main()
{
	Customer* headCustomer = (Customer*)malloc(sizeof(Customer));
	Product* headProduct = (Product*)malloc(sizeof(Product));
	Purchased* headPurchased = (Purchased*)malloc(sizeof(Purchased));
	
	headCustomer->ID=0;
	
	Customer* tanimliCustomer1= (Customer*)malloc(sizeof(Customer));
	Customer* tanimliCustomer2= (Customer*)malloc(sizeof(Customer));
	Customer* tanimliCustomer3= (Customer*)malloc(sizeof(Customer));
	Customer* tanimliCustomer4= (Customer*)malloc(sizeof(Customer));
	Customer* tanimliCustomer5= (Customer*)malloc(sizeof(Customer));
	
	tanimliCustomer1->ID=1;
	strcpy(tanimliCustomer1->name,"E Corp");
	tanimliCustomer1->type=1;
	tanimliCustomer1->x_coord=26;
	tanimliCustomer1->y_coord=1;
	tanimliCustomer1->nextCusPtr=tanimliCustomer2;
	
	tanimliCustomer2->ID=2;
	strcpy(tanimliCustomer2->name,"Melike Zengin");
	tanimliCustomer2->type=0;
	tanimliCustomer2->x_coord=2;
	tanimliCustomer2->y_coord=4.5;
	tanimliCustomer2->nextCusPtr=tanimliCustomer3;
	
	tanimliCustomer3->ID=3;
	strcpy(tanimliCustomer3->name,"Ali Keskin");
	tanimliCustomer3->type=0;
	tanimliCustomer3->x_coord=10;
	tanimliCustomer3->y_coord=2;
	tanimliCustomer3->nextCusPtr=tanimliCustomer4;
	
	
	tanimliCustomer4->ID=4;
	strcpy(tanimliCustomer4->name,"Osman Pazarlama");
	tanimliCustomer4->type=1;
	tanimliCustomer4->x_coord=12;
	tanimliCustomer4->y_coord=5;
	tanimliCustomer4->nextCusPtr=tanimliCustomer5;
	
	tanimliCustomer5->ID=5;
	strcpy(tanimliCustomer5->name,"Zehra Cilek");
	tanimliCustomer5->type=0;
	tanimliCustomer5->x_coord=4;
	tanimliCustomer5->y_coord=2.2;
	tanimliCustomer5->nextCusPtr=NULL;
	
	headCustomer->nextCusPtr = tanimliCustomer1;
	
	headProduct->ID=0;
	
	Product* tanimliProduct1= (Product*)malloc(sizeof(Product));
	Product* tanimliProduct2= (Product*)malloc(sizeof(Product));
	Product* tanimliProduct3= (Product*)malloc(sizeof(Product));
	Product* tanimliProduct4= (Product*)malloc(sizeof(Product));
	Product* tanimliProduct5= (Product*)malloc(sizeof(Product));
	
	tanimliProduct1->ID=1;
	strcpy(tanimliProduct1->name,"Portakal Sikma");
	tanimliProduct1->type=1;
	tanimliProduct1->price=5.99;
	
	tanimliProduct1->nextProPtr=tanimliProduct2;
	
	tanimliProduct2->ID=2;
	strcpy(tanimliProduct2->name,"Pirasa");
	tanimliProduct2->type=2;
	tanimliProduct2->price=3.95;
	tanimliProduct2->nextProPtr=tanimliProduct3;
	
	tanimliProduct3->ID=3;
	strcpy(tanimliProduct3->name,"Limon");
	tanimliProduct3->type=1;
	tanimliProduct3->price=7.45;
	tanimliProduct3->nextProPtr=tanimliProduct4;
	
	tanimliProduct4->ID=4;
	strcpy(tanimliProduct4->name,"Hamsi");
	tanimliProduct4->type=3;
	tanimliProduct4->price=15;
	tanimliProduct4->nextProPtr=tanimliProduct5;
	
	tanimliProduct5->ID=5;
	strcpy(tanimliProduct5->name,"Lahana");
	tanimliProduct5->type=2;
	tanimliProduct5->price=5.95;
	tanimliProduct5->nextProPtr=NULL;
	
	headProduct->nextProPtr = tanimliProduct1;
	
	headPurchased->ID=0;
	
	Purchased* tanimliPurchased1= (Purchased*)malloc(sizeof(Purchased));
	Purchased* tanimliPurchased2= (Purchased*)malloc(sizeof(Purchased));
	Purchased* tanimliPurchased3= (Purchased*)malloc(sizeof(Purchased));
	Purchased* tanimliPurchased4= (Purchased*)malloc(sizeof(Purchased));
	Purchased* tanimliPurchased5= (Purchased*)malloc(sizeof(Purchased));	

	tanimliPurchased1->ID=1;
	tanimliPurchased1->invoice_ID=1;
	tanimliPurchased1->customer_ID=2;
	tanimliPurchased1->product_ID=2;//2xPirasa aldi varsayalim
	tanimliPurchased1->cost=7.9;//3.95x2
	tanimliPurchased1->nextPurchPtr=tanimliPurchased2;
	
	tanimliPurchased2->ID=2;
	tanimliPurchased2->invoice_ID=1;
	tanimliPurchased2->customer_ID=2;
	tanimliPurchased2->product_ID=3;//1xLimon aldi varsayalim
	tanimliPurchased2->cost=7.45;//7.45
	tanimliPurchased2->nextPurchPtr=tanimliPurchased3;
	
	tanimliPurchased3->ID=3;
	tanimliPurchased3->invoice_ID=2;
	tanimliPurchased3->customer_ID=4;
	tanimliPurchased3->product_ID=4;//3xHamsi aldi varsayalim
	tanimliPurchased3->cost=45;//3x15
	tanimliPurchased3->nextPurchPtr=tanimliPurchased4;
	
	
	tanimliPurchased4->ID=4;
	tanimliPurchased4->invoice_ID=3;
	tanimliPurchased4->customer_ID=1;
	tanimliPurchased4->product_ID=5;//1xLahana aldi varsayalim
	tanimliPurchased4->cost=5.95;//5.95
	tanimliPurchased4->nextPurchPtr=tanimliPurchased5;
	
	tanimliPurchased5->ID=5;
	tanimliPurchased5->invoice_ID=3;
	tanimliPurchased5->customer_ID=1;
	tanimliPurchased5->product_ID=3;//4xLimon aldi varsayalim
	tanimliPurchased5->cost=29.8;//4x7.45
	tanimliPurchased5->nextPurchPtr=NULL;

	headPurchased->nextPurchPtr=tanimliPurchased1;
	
	int secim;
	int dongu=0;
	
	while(dongu ==0)
	{
		printf("Satis Otomasyonu Menusune Hosgeldiniz..\nLutfen Yapmak istediginiz islemi seciniz\n\n");
		printf("1.Satis\n2.Musteri Bilgisi\n3.Urun Bilgisi\n4.Musteri Analizleri\n5.Urun Analizleri\n6.Veri Guncelleme\n");
		scanf("%d",&secim);
		switch(secim){
			case 1:
				addPurchased(headPurchased,headCustomer,headProduct);
				printf("Kayitli Faturalari Incelemek icin 1 e islemi sonlandirmak icin 0 a basin\n");
				scanf("%d",&secim);
				if(secim ==1){
					displayPurchaseds(headPurchased);
				}
				break;
			case 2:
				printf("Musteri Bilgisi\n\n");
				printf("1.Tum Musterileri Sirala\n2.Musteri Tipine Gore Sirala\n3.Belirli Musteriyi Goster\n");
				scanf("%d",&secim);
				switch(secim){
					case 1:
						//tum musterileri bastirma fonksiyonu
						system("cls");
						printf("Sistemde Bulunan Musteriler\n");
						displayCustomers(headCustomer);
						break;
					case 2:
						//kullanicidan alinan bilgiye göre bireysel veya sirket musterilerini bastir
						system("cls");
						displayTypeCustomers(headCustomer);
						break;
					
					case 3:
						system("cls");
						displayACustomer(headCustomer);
						break;
				}
				break;
			case 3:
				printf("Urun Bilgisi\n\n");
				printf("1.Tum Urunleri Sirala\n2.Urun Tipine Gore Sirala\n3.Belirli Urunu Goster\n");
				scanf("%d",&secim);
				switch(secim){
					case 1:
						system("cls");
						//Tum urunleri bastirma fonksiyonu
						displayProducts(headProduct);
						break;
					case 2:
						system("cls");
						//urun tipi al ve o tipi bastiran fonksiyon
						displayTypeProducts(headProduct);
						break;
					case 3:
						system("cls");
						displayAProduct(headProduct);
					
						break;
				}
				break;
			case 4:
				printf("Musteri Analizleri\n\n");
				printf("1.Bir Musterinin Satin Aldigi Urunler\n2.Bir Musterinin Harcadigi Toplam Tutar\n3.Tum Musterilerin Toplam Satis Tutari\n4.Musterilerin Toplam Kargo Ucreti\n");	
				scanf("%d",&secim);
				switch(secim){
					case 1:
						//musteri nosu iste alinan degeri parametre olarak al o musterinin aldiklarini bastir
						displayCustomersPurchaseds(headPurchased,headCustomer,headProduct);
						break;
					case 2:
						//musteri nosu iste alinan degeri parametre olarak al aldiklarini topla bastir tutari
						displayCustomersTotal(headPurchased,headCustomer,headProduct);
						break;
					case 3:
						//satilan tum urunleri faturalardan topla toplam tutari bastir
						displayAllCustomersTotal(headPurchased,headCustomer,headProduct);
						displayMinMaxTotal(headPurchased,headCustomer,headProduct);
						break;
					case 4:
						//tum musterileri id ve ad olarak bastir kargo ucretlerini sirala
						cargoPricesTotal(headPurchased,headCustomer,headProduct);
						break;
			
				}
				break;
			case 5:
				printf("Urun Analizleri\n\n");
				printf("1.Bir Urunun Toplam Satis Tutari\n2.Bir Urun Tipinin Toplam Satis Tutari\n3.Tum Urunlerin Toplam Satis Tutari\n");
				scanf("%d",&secim);
				switch(secim){
					case 1:
						//kullanicidan urun no al o urun ne kadar satilmis bastir
						displayProductsTotal(headPurchased,headCustomer,headProduct);
						break;
					case 2:
						//kullanicidan urun tipi al o urun tipi urunler ne kadar satilmis bastir
						displayProductswTypeTotal(headPurchased,headCustomer,headProduct);
						break;
					case 3:
						//toplam satis tutarini bastir
						displayAllTotal(headPurchased,headCustomer,headProduct);
						break;
			
				}
				break;
			case 6:
				printf("1.Musteri Bilgilerinde Degisiklik\n2.Urun Bilgilerinde Degisiklik\n");
				scanf("%d",&secim);
				switch(secim){
					case 1:
						printf("Musteri Bilgi Degisiklik Bolumundesiniz Devam Etmek Icin Ne yapmak Istediginizi Seciniz\n");
						printf("1.Musteri Ekleme(Sona)\n2.Musteri Ekleme(Araya)\n3.Musteri Silme(Sondan)\n");
						scanf("%d",&secim);
						switch(secim){
							case 1:
								addCustomer(headCustomer);
								break;
							case 2:
								arayaAddCustomer(headCustomer);
								break;
							case 3:
								sondanDelete(headCustomer);
								break;
						}
						break;
					case 2:
						printf("Urun Bilgi Degisiklik Bolumundesiniz Devam Etmek Icin Ne yapmak Istediginizi Seciniz\n");
						printf("1.Urun Ekleme(Sona)\n2.Urun Ekleme(Araya)\n3.Urun Silme(Sondan)\n");
						scanf("%d",&secim);
						switch(secim){
							case 1:
								addProduct(headProduct);
								break;
							case 2:
								arayaAddProduct(headProduct);
								break;
							case 3:
								sondanDeleteProduct(headProduct);
								break;
						}
						break;
				}
		}
		printf("Yeni bir islem yapmak istiyorsaniz 0\tSistemden cikmak istiyorsaniz 1e basiniz\n\n");
		scanf("%d",&dongu);
	}
	
	
	return 0;
	
}
