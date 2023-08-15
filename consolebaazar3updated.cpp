#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<windows.h>
#include<vector>
using namespace std;
class Customer;
class Products{
    private:
    int code;
    char name[50];
    float price;
    int quantity;
    friend class Customer;
    

    public:
    void getinfo(){
        cout<<"Name of Product: ";
        cin>>name;
        cout<<"Price: ";
        cin>>price;
        cout<<"Quantity: ";
        cin>>quantity;
        cout<<"Code of product: ";
        cin>>code;
    }
    void putinfo(){
        cout<<setw(6)<<code<<setw(15)<<name<<setw(20)<<quantity<<setw(8)<<price<<endl;
    }
    int code_ret(){
        return code;
    }
    void update_quantity(int n){
        quantity=n;

    }
    

};

class User{
    private: 
    char ch;
    string username;
    string password;
    string name;
    string address;
    friend class Admin;
   

    public:
    void getpersonalinfo(){
        cout<<"\nName: ";
      cin>>name;
      cin.ignore();
       
        cout<<"\nAddress: ";
        cin>>address;
        cin.ignore();
         }

     void getinfo() {
        char ch;
    cout << "Username: ";
    cin >> username;
    
    if (username.length() == 10) {
        cout << "Password: ";
        cin>>password;
       
      
    } else {
        cout << "Username should be a phone number with 10 digits." << endl;
        exit(1);
    }
}

     string &username_comp(){
        return username;
     }
     string &password_comp(){
        return password;
     }


};
class Admin{
    User u1;
    Products p1;

  public: 
    void Login();
    void Homepage();
    void signup();
    void signin();
    void options();
    void addrecord();
    void diskwrite(string s);
    void diskread(string st);
    void seeproduct();

};
void Admin::Login() {
   
    
    string username;
    string password;
    system("cls");
    int n;
    ofstream otfile;
    ifstream ifile;

    cout << "\n1. Don't Have an Account (Sign Up): ";
    cout << "\n2. Already Have an Account? (Sign In): "<<endl;
    cin >> n;

    switch(n) {
        case 1:
            signup();
         
            
            break;

        case 2:
            signin();
            Homepage();
            break;

        default:
            cout << "\nPlease Select Correct option.";
    }
}
void Admin::signup(){
    ofstream otfile;
    ifstream ifile;
    string username;
    string password;
     int flag2=0;
    system("cls");

            otfile.open("Credintialsad.dat", ios::binary | ios::app);
            ifile.open("Credintialsad.dat", ios::binary | ios::in);

            cout << "Enter your Phone number to generate your username: ";
            cin >> username;
            if(username.length()==10){

            ifile.read((char *)&u1, sizeof(u1));
            while (!(ifile.eof())) {
                if (u1.username_comp() == username) {
                    flag2 = 1;
                    cout << "\nPhone Number Already Used.";
                    cout << "Please Use Another username." << endl;
                    cout<<"\nPress any key to return to agiain restart your journey.";
                    getch();
                    break;
                }
                ifile.read((char *)&u1, sizeof(u1));
            }

            if (flag2 == 0) {
                cout << "\nYou Can Use This Phone Number As Username.";
                u1.getinfo();
                otfile.write((char *)&u1, sizeof(u1));
              
            }
            

            ifile.close();
            otfile.close();
            Login();
            }
            else{
                cout<<"Phone number must be of 10 digits."<<endl;
                cout<<"Press any key to return to Login page"<<endl;
                getch();
                Login();
            }

}
void Admin::signin(){
    ofstream ofile;
    ifstream ifile;
     int flag=0;
     string username;
     string password;
    system("cls");
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            ifile.open("Credintialsad.dat", ios::binary | ios::in);
            ifile.read((char *)&u1, sizeof(u1));

            while (!ifile.eof()) {
                if (u1.username_comp() == username && u1.password_comp() == password) {
                   
                    
                    flag = 1;
                    cout << "LogIn Successful";
                    cout << "\nPress any key to continue...";
                    getch();
                    Homepage();
                    break;
                }
                ifile.read((char *)&u1, sizeof(u1));
            }

            if (flag == 0) {
                cout << "\nUsername and Password didn't match";
                cout<<"\nPress any key to try again....";
                getch();
                Login();
            }

            ifile.close();
           

}
void Admin::Homepage() {
    int n;
    system("cls");
    string s="--------------------- WELCOME ADMIN -----------------------------------";
    for(int i=0;i<s.length();i++){
        Sleep(100);
        cout<<s[i];
        
    }
    Sleep(1000);
    cout<<"\n1.Add Products in the stores."<<endl;
    cout<<"\n2.See Products in the stores."<<endl;
    cin>>n;
    switch(n){
        case 1:
        addrecord();
        Homepage();

        case 2:
        seeproduct();
        Homepage();


         
          
    }

}
void Admin::addrecord(){
    int n;
    cout<<"\n1.Store 1";
    cout<<"\n2.Store 2";
    cout<<"\n3.Store 3"<<endl;
    cout<<"\n4.Go Back"<<endl;
    cin>>n;
    switch(n){

        case 1:
          diskwrite("store1.dat");
          addrecord();

        case 2:
        diskwrite("store2.dat");
        addrecord();

        case 3:
        diskwrite("stre3.dat");
        addrecord();


        case 4:
        Homepage();

        default:
           cout<<"\nUnmatched Choice";
           break;



    }
    
}
void Admin::seeproduct(){
    int n;
    cout<<"\n1.Store 1";
    cout<<"\n2.Store 2";
    cout<<"\n3.Store 3"<<endl;
    cin>>n;
    switch(n){
        case 1:
          cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          diskread("store1.dat");

          cout<<"Press any Key to return back......";
          getch();
          Homepage();

        case 2:
          cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          diskread("store2.dat");
          cout<<"Press any Key to return back......";
          getch();
          Homepage();


        case 3:
          cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          diskread("store3.dat");
          cout<<"Press any Key to return back......";
          getch();
          Homepage();


        default:
        break;
    }
}

