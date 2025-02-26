#include <iostream>

class Product
{
public:
	int price;

	void SetPrice(int price_)
	{
		price = price_;
	}
	
};

class IProductValidator
{
public:
	virtual bool IsValid(Product& product) = 0;
};


class CustomerService : public IProductValidator
{
public:
	bool IsValid(Product& product) override
	{
		return product.price > 100000;
	}
};

void SetProductPrice(Product* product, int price_)
{
	product->SetPrice(price_);
}

int main()
{

	Product prod1;
	Product* ptrProd1 = &prod1;
	SetProductPrice(ptrProd1, 100001);


	{
		IProductValidator* validator = new CustomerService();
		Product* product = new Product();
		product->price = 100001;
		if (validator->IsValid(*product))
		{
			std::cout << "Product is valid" << std::endl;
		}
		else
		{
			std::cout << "Product is invalid" << std::endl;
		}

		delete validator;
		validator = nullptr;
	}

	return 0;
}