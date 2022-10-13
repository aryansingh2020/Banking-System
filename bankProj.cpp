#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;

class Account
{
    private:
    long long accountNumber;
    int pin;
    long long contactNumber;
    string name;
    string dob;  //date validity checker is pending
    long balance;
    public :
    void createAccount()
    {
        cout<<string(58,'-')<<endl;
        cout<<"     Enter your name : ";
        cin.ignore();
        getline(cin,name);
        cout<<"     Enter your mobile number :";
        cin>>contactNumber;  
        cout<<"     Enter your DOB (dd/mm/yyyy) : ";
        cin.ignore();
        getline(cin,dob);
        cout<<"     Create your 4 digit pin : ";
        cin>>pin;
        cout<<"     Enter amount to deposit : ";
        cin>>balance;
        srand(time(0));
        this->accountNumber=700000000000+rand();
        cout<<"Congratulations! your account has been created.\n";
        cout<<"Your account number is :"<<this->accountNumber<<endl;
        cout<<"Please note the account number for future references.\n";
        cout<<string(58,'-')<<endl;
    }
    bool verifier(long long accountNumber,int pin)
    {
        if(accountNumber==this->accountNumber && pin==this->pin)
        {
            return(true);
        }
        else 
        {
            return(false);
        }
    }
    void showDetails()
    {
        cout<<string(58,'-')<<endl;
        cout<<"     Account number : "<<accountNumber<<endl;
        cout<<"     Account holder's name : "<<name<<endl;
        cout<<"     Contact number : "<<contactNumber<<endl;
        cout<<"     DOB : "<<dob<<endl;
        cout<<"     Balance left : "<<balance<<endl;
        cout<<string(58,'-')<<endl;
    }
    void withdraw()
    {
        long tempBalance;
        cout<<string(58,'-')<<endl;
        cout<<"Enter the amount to withdraw :";
        cin>>tempBalance;
        if(tempBalance>this->balance)
        {
            cout<<"Enter amount less than current amount.\n";
            this->withdraw();
        }
        else
        {
            this->balance=balance-tempBalance;
            cout<<"Amount withdrawn :"<<tempBalance<<endl;
            cout<<"Balance left :"<<this->balance<<endl;
            cout<<string(58,'-')<<endl;
        }
    }
    void deposit()
    {
        long tempBalance;
        cout<<string(58,'-')<<endl;
        cout<<"Enter the amount to deposit :";
        cin>>tempBalance;
        this->balance=balance+tempBalance;
        cout<<"Balance left :"<<this->balance<<endl;
        cout<<string(58,'-')<<endl;
    }
    void changePin()
    {
        int tempPin1;
        int tempPin2;
        cout<<string(58,'-')<<endl;
        cout<<"Enter the new 4-digit pin :";
        cin>>tempPin1;
        cout<<"Re-enter the new 4-digit pin :";
        cin>>tempPin2;
        if(tempPin2==tempPin1)
        {
            cout<<"Your pin has been updated.\n";
            this->pin=tempPin2;
            cout<<string(58,'-')<<endl;
        }
        else
        {
            cout<<"Error! enter same pin number in above fields.\n";
            this->changePin();
        }
    }
    long long getAccountNumber()
    {
        return(this->accountNumber);
    }
    int getPin()
    {
        return(this->pin);
    }
};

int main()
{
    long long tempAccountNumber;
    int tempPin;
    int size=20;
    Account*acc=new Account[size];
    int user=0;
    while(user!=20)
    {
        int choice;
        cout<<string(58,'#')<<endl;
        cout<<"      1. Create new account.\n";
        cout<<"      2. See existing user's account details.\n";
        cout<<"      3. Deposit money.\n";
        cout<<"      4. Withdraw money.\n";
        cout<<"      5. Change PIN.\n";
        cout<<"      6. Exit\n";
        cout<<"      Please choose the appropriate option :";
        cin>>choice;
        cout<<string(58,'#')<<endl;
        switch(choice)
        {
            case 1:acc[user].createAccount();
            user++;
            break;
            case 2:
            cout<<"Enter your account number :";
            cin>>tempAccountNumber;
            cout<<"Enter your PIN :";
            cin>>tempPin;
            for(int i=0;i<=size;i++)
            {
                if(acc[i].verifier(tempAccountNumber,tempPin))
                {
                    acc[i].showDetails();
                    break;
                }
                else if(i==size)
                {
                    cout<<"Please enter valid details.\n";
                }              
            }
            break;
            case 3:
            cout<<"Enter your account number :";
            cin>>tempAccountNumber;
            cout<<"Enter your PIN :";
            cin>>tempPin;
            for(int i=0;i<=size;i++)
            {
                if(acc[i].verifier(tempAccountNumber,tempPin))
                {
                    acc[i].deposit();
                    break;
                }
                else if(i==size)
                {
                    cout<<"Please enter valid details.\n";
                }              
            }
            break;
            case 4:
            cout<<"Enter your account number :";
            cin>>tempAccountNumber;
            cout<<"Enter your PIN :";
            cin>>tempPin;
            for(int i=0;i<=size;i++)
            {
                if(acc[i].verifier(tempAccountNumber,tempPin))
                {
                    acc[i].withdraw();
                    break;
                }
                else if(i==size)
                {
                    cout<<"Please enter valid details.\n";
                }              
            }
            break;
            case 5:
            cout<<"Enter your account number :";
            cin>>tempAccountNumber;
            cout<<"Enter your PIN :";
            cin>>tempPin;
            for(int i=0;i<=size;i++)
            {
                if(acc[i].verifier(tempAccountNumber,tempPin))
                {
                    acc[i].changePin();
                    break;
                }
                else if(i==size)
                {
                    cout<<"Please enter valid details.\n";
                }              
            }
            break;
            default:exit(1);
        }
    }
}