void Admin::diskwrite(string st){
    char ch;
    ofstream ofile;
    ofile.open(st,ios::app|ios::out);
    do{
        p1.getinfo();
        ofile.write((char *)&p1,sizeof(p1));
        cout<<"Add other records: [y/n]?";
        cin>>ch;

    }while(ch=='y'||ch=='Y');
    ofile.close();


}
void Admin::diskread(string sn){
    ifstream infile;
    infile.open(sn,ios::app|ios::in);
    infile.read((char *)&p1,sizeof(p1));
    while((!infile.eof())){
        p1.putinfo();
        infile.read((char *)&p1,sizeof(p1));

    }
    infile.close();




}
class Customer{
     float sum=0.0;
    int quantity;
    User u;
    Products p;
    Admin a;
    string userfile;

public:
void Login();
void signup();
void signin();
void Homepage();
void StartShopping();
void BuyingStore(string s);
void ShoppingProduct(string s);
void generatebill(string s);
void previoushist();
void update(string ,int ,int);






};
void Customer::Login(){
    string username;
    string password;
    
   
    
    system("cls");
    int n;
    ofstream otfile;
    ifstream ifile;

    cout << "\n1. Don't Have an Account (Sign Up): ";
    cout << "\n2. Already Have an Account? (Sign In): "<<endl;
    cin >> n;

    switch (n) {
        case 1:
            signup();
         
            
            break;

        case 2:
            signin();
            Homepage();
            break;

        default:
            cout << "\nPlease Select Correct option.";
    }
}
void Customer::signup(){
     ofstream otfile;
    ifstream ifile;
    string username;
    string password;
     int flag2=0;
    system("cls");

            otfile.open("Credintialscu.dat", ios::binary | ios::app);
            ifile.open("Credintialscu.dat", ios::binary | ios::in);

            cout << "Enter your Phone number to generate your username: ";
            cin >> username;
            if(username.length()==10){

            ifile.read((char *)&u, sizeof(u));
            while (!(ifile.eof())) {
                if (u.username_comp() == username) {
                    flag2 = 1;
                    cout << "\nPhone Number Already Used.";
                    cout << "Please Use Another username." << endl;
                    cout<<"\nPress any key to  restart your journey.";
                    getch();
                    break;
                }
                ifile.read((char *)&u, sizeof(u));
            }

            if (flag2 == 0) {
                cout << "\nYou Can Use This Phone Number As Username.";
                u.getpersonalinfo();
                u.getinfo();
                otfile.write((char *)&u, sizeof(u));
              
            }
            

            ifile.close();
            otfile.close();
            cout<<"\nAccount Created Successfully........";
            cout<<"\nPlease wait 2 seconds while you are redirected to the login page.";
            Sleep(2000);
            Login();
            }
            else{
                cout<<"Phone number must be of 10 digits."<<endl;
                cout<<"Press any key to return to Login page"<<endl;
                getch();
                Login();
            }


}
void Customer::signin(){
    char ch;
     ofstream ofile;
    ifstream ifile;
     int flag=0;
     string username;
     string password;
    system("cls");
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
                 while ((ch = getch()) != '\r') {
            if (ch == '\b') {
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                }
            } else {
                password.push_back(ch);
                cout << '*';
            }
        }
        cout<<endl;
     
    


            

            ifile.open("Credintialscu.dat", ios::binary | ios::in);
            ifile.read((char *)&u, sizeof(u));

            while (!ifile.eof()) {
                if (u.username_comp() == username && u.password_comp() == password) {
                    
                    
                    flag = 1;
                    this->userfile=username;
                    cout << "LogIn Successful";
                    cout << "\nPress any key to continue...";
                    getch();
                    Homepage();
                    break;
                }
                ifile.read((char *)&u, sizeof(u));
                
            }

            if (flag == 0) {
                cout<<username;
                cout << "\nUsername and Password didn't match";
                cout<<"\nPress any key to try again....";
                getch();
                Login();
            }

            ifile.close();


}
void Customer::Homepage(){
       int n;
    system("cls");
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Sleep(100);
     SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    cout<<"-------------------------------------";
    string s="WELCOME  TO CONSOLE BAAZAR ";
    for(int i=0;i<s.length();i++){
        cout<<s[i];
        Sleep(100);
    }
    cout<<"--------------------------------------";
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

 
   
    cout<<endl;
    Sleep(1000);
    cout<<"\n1.Start Shopping"<<endl;
    cout<<"\n2.Generate Bill"<<endl;
    cout<<"\n3.See your Previous Buyings"<<endl;
    cout<<"\n4.Exit"<<endl;
    cin>>n;
    switch(n){
        case 1:
       StartShopping();
        Homepage();

        case 2:
       generatebill(userfile);
        Homepage();

        case 3:
        previoushist();
        Homepage();

 
        case 4:
        exit(3);

         
          
    }

}
void Customer::StartShopping(){
    system("cls");
    
    cout<<"\n1.Store 1";
    cout<<"\n2.Store 2";
    cout<<"\n3.Store 3"<<endl;
    cout<<"\n4.Return to Home Page"<<endl;
    cout<<"Choose The Store To Buy The Products"<<endl;
    int n;
    cin>>n;
    switch(n){
        case 1:
        cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          BuyingStore("store1.dat");
          StartShopping();

        case 2:
        cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          BuyingStore("store2.dat");
          StartShopping();

        case 3:
        cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          BuyingStore("store3.dat");
          StartShopping();

        case 4:
            Homepage();

          default:
          cout<<"Please Choose a valid option";
          getch();
          StartShopping();


          

          
          
    }





}
void Customer::BuyingStore(string sn){
    int flag=0;
    char ch;
    int code;
   
     ifstream infile;
     ofstream otfile;
    infile.open(sn,ios::app|ios::in);
    infile.read((char *)&p,sizeof(p));
    while((!infile.eof())){
        p.putinfo();
        infile.read((char *)&p,sizeof(p));

    }
    infile.close();
    cout<<endl;
    do{
        ShoppingProduct(sn);
        cout<<"Buy More Products From This Store:[y/n] "<<endl;
        cin>>ch;
    
            


        }while(ch=='y'||ch=='Y');
        
    
    }


    


