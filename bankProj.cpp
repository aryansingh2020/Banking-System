#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;

class account
{
    private:
    string name;
    string dob;
    long acc_no=0;
    int pin=0;
    float balance=0;
    long mob_no=0;
    public:
    void createAccount(string a,string b,int c,int d,int e)
    {
        this->name=a;
        this->dob=b;
        this->mob_no=c;
        this->pin=d;
        this->balance=e;
        srand(time(0));
        this->acc_no=10000000+rand();
        cout<<"\n################################################\n";
        cout<<"  Your Account number is : "<<this->acc_no<<endl;
        cout<<"  Congratulations,your account has been created.\n";
        cout<<"\n################################################\n";
    }
    void showDetails()
    {
        cout<<"\n##########################################\n";
        cout<<"     Account number : "<<acc_no<<endl;
        cout<<"     Account holder's name : "<<name<<endl;
        cout<<"     Mobile number : "<<mob_no<<endl;
        cout<<"     DOB : "<<dob<<endl;
        cout<<"     Balance left : "<<balance<<endl;
        cout<<"\n##########################################\n";
    }
    void withDraw(float value)
    {
        this->balance=this->balance-value;
        cout<<"\n######################################################\n";
        cout<<"    Transaction succesfull.\n   Amount debited : "<<value<<endl;
        cout<<"    Balance left : "<<this->balance<<endl;
        cout<<"\n######################################################\n";
    }
    void deposit(float value)
    {
            this->balance=this->balance+value;
            cout<<"\n######################################################\n";
            cout<<"    Transaction successfull.\n   Amount deposited : "<<value<<endl;
            cout<<"    Balance left : "<<balance<<endl;
            cout<<"\n######################################################\n";
    }
    int getAccNumb()
    {
        return(this->acc_no);
    }
    int getPin()
    {
        return(pin);
    }
};
int main()
{
    int user=0;
    account*accs=new account[20];
    while(user!=20)
    {
        int choice;
        cout<<"\n######################################################\n";
        cout<<"  Maximum account allowed in this bank is 20."<<endl;
        cout<<"            [1] Create account."<<endl;
        cout<<"            [2] View account details."<<endl;
        cout<<"            [3] Withdraw money."<<endl;
        cout<<"            [4] Deposit money."<<endl;
        cout<<"         Any other key to exit."<<endl;
        cout<<"  Press the indicated number : ";
        cin>>choice;
        cout<<"\n######################################################\n";    
        string username;
        int pincode;
        int temp1=0,temp2=0;
        float temp3=0;
        int user_numb;
        string name;
        string dob;
        long mob_no;
        int pin;
        float balance;
        switch(choice)
        {
            case 1:
            cout<<"\n######################################################\n";
            cout<<"     Enter your name : ";
            cin.ignore();
            getline(cin,name);
            cout<<"     Enter your mobile number :";
            cin>>mob_no;   
            cout<<"     Enter your DOB (dd/mm/yyyy) : ";
            cin.ignore();
            getline(cin,dob);
            cout<<"     Create your Pin : ";
            cin>>pin;
            cout<<"     Enter amount to deposit : ";
            cin>>balance;
            cout<<"     Your user number is : "<<user+1<<endl;
            accs[user].createAccount(name,dob,mob_no,pin,balance);
            cout<<"\n######################################################\n";
            user++;
            break;

            case 2: 
            cout<<"\n######################################################\n";
            cout<<"Enter your Account number : ";
            cin>>temp1;
            cout<<"Enter your Pin number : ";
            cin>>temp2;
            cout<<"\n######################################################\n";
            for(int i=0;i<(user+1);i++)
            {
                if((temp1==accs[i].getAccNumb()) && (temp2==accs[i].getPin()))
                {
                    accs[i].showDetails();
                }
            }
            break;

            case 3:
            cout<<"Enter your Account number : ";
            cin>>temp1;
            cout<<"Enter your Pin number : ";
            cin>>temp2;
            for(int i=0;i<20;i++)
            {
                if((temp1==accs[i].getAccNumb()) && (temp2==accs[i].getPin()))
                {
                    cout<<"Enter the amount to withdraw : ";
                    cin>>temp3;
                    accs[i].withDraw(temp3);
                }
            }
            break;

            case 4:
            cout<<"Enter your Account number : ";
            cin>>temp1;
            cout<<"Enter your Pin number : ";
            cin>>temp2;
            for(int i=0;i<20;i++)
            {
                if((temp1==accs[i].getAccNumb() && temp2==accs[i].getPin()))
                {
                    cout<<"Enter the amount to deposit : ";
                    cin>>temp3;
                    accs[i].deposit(temp3);
                }
            }
            break;

            default:main();
            break;
        }
    }
}