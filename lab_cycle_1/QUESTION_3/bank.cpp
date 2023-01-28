#include<iostream>
#include<string>
int srno=100;
using namespace std;
class bank
{
    private:
    string cust_name;
    int acc_no;
    long balance;
    string acc_type;
    public:
    void addacc(void);
    void withdraw(void);
    void deposit(void);
    void balance_check(void);
    void statement(void);
};
void bank::addacc(void)
{
    acc_no=srno;
    cout<<"Enter the Details:"<<endl;
    cout<<"Enter the Accounter Holder Name:";
    cin>>cust_name;
    cout<<"Enter the Account Type:";
    cin>>acc_type;
    cout<<"Enter the balance amount greater than 500:";
    cin>>balance;
    while(balance<500)
    {
        cout<<"The entered balance is less than 500, Please Enter the balance amount greater than 500:";
        cin>>balance;   
    }
    cout<<"Your Account Number:"<<acc_no<<endl;
    cout<<"New Account Created. "<<endl<<endl;
}
void bank::withdraw(void)
{
    int amt;
    cout<<"----------WITHDRAWAL----------"<<endl;
    cout<<"The Account Balance is:"<<balance;
    cout<<"Enter the amount to be withdrawn:";
    cin>>amt;
    while(balance-amt>500)
    {
        cout<<"The balance will be less than 500, Withdrawal not Possible!"<<endl;
        cout<<"Enter lesser amount:";
        cin>>amt;
    }
    balance=balance-amt;
    if(balance>0)
    cout<<amt<<"Rupees has been withdrawn, New Balance="<<balance<<"Rupees"<<endl;
    else
    cout<<"Insuficient Balance, Withdrawal not possible!"<<endl;
}
void bank::deposit(void)
{
    int amt;
    cout<<"----------DEPOSIT----------"<<endl;
    cout<<"Enter the amount to be deposited:";
    cin>>amt;
    balance=balance+amt;
    cout<<amt<<"Rupees has been deposited, New Balance="<<balance<<"Rupees"<<endl;
}
void bank:: balance_check(void)
{
    cout<<"----------BALANCE----------"<<endl;
    cout<<"Your Account Balance is:"<<balance<<"Rupees"<<endl;
}
void bank::statement(void)
{
    cout<<"----------STATEMENT----------"<<endl;
    cout<<" Name            : "<<cust_name<<endl;
    cout<<"Account Number   : "<<acc_no<<endl;
    cout<<"Account Type     : "<<acc_type<<endl;
    cout<<"Account Balance  : "<<balance<<endl;
    cout<<"-----------------------------"<<endl;
}
int main()
{
    bank ob[2000];
    int flag=1;
    int no=0,n;
    while(flag==1)
    {
        cout<<"\n---------------BANK----------------"<<endl;
        cout<<"---SELECT THE TRANSACTION YOU NEED---"<<endl;
		cout<<"\n   1	: Add an account ";
		cout<<"\n   2	: Withdraw amount";
		cout<<"\n   3	: Deposit amount ";
		cout<<"\n   4	: Balance check";
		cout<<"\n   5	: Bank Statement ";
		cout<<"\nAny other key : EXIT";
		cout<<endl<<"Give your input : ";
		cin>>n;
        if((n>1)&&(n<=5))
        {
            cout<<"Enter your Account Number:";
            cin>>no;
            while((no<100)&&(no>srno))
            {
                cout<<"Incorrect Account Number, Please enter the correct Account Number:";
                cin>>no;
            }
        }
        switch(n)
        {
            case 1:
            ob[srno].addacc();
            srno++;
            break;
            case 2:
            ob[no].withdraw();
            break;
            case 3:
            ob[no].deposit();
            break;
            case 4:
            ob[no].balance_check();
            break;
            case 5:
            ob[no].statement();
            break;
            default:
            cout<<"Thank You";
            flag=0; 
        }
    }
    return 0;
}
