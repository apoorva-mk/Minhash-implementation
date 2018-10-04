#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
ifstream fin;
ofstream fout;
fstream file;

class product{
    int pid;
    char pname[20];
    int rate;
    int stock;
    public:
    void setdata(){
    cout<<"enter product id"<<endl;
    cin>>pid;
    cout<<"enter product name"<<endl;
    char ch;
    cin.get(ch);
    cin.getline(pname,20);
    cout<<"enter product rate"<<endl;
    cin>>rate;
    cout<<"enter product stock"<<endl;
    cin>>stock;
    }

void showdata(){              //TO DISPLAY ALL PRODUCTS
    cout<<"pid       product name   cost      available stock"<<endl;
    cout<<pid<<"          "<<pname<<"             "<<rate<<"        "<<stock<<endl;
}
int returnpid(){
return pid;}
void changestock(int m){         //FOR ADDING STOCK
    stock=stock+m;
}
void reducestock(int n){         //TO REDUCE THE QUANTITY OF ITEMS IN STOCK
stock=stock-n;}
int returnstock(){return stock;}   //RETURNS THE QUANTITY OF A PURTICULAR ITEM
int returnrate(){return rate;}     //RETURNS RATE OF A PURTICULAR ITEM



};
class sale{                                   //FOR ALL THE DETAILS OF SALE IN A DAY
    int id;
    int q;

    int total;
public:
    void setsale(int n,int m,int t){            //TO SET SALE DETAILS
        id=n;
        q=m;
        total=t;
    }
    void showsale(){                              //DISPLAY SALE DETAILS
    cout<<"product id :"<<id<<endl;
    cout<<"product quantity :"<<q<<endl;
    cout<<"total cost :"<<total<<endl;
cout<<endl;
    }
    int returntotal(){
    return total;}
    };
    int getcoup();
    class customer{
    int cid;
    char cname[1000];
    int coupon;
public:
    void setcustom(int p){
   cout<<"enter customer id"<<endl;
   cin>>cid;
   cout<<"enter customer name"<<endl;
   char ch;cin.get(ch);
   cin.getline(cname,25);
   coupon=p;
    }
    int getcoupon(){
    return coupon;}
};
        void setcustomer(){               //FOR CUSTOMER DETAILS
            int p;
            p=getcoup();
            fout.open("customer.dat",ios::app|ios::binary);
            customer obj;
            obj.setcustom(p);
            fout.write((char*)&obj,sizeof(obj));
            fout.close();

        }
    void writesale(int n,int m,int t){
    sale obj;
    fout.open("sale.dat",ios::app|ios::binary);
    obj.setsale(n,m,t);
    fout.write((char*)&obj,sizeof(obj));
    fout.close();
    }
    void displaysale(){           //TO DISPLAY SALE DETAILS
    fin.open("sale.dat",ios::in|ios::binary);
    sale obj;
    while(fin.read((char*)&obj,sizeof(obj)))
    {
        obj.showsale();
    }
    }
void reducestock(int m,int n){
    product obj;
    long fp;
   file.open("product.dat",ios::in|ios::out|ios::binary);
while(file.read((char*)&obj,sizeof(obj)))
{
    if(obj.returnpid()==n)
      {

       obj.reducestock(m);
       fp=file.tellg();
       file.seekp(fp-1*sizeof(obj));

file.write((char*)&obj,sizeof(obj));}
}
file.close();
}