void Customer::ShoppingProduct(string st) {
    string name;
    float price;
    int num;
    
    int flag = 0;
    int code;
    char ch;
    ifstream infile;
    ofstream otfile;

    cout << "Enter the Code of The Product You Would Like To Buy: ";
    cin >> code;
    cout << "Enter the quantity of The Product You Would Like To Buy: ";
    cin >> quantity;

    infile.open(st, ios::binary | ios::in);
    otfile.open(userfile + ".txt", ios::app | ios::binary);

    while (!infile.eof()) {
        infile.read((char*)&p, sizeof(p));
        if (p.code_ret() == code) {
            flag = 1;
            if(quantity>p.quantity){
                cout<<endl<<"Not Enough Quantity.";
                cout<<"Press BackSpace to move backwards "<<endl;
                getch();
                StartShopping();
            }
            num=p.quantity-quantity;
            code=p.code;
            name=p.name;
            price=p.price; 
            otfile<<'\t'<<code<<'\t';
            otfile<<'\t'<<name<<'\t';
            otfile<<'\t'<<price<<'\t';
            otfile<<'\t'<<quantity<<'\t';
            otfile<<endl;
            sum+=quantity*price;
        }
        update(st,code,num);

    }

    infile.close();
    otfile.close();

    if (flag == 0) {
        cout << "Product with that code doesn't exist." << endl;
        cout<<"Press any key to return to continue to store"<<endl;
        getch();


    }
}
void Customer::update(string st,int c,int q){
    

    fstream file;
    file.open(st,ios::binary |ios::in |ios::out);
    if(!file){
        cout<<st;
        cout<<"File Doesn't Exists"<<endl;
        getch();
    }
    while(file.read((char*)&p,sizeof(p))){
        if(p.code_ret()==c){
            p.update_quantity(q);
            int pos=sizeof(p);
            file.seekp(-pos,ios::cur);
            file.write((char *)&p,sizeof(p));
        }




    }
    file.close();

    











}
void Customer::generatebill(string st){
    string name;
    float price;
    
    int flag = 0;
    int code;
    char ch;
    string line;
    ifstream infile;
    ofstream otfile;
    string username=st+".txt";
    const char *cptr=username.c_str();
    

   
   otfile.open(st +"his.txt",ios::app);
    infile.open( st +".txt",ios::in);
   

    infile.seekg(0,ios::end);
    if(infile.tellg()==0){
        cout<<"You Haven't Bought any Product From Our Store.";
        cout<<endl;
        cout<<"First Buy Some Products From Our Store.";
        StartShopping();

    }
    infile.seekg(0,ios::beg);
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"\tCode\t\tName\t\tPrice\t\tQuantity\t"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
   while (std::getline(infile, line)) {
        std::cout << line << std::endl; 
        otfile<<line<<endl;
       
    }
    cout<<"\t\t\t\t\t\t\t\tTotal : "<<sum;
    
  
    infile.close();
    remove(cptr);
    

    otfile.close();
    
     getch();
    











}
void Customer::previoushist(){
    
    ifstream infile;
    string line;
    infile.open(userfile +"his.txt",ios::in);
    if(!(infile.good())){
        cout<<"You Don't Have  Any Buying History"<<endl;
        cout<<"Press BackSpace to move to previous page";
        getch();
        Homepage();

    }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout <<userfile<<"   Your History So Saved Here Are: " << std::endl;

    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
  cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"\tCode\t\tName\t\tPrice\t\tQuantity\t"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
      while (std::getline(infile, line)) {
        std::cout << line << std::endl; 
        
       
    }
    getch();
    
    









}

    





int main() {
    Admin a1;
    Customer c1;
  char ch;
  cout<<"\n a.Enter as Admin";

  cout<<"\nb.Enter as Customer";
  cin>>ch;
  if(ch=='a'){
    a1.Login();
  }
  if(ch=='b'){
    c1.Login();

  }
  else {
    cout<<"Enter a valid option ";
      main();
  }


}