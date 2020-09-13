#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  
class Iobserver
{
   public:
   virtual void newUpdateshow(float price)=0;
};
class Shop : public Iobserver
{
   std::string name;
   float price;
 public:
   Shop(string name )
   {
   this->name=name;
   }
 void newUpdateshow(float price)
 {
   cout<<"price at"<<name<<"   "<<price<<endl; 
 }
 
};
class shopOperationObject
{
 vector<Shop*> list;
 vector<Shop*>:: iterator it;

public :
  void suscribe(Shop *p)
  {
  list.push_back(p);
  }

 void unsubscribe(Shop *p)
{
 list.erase(remove(list.begin(),list.end(),p),list.end()); 
}

void notifyinfo(float price )
   {
   for(auto itr=list.begin();itr!=list.end();itr++)
     {

        if(*itr != 0)
           {
                (*itr)->newUpdateshow(price);
           }


       }
   }

};


class updateproductinfo:public shopOperationObject
{
   public: 
   void changeprice(float price)
    {
    notifyinfo(price);
    }

};

int main()
{
updateproductinfo product;
Shop s1("shop1");
Shop s2("shop 2");
product.suscribe(&s1);
product.suscribe(&s2);
product.changeprice(10);
product.unsubscribe(&s2);

product.changeprice(15);

return 0;
}
