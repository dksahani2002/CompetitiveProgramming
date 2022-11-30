#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class shopping{
    int pcode;
    float price;
    float dis;
    string pname;
    public:
     void menu();
     void adminstrator();
     void buyer();
     void add();
     void edit();
     void exc();
     void rem();
     void list();
     void reciept();
};
void shopping::menu(){
    m:
    int choice;
    string email;
    string password;
    cout<<"\t\t\t\t\t____________________________\n";
    cout<<"\t\t\t\t\t                            \n";
    cout<<"\t\t\t\t\t    SuperMarket Main Menu   \n";
    cout<<"\t\t\t\t\t                            \n";
    cout<<"\t\t\t\t\t____________________________\n";
    cout<<"\t\t\t\t\t                            \n";
    cout<<"\t\t\t\t\t  1) Adminstrator   |\n";
    cout<<"\t\t\t\t\t                    |\n";
    cout<<"\t\t\t\t\t  2) Buyer          |\n";
    cout<<"\t\t\t\t\t                    |\n";
    cout<<"\t\t\t\t\t  3) Exit           |\n";
    cout<<"\t\t\t\t\t                    |\n";
    cout<<"\n\t\t\t\t Please Select!";
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"\t\t\t Please Login \n";
            cout<<"\t\t\t Enter Email  \n";
            cin>>email;
            cout<<"\t\t\t Password     \n";
            cin>>password;
            if(email=="dd@gmail.com" && password=="dd@dd2022"){
                adminstrator();
            }else{
                cout<<"Invalid Email/Password     \n";
            }
            break;
        case 2:
            buyer();
        case 3:
            exc();
        default :
            cout<<"Please Select from the given option";
    }
    goto m;
}
void shopping::exc(){
    exit(0);
}
void shopping::adminstrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Adminstrator menu";
    cout<<"\n\t\t\t|_____1) Add the Product_____|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____2) Modify the Product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____3) Delete the Product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____4) Back to main Menu___|";
    cout<<"\n\n\t Please enter your choice";
    cin>>choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"Invalid Choice!";
    }
    goto m;
}
void shopping::buyer(){
    m:
    int choice;
    cout<<"\t\t\t  Buyer       \n";
    cout<<"                      \n";
    cout<<"\t\t\t 1) Buy Product \n";
    cout<<"                \n";
    cout<<"\t\t\t 2) Go Back \n";
    cout<<"\t\t\t Enter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        reciept();
        break;
    case 2:
        menu();
        break;
    default:
        cout<<"Invalid Choice";
    }
    goto m;
}
void shopping::add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\\t\t\t Add new Product";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t Name of the product";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on  product";
    cin>>dis;
    data.open("database.txt",ios::in);
    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token==1){
        goto m;
    }else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    cout<<"\n\n\t\t Record inserted";
}
void shopping::edit(){
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Enter the product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n File doesn't exist";
    }else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\n\t\t Price:";
                cin>>p;
                cout<<"\n\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited";
                token++;
            }else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"\n\n Record not found sorry! ";
        }
    }
}
void shopping::rem(){
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File doen't exist";
    }else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"\n\n Record not found";
        }
    }
}
void shopping::list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_____________________________________\n";
    cout<<"ProdNo\t\tName\t\tPrice\n";
    cout<<"\n\n|_____________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void shopping::reciept(){
    fstream data;
    int arrc[100];
    int arrq[100];
    int choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    cout<<"\n\n\t\t\t RECIEPT ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty Database";
    }else{
        data.close();
        list();
        cout<<"\n_______________________________\n";
        cout<<"\n|                              \n";
        cout<<"\n    Please place the order     \n";
        cout<<"\n|                              \n";
        cout<<"\n_______________________________\n";
        do{
            m:
            cout<<"\n\n Enter Product code :";
            cin>>arrc[c];
            cout<<"\n\n Enter the quantity :";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate Product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product or not";
            cin>>choice;
        }while(choice==1);
        cout<<"\n\n\t\t\t______________________RECIEPT___________________\n";
        cout<<"\nProduct No\t Product Name \t Product Quantity\t Amount with discount\n";
        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<"\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                    data>>pcode>>pname>>price>>dis;
                }
            }
        }
        data.close();

    }
    cout<<"\n\n______________________________________________";
    cout<<"\n Total Amount : "<<total;
}
int main(){
    shopping s;
    s.menu();
}