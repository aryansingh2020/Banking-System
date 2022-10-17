#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<string>
#include<stdlib.h>
using namespace std;
/*Don't get confused with the same names of variables used in this code.Every variables used have a scope either within the class or function.They are not he same.*/
class Account
{
    private:
    long long accountNumber;// variable to store generated account number.
    int pin;                // variable to store PIN number.
    long long contactNumber;// variable to store contact number of the user
    string name;            // variable to store name of the user.
    string gender;          // variable to store gender of the user.
    string dob;             // variable to store date of birth of the user.
    long balance;           // variable to store manage account money.
    
    public :
    Account()
    {
        accountNumber=0;
        pin=0;
        contactNumber=0;
        name="__";
        gender="__";
        dob="00/00/0000";
        balance=0;
    }
    void createAccount()    //method to create new user account.
    {
        cout<<string(128,'-')<<endl;
        cout<<"->Enter your name : ";
        cin.ignore();
        getline(cin,name);
        cout<<"->Enter your mobile number :";
        cin>>contactNumber;  
        cout<<"->Enter your DOB (dd/mm/yyyy) : ";
        cin.ignore();
        getline(cin,dob);
        cout<<"->Enter your gender(Male/Female/Other) :";
        cin>>gender;
        cout<<"->Create your 4 digit pin : ";
        cin>>pin;
        cout<<"->Enter amount to deposit : ";
        cin>>balance;
        srand(time(0));
        this->accountNumber=700000000000+rand();
        cout<<"  Congratulations! "<<this->name<<" your account has been created.\n";
        cout<<"  Your account number is :"<<this->accountNumber<<endl;
        cout<<"  Please note your account number and PIN for future references.\n";
        cout<<string(128,'-')<<endl;
    }
    bool verifier(long long accountNumber,int pin) //method invoked to verify an existing user.It returns true for 
    {                                              // if user account already exists else returns false. 
        if(accountNumber==this->accountNumber && pin==this->pin)
        {
            return(true);
        }
        else 
        {
            return(false);
        }
    }
    void showDetails()  //method used to show account details of an existing user.
    {
        cout<<string(128,'-')<<endl;
        cout<<"- Account number : "<<accountNumber<<endl;
        cout<<"- Account holder's name : "<<name<<endl;
        cout<<"- Contact number : "<<contactNumber<<endl;
        cout<<"- DOB : "<<dob<<endl;
        cout<<"- Balance left : "<<balance<<endl;
        cout<<string(128,'-')<<endl;
    }
    void withdraw()    //method used to withdraw money from the account.
    {
        long tempBalance;
        cout<<string(128,'-')<<endl;
        cout<<"  Available amount :"<<this->balance<<endl;
        cout<<"->Enter the amount to withdraw :";
        cin>>tempBalance;
        if(tempBalance>this->balance)
        {
            cout<<"  Please enter amount less than current balance.\n";
            this->withdraw();
        }
        else
        {
            this->balance=balance-tempBalance;
            cout<<"  Amount withdrawn :"<<tempBalance<<endl;
            cout<<"  Balance left :"<<this->balance<<endl;
            cout<<string(128,'-')<<endl;
        }
    }
    void deposit()   //method used to deposit money into the account.
    {
        long tempBalance;
        cout<<string(128,'-')<<endl;
        cout<<"->Enter the amount to deposit :";
        cin>>tempBalance;
        this->balance=balance+tempBalance;
        cout<<"  Balance left :"<<this->balance<<endl;
        cout<<string(128,'-')<<endl;
    }
    void login()  //method used for logging in the existing user.
    {
        int choice;
        string tempDob,tempName;
        long long tempContact;
        cout<<string(128,'-')<<endl;
        cout<<"Welcome back! "<<this->name<<","<<endl;
        cout<<"  1. See your account details.\n";
        cout<<"  2. Update your account details.\n";
        cout<<"  3. Withdraw money.\n";
        cout<<"  4. Deposit money\n";
        cout<<"  5. Exit\n";
        cout<<"->Enter the appropriate option :";
        cin>>choice;
        cout<<string(128,'-')<<endl;
        switch(choice)
        {
            case 1:this->showDetails();
            break;
            case 2:this->changeDetails();
            break;
            case 3:this->withdraw();
            break;
            case 4:this->deposit();
            break;
            default:break;
        }
    }
    void changePin()  //method used to change the PIN number.
    {
        int tempPin1;
        int tempPin2;
        cout<<string(128,'-')<<endl;
        cout<<"->Enter the new 4-digit pin :";
        cin>>tempPin1;
        cout<<"->Re-enter the new 4-digit pin :";
        cin>>tempPin2;
        if(tempPin2==tempPin1)  //double verification of new PIN before changing the existing PIN number.
        {
            cout<<"  Your pin has been updated.\n";
            this->pin=tempPin2;
            cout<<string(128,'-')<<endl;
        }
        else
        {
            cout<<"  Error! plese enter same pin number in above fields.\n";
            this->changePin();
        }
    }

