#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer{
	int ID;
	char name[50];
	unsigned int type:1;
	double x_coord;
	double y_coord;
	struct customer *nextCusPtr;
	
};
typedef struct customer Customer;


struct product{
	int ID;
	char name[50];
	unsigned int type: 4;
	double price;
	struct product *nextProPtr;
};
typedef struct product Product;


struct purchased{
	int ID;
	int invoice_ID;
	int customer_ID;
	int product_ID;
	double cost;
	struct purchased *nextPurchPtr;
};
typedef struct purchased Purchased;

void addCustomer(Customer* headCustomer){
	Customer* temp;
	
	Customer* yeniCustomer;
	yeniCustomer =(Customer*)malloc(sizeof(Customer));
	int c_ID;
	
	char c_name[30];
	int c_type;
	double c_x, c_y;
	
	printf("Lutfen sirasiyla id-name-customerType(0 for personal 1 for commercial)-xlocation-ylocation verilerini giriniz\n");
	
	printf("Musteri Numarasini giriniz(sistemde olmadigina dikkat ediniz 1-2-3-4-5 seklinde ilk 5 i olusturuldu)\n");
	scanf("%d",&c_ID);
	while(c_ID <= 5){
		printf("Yeniden giriniz\n");
		scanf("%d",&c_ID);
	}
	
	
	printf("Musteri Ismini giriniz\n");
	scanf(" %[^\n]", c_name);
	
	printf("Musteri Tipini Giriniz(0 for personal 1 for commercial)\n");
	scanf("%d",&c_type);
	
	printf("Musteri X ve Y konum verilerini giriniz\n");
	scanf("%lf %lf",&c_x,&c_y);
	
	yeniCustomer->ID = c_ID;
	strcpy(yeniCustomer->name,c_name);//yeni musteri verileri dugume yerlestirildi
	yeniCustomer->type = c_type;
	yeniCustomer->x_coord =c_x;
	yeniCustomer->y_coord =c_y;
	yeniCustomer->nextCusPtr =NULL;
	
	if(headCustomer == NULL){
		headCustomer = yeniCustomer;//eger ilk dugum yoksa ilk dugum olarak yerlestir
	}
	else{
		temp= headCustomer;
		while(temp->nextCusPtr !=NULL){//dugumun sonuna git oraya ekle
			temp = temp->nextCusPtr;
		}
		temp->nextCusPtr=yeniCustomer;
	}
	
}
void displayCustomers(Customer* headCustomer){
	Customer* temp;
	temp= headCustomer;
	
	while(temp->nextCusPtr !=NULL){
		if(temp->ID !=0){//bu ifadeyi tum fonksiyonlarda kullandim bos olan ilk dugumu gizlemek amaciyla
			printf("id: %d\nName: %s\nCustomer type: %d\nLocation: x:%.2lf y:%.2lf\n\n",temp->ID,temp->name,temp->type,temp->x_coord,temp->y_coord);
			
		}
		temp=temp->nextCusPtr;
	}//ilersi null oldugu icin
	printf("id: %d\nName: %s\nCustomer type: %d\nLocation: x:%.2lf y:%.2lf\n\n",temp->ID,temp->name,temp->type,temp->x_coord,temp->y_coord);//son kullanici icin ek olarak printf eklendi
}
void displayACustomer(Customer* headCustomer){
	int key;
	
	Customer* temp;
	temp = headCustomer;
	
	printf("Hangi Musteriyi Incelemek istiyorsunuz\n");
	scanf("%d",&key);//kullanici idsi alindi
	
	while(temp->nextCusPtr !=NULL){
		if(temp->ID !=0){//ilk root dugumu hataya neden olmasýn diye engellendi bu tum fonksiyonlarda yapildi
			if(temp->ID == key){//o idye gelene kadar dugumlerde gezildi
				printf("id: %d\nName: %s\nCustomer type: %d\nLocation: x:%.2lf y:%.2lf\n\n",temp->ID,temp->name,temp->type,temp->x_coord,temp->y_coord);
			}
		}
		temp=temp->nextCusPtr;
	}
	if(temp->ID == key){//son musteri icin olusturuldu
		printf("id: %d\nName: %s\nCustomer type: %d\nLocation: x:%.2lf y:%.2lf\n\n",temp->ID,temp->name,temp->type,temp->x_coord,temp->y_coord);
	}
}
void arayaAddCustomer(Customer* headCustomer){
	int soluna;
	
	int c_ID;
	char c_name[30];
	int c_type;
	double c_x, c_y;
	
	Customer* temp;
	Customer* newCustomer =(Customer*)malloc(sizeof(Customer));
	
	displayCustomers(headCustomer);
	printf("Hangi Musterinin Soluna(Onune) eklemek istiyorsanýz id numarasini giriniz\n");
	scanf("%d",&soluna);
	
	
	printf("Lutfen sirasiyla id-name-customerType(0 for personal 1 for commercial)-xlocation-ylocation verilerini giriniz\n");
	printf("Musteri Numarasini giriniz(Girdiginiz numaralarin ayni olmadigina ve sirali olduguna ozen gösteriniz)\n");
	scanf("%d",&c_ID);
	
	while(c_ID <= 5){//ilk 5 olusturuldugu icin
		printf("Yeniden giriniz\n");
		scanf("%d",&c_ID);
	}
	
	printf("Musteri Ismini giriniz\n");
	scanf(" %[^\n]", c_name);
	
	printf("Musteri Tipini Giriniz(0 for personal 1 for commercial)\n");
	scanf("%d",&c_type);
	
	printf("Musteri X ve Y konum verilerini giriniz\n");
	scanf("%lf %lf",&c_x,&c_y);
	
	newCustomer->ID=c_ID;
	strcpy(newCustomer->name,c_name);
	newCustomer->type=c_type;//alinan verileri dugume yerlestir
	newCustomer->x_coord=c_x;
	newCustomer->y_coord=c_y;
	
	temp=headCustomer;
	while(temp->nextCusPtr->ID !=soluna){//soluna eklenmek istenen dugumu bul
		temp=temp->nextCusPtr;
	}
	Customer* previousPtr;
	Customer* currentPtr;
	currentPtr = temp->nextCusPtr;
	previousPtr = temp;
	previousPtr->ID=newCustomer->ID;
	strcpy(previousPtr->name,newCustomer->name);
	previousPtr->type=newCustomer->type;
	previousPtr->x_coord=newCustomer->x_coord;
	previousPtr->y_coord=newCustomer->y_coord;
	previousPtr->nextCusPtr=currentPtr;
}
void sondanDelete(Customer* headCustomer){
	Customer* temp;
	if(headCustomer->nextCusPtr != NULL){
		temp = headCustomer;
		while(temp->nextCusPtr->nextCusPtr != NULL){
			temp=temp->nextCusPtr;
		}
		free(temp->nextCusPtr);
		temp->nextCusPtr=NULL;
	}
	else{
		if(headCustomer !=NULL){
			temp=headCustomer->nextCusPtr;
			free(headCustomer);
			headCustomer=temp;
		}
		else{
			free(headCustomer);
		}
	}
}
void displayTypeCustomers(Customer* headCustomer){
	int typeKey;
	Customer* temp;
	temp=headCustomer;
	
	printf("Hangi tip musterileri gormek istediginizi seciniz(0 for personal 1 for commercial)\n");
	scanf("%d",&typeKey);//istenilen musteri tipi alindi
	while(typeKey !=1 && typeKey !=0){
		printf("Hatali Giris!!!!(0 for personal 1 for commercial)\n");
		scanf("%d",&typeKey);
	
	}
	if(typeKey == 1){
		printf("\t\tCommercial Customer\n");
	}
	else if(typeKey == 0){
		printf("\t\tPersonal Customers\n");
	}
	
	while(temp->nextCusPtr !=NULL){
		if(temp->type == typeKey){
			if(temp->ID != 0){
				printf("id: %d\nName: %s\nCustomer type: %d\nLocation: x:%.2lf y:%.2lf\n\n",temp->ID,temp->name,temp->type,temp->x_coord,temp->y_coord);
			
			}
		}
		
		temp=temp->nextCusPtr;
		/*
		printf("id: %d\nName: %s\nCustomer type: %d\nLocation: x:%.2lf y:%.2lf\n\n",temp->ID,temp->name,temp->type,temp->x_coord,temp->y_coord);
		temp=temp->nextCusPtr;*/
	}
	if(temp->type == typeKey){//son dugum icin tekrar yazildi
		printf("id: %d\nName: %s\nCustomer type: %d\nLocation: x:%.2lf y:%.2lf\n\n",temp->ID,temp->name,temp->type,temp->x_coord,temp->y_coord);
	}
}

