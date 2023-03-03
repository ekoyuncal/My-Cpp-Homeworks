#ifndef sale_h
#define sale_h

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

void addCustomer(Customer* headCustomer);
void displayCustomers(Customer* headCustomer);
void displayACustomer(Customer* headCustomer);
void arayaAddCustomer(Customer* headCustomer);
void sondanDelete(Customer* headCustomer);
void displayTypeCustomers(Customer* headCustomer);

void addProduct(Product* headProduct);
void displayProducts(Product* headProduct);
void displayAProduct(Product* headProduct);
void arayaAddProduct(Product* headProduct);
void sondanDeleteProduct(Product* headProduct);
void displayTypeProducts(Product* headProduct);

void addPurchased(Purchased* headPurchased,Customer* headCustomer,Product* headProduct);
void displayPurchaseds(Purchased* headPurchased);

void displayCustomersPurchaseds(Purchased* headPurchased,Customer* headCustomer,Product* headProduct);
void displayCustomersTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct);
void displayCustomersTotalwParameter(int c_id,Purchased* headPurchased,Customer* headCustomer,Product* headProduct);
void displayAllCustomersTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct);
double returnCustomersTotalwParameter(int c_id,Purchased* headPurchased,Customer* headCustomer,Product* headProduct);
double returnACustomersCargowParameter(int c_id,Purchased* headPurchased,Customer* headCustomer,Product* headProduct);
void cargoPricesTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct);
void displayMinMaxTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct);
void displayProductsTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct);
void displayAllTotal(Purchased* headPurchased,Customer* headCustomer,Product* headProduct);


#endif