void addstock(){                                  //FUNCTION TO ADD STOCK
    int n,a;
    long fp;
    product obj;
    cout<<"enter product id of the required product"<<endl;
    cin>>n;
    cout<<"enter stock amount"<<endl;
cin>>a;
file.open("product.dat",ios::in|ios::out|ios::binary);
while(file.read((char*)&obj,sizeof(obj)))
{
    if(obj.returnpid()==n)
      {

       obj.changestock(a);
       fp=file.tellg();
       file.seekp(fp-1*sizeof(obj));

file.write((char*)&obj,sizeof(obj));}
}
file.close();
}
void enter(){                      //TO ENTER NEW PRODUCTS
    fout.open("product.dat",ios::app|ios::binary);
    product obj;
    obj.setdata();
    fout.write((char*)&obj,sizeof(obj));
    fout.close();
}
void display(){
fin.open("product.dat",ios::in|ios::binary);
product obj;
while(fin.read((char*)&obj,sizeof(obj)))
{
    obj.showdata();
}
fin.clear();
fin.close();
}
int totalbill(){                           //TO CALCULATE TOTAL INCOME OF THE DAY
    int total=0;
fin.open("sale.dat",ios::in|ios::binary);
sale obj;
while(fin.read((char*)&obj,sizeof(obj)))
{
    total=total+obj.returntotal();
}
fin.clear();
fin.close();

return total;
}
void makebill(){                       //FOR BILLING
    int c,n,m,r,total=0,num,coupon,discount;
    long fp,f;
    product obj;
    sale ob;

    do{
        file.open("product.dat",ios::in|ios::out|ios::binary);
        setcustomer();
        cout<<"enter product id"<<endl;
        cin>>n;
        cout<<"enter product quantity"<<endl;
        cin>>m;
        while(file.read((char*)&obj,sizeof(obj)))
        {
            if(obj.returnpid()==n)
            {
                    if(obj.returnstock()>=m)
                 {

                  total=total+obj.returnrate()*m;


                  writesale(n,m,total);}
                  else
                    cout<<"out of stock"<<endl;

            }


}
cout<<"to enter more  products press 1 "<<endl;
         cout<<"to get total bill amount press 2"<<endl;

                  cin>>c;
reducestock(m,n);
                  file.close();
        }while(c==1);
cout<<"Press 1 to redeem your coupon(if any ,else press 2)"<<endl;
cin>>num;
if(num==1){
    cout<<"enter coupon id"<<endl;
    cin>>coupon;
    file.open("customer.dat",ios::in|ios::out|ios::binary);
    customer obj;
    while(file.read((char*)&obj,sizeof(obj)))
   {if(obj.getcoupon()>=1000&&obj.getcoupon()<5000)
       {discount=10;
        long fp;
        fp=file.tellg();
        file.seekp(fp,ios::beg);
       }
    else if(obj.getcoupon()>=5000&&obj.getcoupon()<10000)
    {
        discount=20;
         long fp;
        fp=file.tellg();
        file.seekp(fp,ios::beg);
    }
       }
       file.close();
       cout<<"you got a discount of "<<discount<<" %"<<endl;
       cout<<"your original bill amount is :"<<total<<endl;
       int r;
       r=(discount*total)/100;
       total=total-r;
       cout<<"after discount , amount to be paid is Rs "<<total<<endl;
}
else
    cout<<"total bill amount is :"<<total<<endl;


       if(total>=100)
       {
           cout<<"you are our lucky customer!!!"<<endl;
           cout<<"here is your coupon code to get discount"<<endl;
           cout<<"coupon number :"<<getcoup()<<endl;
           cout<<"you can access your coupon in your next transaction"<<endl;

       }
       cout<<"Thank You for shopping with us"<<endl;
       cout<<"have a nice day"<<endl;
    }

    int getcoup(){                //TO GENERATE COUPON...
        srand((int)time(0));
        int coup;                     //TIME FUNCTION USED

    coup=(rand() % 9999) + 1000;
           return coup;
    }



int main(){
    int choice;

    while(1){
system("cls");
        cout<<"enter 1 to enter new products to the store"<<endl;
        cout<<"enter 2 for billing"<<endl;
        cout<<"enter 3 to add stock "<<endl;
        cout<<"enter 4 to display available products"<<endl;
        cout<<"enter 5 to display sale details"<<endl;
        cout<<"enter 6 to display total sale of the day"<<endl;

        cin>>choice;
        switch(choice){
    case 1:{enter();
    }break;
    case 2:{cout<<"available products are:"<<endl;
    display();
    makebill();
    }break;
    case 3:{cout<<"available products are"<<endl;
    display();
    addstock();
    }
    break;
    case 4:display();
    break;
    case 5:displaysale();
    break;
    case 6:cout<<"total income of the day is : Rs "<<totalbill();
    break;

        }

        system("pause");

    }
    return 0;
    }