void addProduct(Product* headProduct){
	Product* temp;
	
	Product* yeniProduct;
	yeniProduct =(Product*)malloc(sizeof(Product));
	
	int p_ID;
	char p_name[50];
	int p_type;
	double p_price;
	
	printf("Lutfen sirasiyla id-name-productType(1 for fruits 2 for vegetables 3 for meats)-xlocation-ylocation verilerini giriniz\n");
	
	printf("Urun Numarasini giriniz(sistemde olmadigina dikkat ediniz 1-2-3-4-5 seklinde ilk 5 i olusturuldu)\n");
	scanf("%d",&p_ID);
	while(p_ID <= 5){
		printf("Yeniden giriniz\n");
		scanf("%d",&p_ID);
	}
	
	
	
	printf("Urun Ismini giriniz\n");
	scanf(" %[^\n]", p_name);
	
	printf("Urun Tipini Giriniz(1 for fruits 2 for vegetables 3 for meats)\n");
	scanf("%d",&p_type);
	
	printf("Urun fiyatini giriniz\n");
	scanf("%lf",&p_price);
	
	yeniProduct->ID = p_ID;
	strcpy(yeniProduct->name,p_name);
	yeniProduct->type=p_type;//alinan veriler yeni dugume yerlestirildi
	yeniProduct->price=p_price;
	yeniProduct->nextProPtr=NULL;
	
	if(headProduct==NULL){
		headProduct = yeniProduct;
	}
	else{
		temp=headProduct;
		while(temp->nextProPtr != NULL){//son dugume kadar gidildi
			temp = temp->nextProPtr;
		}
		temp->nextProPtr=yeniProduct;
	}
	
}
void displayProducts(Product* headProduct){
	Product* temp;
	temp = headProduct;
	
	while(temp->nextProPtr != NULL){
		if(temp->ID !=0){
			printf("id: %d\nProductName: %s\nProduct type: %d\nPrice: %.2lf\n\n",temp->ID,temp->name,temp->type,temp->price);
		}
		temp=temp->nextProPtr;
	}//son dugum icin
	printf("id: %d\nProductName: %s\nProduct type: %d\nPrice: %.2lf\n\n",temp->ID,temp->name,temp->type,temp->price);
	
}
void displayAProduct(Product* headProduct){
	int key;
	
	Product* temp;
	temp = headProduct;
	
	printf("Hangi urunu incelemek istiyorsunuz(id numarasini giriniz)\n");
	scanf("%d",&key);//istenilen dugum alinarak o dugumm bastirildi
	
	while(temp->nextProPtr != NULL){
		if(temp->ID !=0){
			if(temp->ID == key){
				printf("id: %d\nProductName: %s\nProduct type: %d\nPrice: %.2lf\n\n",temp->ID,temp->name,temp->type,temp->price);
			}
		}
		temp=temp->nextProPtr;
	}
	if(temp->ID == key){
		printf("id: %d\nProductName: %s\nProduct type: %d\nPrice: %.2lf\n\n",temp->ID,temp->name,temp->type,temp->price);
	}
	
}
void arayaAddProduct(Product* headProduct){
	int soluna;
	
	int p_ID;
	char p_name[50];
	int p_type;
	double p_price;
	
	Product* temp;
	Product* newProduct =(Product*)malloc(sizeof(Product));
	
	displayProducts(headProduct);
	printf("Hangi Urunun Soluna(Onune) eklemek istiyorsaniz id numarasini giriniz\n");
	scanf("%d",&soluna);
	
	
	printf("Lutfen sirasiyla id-name-productType(1 for fruits 2 for vegetables 3 for meats)-xlocation-ylocation verilerini giriniz\n");
	printf("Urun Numarasini giriniz(lutfen 5den buyuk)\n");
	scanf("%d",&p_ID);
	
	while(p_ID <= 5){
		printf("Yeniden giriniz\n");
		scanf("%d",&p_ID);//tanimli 5 tane oldugu icin 5ten buyuk alýyoruz
	}
	
	
	printf("Urun Ismini giriniz\n");
	scanf(" %[^\n]", p_name);//%[^\n] butun satiri almak icin kullaniyoruz
	
	printf("Urun Tipini Giriniz(1 for fruits 2 for vegetables 3 for meats)\n");
	scanf("%d",&p_type);
	
	printf("Urun fiyatini giriniz\n");
	scanf("%lf",&p_price);
	
	newProduct->ID=p_ID;
	strcpy(newProduct->name,p_name);
	newProduct->type=p_type;//alinan veriler yeni dugume yerlestirildi
	newProduct->price=p_price;
	
	temp=headProduct;
	while(temp->nextProPtr->ID !=soluna){
		temp=temp->nextProPtr;
	}
	Product* previousPtr;
	Product* currentPtr;
	currentPtr = temp->nextProPtr;
	previousPtr = temp;
	previousPtr->ID=newProduct->ID;//pointer adresleri ayarlandi
	strcpy(previousPtr->name,newProduct->name);
	previousPtr->type=newProduct->type;
	previousPtr->price=newProduct->price;
	
	previousPtr->nextProPtr=currentPtr;
}
void sondanDeleteProduct(Product* headProduct){
	Product* temp;
	if(headProduct->nextProPtr != NULL){
		temp = headProduct;
		while(temp->nextProPtr->nextProPtr != NULL){
			temp=temp->nextProPtr;
		}
		free(temp->nextProPtr);//sondakini sil bir oncekinin ilerisini NULL yap
		temp->nextProPtr=NULL;
	}
	else{
		if(headProduct != NULL){
			temp=headProduct->nextProPtr;
			free(headProduct);
			headProduct=temp;
		}
		else{
			free(headProduct);
		}
	}
}
void displayTypeProducts(Product* headProduct){
	int typeKey;
	Product* temp;
	temp= headProduct;
	
	printf("Hangi tip urunleri gormek istediginizi seciniz(1 for fruits 2 for vegetables 3 for meats)\n");
	scanf("%d",&typeKey);//Hangi tip oldugunu al
	while(typeKey !=1 && typeKey !=2 && typeKey !=3){
		printf("Hatali Giris!!!(1 for fruits 2 for vegetables 3 for meats)\n");
		scanf("%d",&typeKey);
	}
	if(typeKey == 1){
		printf("\t\tFruits\n");
	}
	else if(typeKey == 2){
		printf("\t\tVegetables\n");
	}
	else if(typeKey == 3){
		printf("\t\tMeats\n");
	}
	//bastir
	while(temp->nextProPtr != NULL){
		if(temp->type == typeKey){//ayni tipteyse bastir
			if(temp->ID != 0){
				printf("id: %d\nProductName: %s\nProduct type: %d\nPrice: %.2lf\n\n",temp->ID,temp->name,temp->type,temp->price);
			}
		}
		
		temp =temp->nextProPtr;
	}
	if(temp->type ==typeKey){
		printf("id: %d\nProductName: %s\nProduct type: %d\nPrice: %.2lf\n\n",temp->ID,temp->name,temp->type,temp->price);
	}
	
}