    void changeDetails()  //method used to change user account details.
    {
        int choice;
        string tempDob,tempName;
        long long tempContact;
        cout<<"  1. Change contact number.\n";
        cout<<"  2. Change date of birth.\n";
        cout<<"  3. Change PIN.\n";
        cout<<"  4. Change account holder's name.\n";
        cout<<"  5. Exit\n";
        cout<<"->Enter the appropriate option :";
        cin>>choice;
        cout<<string(128,'-')<<endl;
        switch(choice)
        {
            case 1:
            cout<<"  Enter the new contact number :";
            cin>>tempContact;
            this->contactNumber=tempContact;
            cout<<"  Your contact detail has been updated\n";
            cout<<string(58,'-')<<endl;
            break;
            case 2:
            cin>>tempDob;
            this->dob=tempDob;
            cout<<"Your date of birth is updated\n";
            cout<<string(128,'-')<<endl;
            break;
            case 3:
            this->changePin();
            break;
            case 4:
            cout<<"->Enter new account holder's name :";
            cin.ignore();
            getline(cin,tempName);
            this->name=tempName;
            cout<<"  Account holder's name has been updated\n";
            cout<<string(128,'-')<<endl;
            break;
            default:break;
        }
    }
};

int main() //Driver function-> main()
{
    long long tempAccountNumber;
    int tempPin;
    int size=20;
    Account*acc=new Account[size];
    int user=0;
    while(user!=20)
    {
        int choice;
        cout<<string(128,'=')<<endl;
        cout<<"  ||||||||    ||||   |||   || ||   || |||||||| |||   ||   |||||||     |||||||| ||    || |||||||| |||||||| ||||||| ||||   ||||\n";
        cout<<"  ||     ||  ||  ||  ||||  || ||  ||     ||    ||||  ||  ||          ||         ||  || ||           ||    ||      || || || ||\n";
        cout<<"  ||||||||  |||||||| || || || |||||      ||    || || || ||   |||||    ||||||||   ||||   ||||||||    ||    ||||||| ||  |||  ||\n";
        cout<<"  ||     || ||    || ||  |||| ||  ||     ||    ||  ||||  ||     ||           ||   ||           ||   ||    ||      ||       ||\n";
        cout<<"  ||||||||  ||    || ||   ||| ||   || |||||||| ||   |||   |||||||    |||||||||    ||   |||||||||    ||    ||||||| ||       ||\n";
        cout<<string(128,'=')<<endl;        
        cout<<"Welcome to the Banking System.\n";
        cout<<"  1. New user registration.\n";
        cout<<"  2. Existing user login.\n";
        cout<<"  3. Exit\n";
        cout<<"  Please choose the appropriate option :";
        cin>>choice;
        switch(choice)  //switch condition to ask user for his/her choice of option.
        {
            case 1:acc[user].createAccount();
            user++;
            break;
            case 2:
            cout<<string(128,'-')<<endl;
            cout<<"->Enter your account number :";
            cin>>tempAccountNumber;
            cout<<"->Enter your PIN :";
            cin>>tempPin;
            for(int i=0;i<=size;i++)  //for loop to iterate among every existing account in the dynamic memory.
            {
                if(acc[i].verifier(tempAccountNumber,tempPin))
                {
                    acc[i].login();
                    break;
                }
                else if(i==size)
                {
                    cout<<"  Error! please enter valid details.\n";
                }              
            }
            break;
            default:exit(1);
        }
    }
}