void addPurchased(Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	
	static purchasedID=6;//idyi her satista arttirirken fatura 1 kere artiyor
	static fatura_ID=4;
	int tekrarsecim;
	double total=0;//ilk alisveris
	double total2=0;//ikinci ve fazlasialisveris
	int c_id;
	int p_id;
	int ckey = 0;
	int pkey = 0;
	int pkey2 =0;
	int miktar;
    double mesafex;
    double mesafey;
    double priceproduct;
	Purchased* purtemp = headPurchased;
	Customer* ctemp = headCustomer;
	Product* protemp = headProduct;
	
	Purchased* newPurchased = (Purchased*)malloc(sizeof(Purchased));
	
	while(purtemp->nextPurchPtr !=NULL){
		purtemp=purtemp->nextPurchPtr;
	}
	printf("Lutfen musteri numarasini giriniz\n");
	scanf("%d",&c_id);
	while(ckey == 0){
		ctemp=headCustomer;
		while(ctemp->nextCusPtr !=NULL){
			if(ctemp->ID !=0){
				if(ctemp->ID == c_id){
					ckey =1;
					mesafex=ctemp->x_coord;//musteri numarasý dogrularken konumu da alip mesafex mesafey olarak kayydet
					mesafey=ctemp->y_coord;
				}
			}
			ctemp=ctemp->nextCusPtr;
		}
		if(ctemp->ID == c_id){//son eleman icin de ayni islem
			ckey =1;
			mesafex=ctemp->x_coord;
			mesafey=ctemp->y_coord;
		}
		if(ckey == 0){
			printf("Lutfen musteri numarasini yeniden giriniz\n");
			scanf("%d",&c_id);
		}
	}			
	printf("\t\t\tSatistaki Urunler\n");
	displayProducts(headProduct);
	printf("Lutfen almak istediginiz urunu giriniz\n");
	scanf("%d",&p_id);
	while(pkey == 0){
		protemp =headProduct;
		while(protemp->nextProPtr !=NULL){
			if(protemp->ID !=0){
				if(protemp->ID == p_id){
					pkey =1;
					priceproduct=protemp->price;
					printf("Secilen urun:%s\n",protemp->name);
				}
			}
			protemp=protemp->nextProPtr;
		}
		if(protemp->ID == p_id){
			pkey =1;
			priceproduct=protemp->price;
		}
		if(pkey == 0){
			printf("Lutfen Urun numarasini yeniden giriniz\n");
			scanf("%d",&p_id);
		}
	}
	printf("Sectiginiz urunden ne kadar almak istediginizi seciniz\n");
	scanf("%d",&miktar);
	purtemp->nextPurchPtr=newPurchased;
	newPurchased->ID=purchasedID;
	newPurchased->invoice_ID=fatura_ID;
	newPurchased->customer_ID=c_id;
	newPurchased->product_ID=p_id;
	newPurchased->cost=miktar*priceproduct;
	newPurchased->nextPurchPtr=NULL;
	//kargo hesabi => 2x+2y;
	printf("%d numarali satis icin kargo ucretiniz->%.2lf\n\n",purchasedID,mesafex*2+mesafey*2);
	
	total = (miktar*priceproduct);
	printf("%.2lf\n\n",total);
	printf("Alisverise devam icin 1\nAlisverisi Tamamladiysaniz 2\n\n");
	
	scanf("%d",&tekrarsecim);
	if(tekrarsecim !=2){
		purchasedID++;
	}
	while(tekrarsecim !=2){
		
		ctemp = headCustomer;
		protemp = headProduct;
		
		Purchased* newPurchased = (Purchased*)malloc(sizeof(Purchased));
		purtemp=purtemp->nextPurchPtr;
				
		printf("\t\t\tSatistaki Urunler\n");
		displayProducts(headProduct);
		printf("Lutfen almak istediginiz urunu giriniz\n");
		scanf("%d",&p_id);
		
		while(pkey2 == 0){
			
			protemp=headProduct;
			while(protemp->nextProPtr !=NULL){
				
				if(protemp->ID !=0){
					
					if(protemp->ID == p_id){
						
						priceproduct=protemp->price;
						printf("Secilen urun:%s\n",protemp->name);
						pkey2 =1;
						
					}
				}
				protemp=protemp->nextProPtr;
			}
			if(protemp->ID == p_id){
				pkey2=1;
				priceproduct=protemp->price;
				printf("Secilen urun:%s\n",protemp->name);
			}
			if(pkey2 == 0){
				printf("Lutfen Urun numarasini yeniden giriniz\n");
				scanf("%d",&p_id);
			}
		}
		
		printf("Sectiginiz urunden ne kadar almak istediginizi seciniz\n");
		scanf("%d",&miktar);
		purtemp->nextPurchPtr=newPurchased;//yeni faturayi tanimla
		newPurchased->ID=purchasedID;
		newPurchased->invoice_ID=fatura_ID;
		newPurchased->customer_ID=c_id;
		newPurchased->product_ID=p_id;
		newPurchased->cost=miktar*priceproduct;
		newPurchased->nextPurchPtr=NULL;
		
		
		
		total2 =(miktar*priceproduct);
		
		printf("Alisverise devam icin 1\nAlisverisi Tamamladiysaniz 2\n\n");
		scanf("%d",&tekrarsecim);
		if(tekrarsecim !=2){
			purchasedID++;
		}
	}
	total=total+total2;//+mesafex*2+mesafey*2
	printf("%d. fatura numarali alisverisin toplam tutari: %.2lf+kargo(%.2lf)\n\n",fatura_ID,total,mesafex*2+mesafey*2);
	purchasedID++;
	fatura_ID++;
}
void displayPurchaseds(Purchased* headPurchased){
	Purchased* temp;
	temp=headPurchased;
	
	while(temp->nextPurchPtr != NULL){
		if(temp->ID !=0){
			printf("id: %d\nFaturaID: %d\nMusteriID: %d\nSatilan UrunID: %d\nTutar: %.2lf\n\n",temp->ID,temp->invoice_ID,temp->customer_ID,temp->product_ID,temp->cost);
		}
		temp=temp->nextPurchPtr;
	}//tum faturalarýn ekrana basimi
	printf("id: %d\nFaturaID: %d\nMusteriID: %d\nSatilan UrunID: %d\nTutar: %.2lf\n\n",temp->ID,temp->invoice_ID,temp->customer_ID,temp->product_ID,temp->cost);
	
}
void displayCustomersPurchaseds(Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	
	double total=0;
	int c_id;
	int ckey = 0;
	double satisKontrol=555;
	Purchased* purtemp = headPurchased;
	Customer* ctemp = headCustomer;
	Product* protemp = headProduct;
	
	printf("Lutfen musteri numarasini giriniz\n");
	scanf("%d",&c_id);
	while(ckey == 0){//musterinin kayitli olup olmadigini kontrol ediyoruz
		while(ctemp->nextCusPtr !=NULL){
			if(ctemp->ID !=0){
				if(ctemp->ID == c_id){
					ckey =1;
				}
			}
			ctemp=ctemp->nextCusPtr;
		}
		if(ctemp->ID == c_id){
			ckey =1;
		}
		if(ckey == 0){
			printf("Lutfen musteri numarasini yeniden giriniz\n");
			scanf("%d",&c_id);
		}
	}//musteri kayitlarda varsa fatura listesinde gezip id kontrolu ile ekrana bastirma
	printf("\t\tMusteriID: %d\n",c_id);
	while(purtemp->nextPurchPtr !=NULL){
		if(purtemp->customer_ID == c_id){
			if(purtemp->ID !=0){
				satisKontrol=purtemp->cost;
				printf("id: %d\nFaturaID: %d\nSatilan UrunID: %d\nTutar: %.2lf\n",purtemp->ID,purtemp->invoice_ID,purtemp->product_ID,purtemp->cost);
			}
			
		}
		purtemp=purtemp->nextPurchPtr;
	}
	if(purtemp->customer_ID == c_id){
		satisKontrol=purtemp->cost;
		printf("id: %d\nFaturaID: %d\nSatilan UrunID: %d\nTutar: %.2lf\n",purtemp->ID,purtemp->invoice_ID,purtemp->product_ID,purtemp->cost);
	}
	if(satisKontrol ==555){
		printf("Musteriye hic satis yapilmadi!\n\n");
	}
}
void displayCustomersTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	double total=0;
	int c_id;
	int ckey = 0;
	Purchased* purtemp = headPurchased;
	Customer* ctemp = headCustomer;
	Product* protemp = headProduct;
	
	printf("Lutfen musteri numarasini giriniz\n");
	scanf("%d",&c_id);
	while(ckey == 0){
		while(ctemp->nextCusPtr !=NULL){
			if(ctemp->ID !=0){
				if(ctemp->ID == c_id){
					ckey =1;
				}
			}
			ctemp=ctemp->nextCusPtr;
		}
		if(ctemp->ID == c_id){
			ckey =1;
		}
		if(ckey == 0){
			printf("Lutfen musteri numarasini yeniden giriniz\n");
			scanf("%d",&c_id);
		}
	}
	printf("\t\tMusteriID: %d\n",c_id);//Musterinin yaptigi butun alislari topluyoruz
	while(purtemp->nextPurchPtr !=NULL){
		if(purtemp->customer_ID == c_id){
			if(purtemp->ID !=0){
				total=total+purtemp->cost;
			}
		}
		purtemp=purtemp->nextPurchPtr;
	}
	if(purtemp->customer_ID == c_id){
		total=total+purtemp->cost;
	}
	printf("Total: %.2lf\n",total);
	
}
void displayCustomersTotalwParameter(int c_id,Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	//bu fonksiyon alttaki fonksiyona kolaylýk olmasý amaciyla yazilmistir
	double total=0;
	
	int ckey = 0;
	Purchased* purtemp = headPurchased;
	Customer* ctemp = headCustomer;
	Product* protemp = headProduct;
	
	
	while(ckey == 0){//musteri id kontrolu
		while(ctemp->nextCusPtr !=NULL){
			if(ctemp->ID !=0){
				if(ctemp->ID == c_id){
					ckey =1;
				}
			}
			ctemp=ctemp->nextCusPtr;
			
		}
		if(ctemp->ID == c_id){
			ckey =1;
		}
		if(ckey == 0){
			printf("Lutfen musteri numarasini yeniden giriniz\n");
			scanf("%d",&c_id);
		}
	}
	printf("\t\tMusteriID: %d\n",c_id);
	while(purtemp->nextPurchPtr !=NULL){
		if(purtemp->customer_ID == c_id){//musterinin toplam alisverisi
			if(purtemp->ID !=0){
				total=total+purtemp->cost;
			}
		}
		purtemp=purtemp->nextPurchPtr;
	}
	if(purtemp->customer_ID == c_id){
		total=total+purtemp->cost;
	}
	printf("Total: %.2lf\n",total);
	
}
void displayAllCustomersTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	
	double total=0;
	int c_id;
	int ckey = 0;
	Purchased* purtemp = headPurchased;
	Customer* ctemp = headCustomer;
	Product* protemp = headProduct;
	
	while(ctemp->nextCusPtr !=NULL){
		if(ctemp->ID !=0){//deminki fonksiyon ile kolaylca bastiriliyor
			displayCustomersTotalwParameter(ctemp->ID,headPurchased,headCustomer,headProduct);
		}
		
		ctemp=ctemp->nextCusPtr;
	}
	
	displayCustomersTotalwParameter(ctemp->ID,headPurchased,headCustomer,headProduct);
	
}
double returnCustomersTotalwParameter(int c_id,Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	//alttaki fonksiyona kolaylik icin yazildi
	double total=0;
	int ckey = 0;
	Purchased* purtemp = headPurchased;
	Customer* ctemp = headCustomer;
	Product* protemp = headProduct;
	
	

	while(ckey == 0){
		while(ctemp->nextCusPtr !=NULL){
			if(ctemp->ID !=0){
				if(ctemp->ID == c_id){
					ckey =1;
				}
			}
			ctemp=ctemp->nextCusPtr;
		}
		if(ctemp->ID == c_id){
			ckey =1;
		}
		if(ckey == 0){
			printf("Lutfen musteri numarasini yeniden giriniz\n");
			scanf("%d",&c_id);
		}
	}

	while(purtemp->nextPurchPtr !=NULL){
		if(purtemp->customer_ID == c_id){
			if(purtemp->ID !=0){
				total=total+purtemp->cost;
			}
		}
		purtemp=purtemp->nextPurchPtr;
	}
	if(purtemp->customer_ID == c_id){
		total=total+purtemp->cost;
	}
	return total;
}
double returnACustomersCargowParameter(int c_id,Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	//alttaki kargo fonksiyonu icin kolaylik olmasi amaciyla yazildi
	int sayac=0;
	double totalCargo=0;
	
	Purchased* purtemp = headPurchased;
	Customer* temp = headCustomer;
	Product* protemp = headProduct;
	

	while(temp->nextCusPtr !=NULL){
		if(temp->ID !=0){
			if(temp->ID == c_id){
				while(purtemp->nextPurchPtr !=NULL){
					totalCargo=(temp->x_coord*2)+(temp->y_coord*2);
					if(purtemp->customer_ID==c_id){
						sayac++;
					}
					purtemp=purtemp->nextPurchPtr;
				}
				if(sayac !=0){
					return totalCargo;
				}
				else{
					return 0;
				}
			}
		}
		temp=temp->nextCusPtr;
	}
	if(temp->ID == c_id){
		while(purtemp->nextPurchPtr !=NULL){
			totalCargo=(temp->x_coord*2)+(temp->y_coord*2);
			if(purtemp->customer_ID==c_id){
				sayac++;
			}
			purtemp=purtemp->nextPurchPtr;
		}
		if(sayac !=0){
			return totalCargo;
		}
		else{
			return 0;
		}
	}
}
void cargoPricesTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	double ctotal=0;
	int c_id;
	int ckey = 0;
	Purchased* purtemp = headPurchased;
	Customer* ctemp = headCustomer;
	Product* protemp = headProduct;
	
	while(ctemp->nextCusPtr !=NULL){
		if(ctemp->ID !=0){
			ctotal = returnACustomersCargowParameter(ctemp->ID,headPurchased,headCustomer,headProduct);//deminki fonksiyondan veriyi aldýk ve burda sira ile bastirdik
			printf("id: %d\nName: %s\nTotalCargo: %.2lf\n\n",ctemp->ID,ctemp->name,ctotal);
		}
		
		ctemp=ctemp->nextCusPtr;
	}
	
	ctotal = returnACustomersCargowParameter(ctemp->ID,headPurchased,headCustomer,headProduct);
	printf("id: %d\nName: %s\nTotalCargo: %.2lf\n\n",ctemp->ID,ctemp->name,ctotal);
}
void displayMinMaxTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	double total=0;
	double mintotal;
	double maxtotal=0;
	int c_id;
	int ckey = 0;
	int mindegerverici=0;
	Purchased* purtemp = headPurchased;
	Customer* ctemp = headCustomer;
	Product* protemp = headProduct;
	
	while(purtemp->nextPurchPtr !=NULL){
		
		if(purtemp->ID !=0){
			
			total =returnCustomersTotalwParameter(purtemp->customer_ID,headPurchased,headCustomer,headProduct);//total degerleri topladik
			while(mindegerverici ==0){//bir defalik mintotali ilk degere esitledik digerleriyle karsilastirmak icin
				mintotal=total;
				mindegerverici++;
			}
		}
		if(total > maxtotal){
			maxtotal = total;//deger buyukse yeni max kucukse yeni min
		}
		if(total < mintotal){
			mintotal=total;
		}
		purtemp=purtemp->nextPurchPtr;
	}
	if(purtemp->customer_ID !=0){//son dugum icin ayni sekilde
		total =returnCustomersTotalwParameter(purtemp->customer_ID,headPurchased,headCustomer,headProduct);
	}
	if(total > maxtotal){
		maxtotal = total;
	}
	if(total < mintotal){
		mintotal=total;
	}
	printf("\nEn yuksek satis: %.2lf\nEn dusuk satis: %.2lf\n",maxtotal,mintotal);//min max bastirildi
}
void displayProductsTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	double total=0;
	int p_id;
	int pkey = 0;
	char urunAdi[20];
	Purchased* purtemp = headPurchased;
	Customer* ctemp = headCustomer;
	Product* protemp = headProduct;
	
	displayProducts(headProduct);
	
	printf("Lutfen urun numarasini giriniz\n");
	scanf("%d",&p_id);
	while(pkey == 0){
		protemp=headProduct;
		while(protemp->nextProPtr !=NULL){
			if(protemp->ID != 0){
				
				if(protemp->ID == p_id){
					
					pkey =1;
					strcpy(urunAdi,protemp->name);//urunu kontrol ederken ismini de aldik
				}
			}
			protemp=protemp->nextProPtr;
			
		}
		if(protemp->ID ==p_id){
			pkey=1;
			strcpy(urunAdi,protemp->name);
		}
		if(pkey == 0){
			printf("Lutfen urun numarasini yeniden giriniz\n");
			scanf("%d",&p_id);
		}
	}
	printf("Urun ID: %d Urun: %s\n",p_id,urunAdi);
	while(purtemp->nextPurchPtr !=NULL){
		if(purtemp->product_ID == p_id){//urun faturalarda geciyorsa ne kadar satildigini total degiskenine kaydet
			if(purtemp->ID !=0){
				total=total+purtemp->cost;
			}
		}
		purtemp=purtemp->nextPurchPtr;
	}
	if(purtemp->product_ID == p_id){
		total=total+purtemp->cost;
	}
	printf("Satilan Toplam Total: %.2lf\n",total);//toplam tutari bastir
}
void displayAllTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	double total=0;
	double total2=0;
	int c_id;
	int ckey = 0;
	Purchased* purtemp = headPurchased;
	Customer* ctemp = headCustomer;
	Product* protemp = headProduct;
	
	while(ctemp->nextCusPtr !=NULL){
		if(ctemp->ID !=0){
			
			total2=returnCustomersTotalwParameter(ctemp->ID,headPurchased,headCustomer,headProduct);//tanimlanan fonksiyonla tum satýþlar toplandi
			
		}
		total=total+total2;
		ctemp=ctemp->nextCusPtr;
	}
	
	total2=returnCustomersTotalwParameter(ctemp->ID,headPurchased,headCustomer,headProduct);
	total=total+total2;
	printf("Toplam satis miktari: %.2lf\n",total);//Toplam Satis Bastirildi

}
void displayProductswTypeTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct){
	double total=0;
	int typeUrunTutucu[100];
	int i=0;
	int k=0;
	int typeKey = 0;
	int urunAdi[20];
	Purchased* purtemp = headPurchased;
	Customer* ctemp = headCustomer;
	Product* protemp = headProduct;
	
	printf("Hangi tip urunleri gormek istediginizi seciniz(1 for fruits 2 for vegetables 3 for meats)\n");
	scanf("%d",&typeKey);
	
	while(typeKey !=1 && typeKey !=2  && typeKey !=3){
		printf("Hatali Giris!!!!(1 for fruits 2 for vegetables 3 for meats)\n");
		scanf("%d",&typeKey);
	
	}
	if(typeKey == 1){
		printf("\t\tFruits(1)\n");
	}
	else if(typeKey == 2){
		printf("\t\tVegetables(2)\n");
	}
	else if(typeKey == 3){
		printf("\t\tMeats(3)\n");
	}
	while(protemp->nextProPtr !=NULL)
	{
		if(protemp->ID !=0)
		{
			if(protemp->type == typeKey)
			{
				typeUrunTutucu[i]=protemp->ID;//o type da bulunan urunleri bir dizine atiyoruz ilerde karsilastirmak icin
				i++;
				
			}
		}
		protemp =protemp->nextProPtr;
	}
	if(protemp->type == typeKey)
	{
		typeUrunTutucu[i]=protemp->ID;
		i++;
	}
	
	while(purtemp->nextPurchPtr != NULL)
	{
		if(purtemp->ID != 0)
		{
			for(k=0;k<i;k++)
			{
				if(purtemp->product_ID ==typeUrunTutucu[k])
				{
					total=total+purtemp->cost;//faturadaki urun ile dizindeki urunleri karsilastirip eger dogru urunse totale ekle
					
				}
			}
			
		}
		purtemp=purtemp->nextPurchPtr;
	}
	for(k=0;k<i;k++)
	{
		
		if(purtemp->product_ID ==typeUrunTutucu[k])
		{
			total=total+purtemp->cost;
		}
	}
	
	printf("Total Satis Miktari: %.2lf",total);
}








