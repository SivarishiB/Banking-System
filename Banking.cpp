//Bank Management System using Class & inheritance in C++

#include<iostream>
using namespace std;

class account
{
private:
    string name;
    int accno;
    string acctype;

public:
    void details()
    {
        cout<<"\nEnter the customer name"<<endl;
        cin>>name;
        cout<<"\nEnter the account number"<<endl;
        cin>>accno;
        cout<<"\nEnter the account type"<<endl;
        cin>>acctype;
    }
    void display()
    {
        cout<<"\nCustomer name:"<<name<<endl;
        cout<<"Account number:"<<accno<<endl;
        cout<<"account type:"<<acctype;
    }
};
class current:public account
{
private:
    float balance;
public:
    void c_display()
    {
        cout<<"\nBalance:"<<balance;
    }
    void c_deposit()
    {
        float deposit;
        cout<<"Enter the amount to deposit :"<<endl;
        cin>>deposit;
        balance = balance + deposit;
        cout<<"\nYou have deposited:"<<deposit;
    }
    void c_withdraw()
    {
        float withdraw;
        cout<<"\nBalance :"<<balance;
        cout<<"Enter the amount to withdraw :"<<withdraw;
        cin>>withdraw;

        if(balance > 1000)
        {
            balance = balance - withdraw;
            cout<<"\nUpdated balance :"<<balance;
        }
        else{
            cout<<"\nInsufficient balance";
        }
    }
};
class savings:public account
{
private:
    float s_balance;

public:
    void s_display()
    {
        cout<<"\nBalance"<<s_balance;
    }
    void s_deposit()
    {
        float deposit,interest;
        cout<<"Enter the amount to deposit:";
        cin>>deposit;
        s_balance= s_balance + deposit;
        interest = (s_balance*2)/100;
        s_balance = s_balance + interest;
        cout<<"\nYou have deposited:"<<deposit;
    }
    void s_withdraw()
    {
        float withdraw;
        cout<<"Balance"<<s_balance;
        cout<<"\nEnter the amount to withdraw:";
        cin>>withdraw;
        if(s_balance > 500)
        {
            s_balance = s_balance - withdraw;
            cout<<"\nUpdated balance:"<<s_balance;
        }
        else{
            cout<<"\nInsufficient balance";
        }
    }
};
int main()
{
    current c1;
    savings s2;
    char type;
    cout<<"\nEnter S for saving a\c or Enter C for current a\c:";
    cin>>type;
    int choice;
    if(type == 's' || type == 'S')
    {
     s2.details();
     while(1)
    {
        cout<<"\nChoose your option";
        cout<<"\n1) Balance";
        cout<<"\n2) Withdraw";
        cout<<"\n3) Deposit";
        cout<<"\n4) Display details";
        cout<<"\n5) Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;

        switch(choice)
        {
        case 1:
            s2.s_display();
            break;
        case 2:
            s2.s_withdraw();
            break;
        case 3:
            s2.s_deposit();
            break;
        case 4:
            s2.display();
            s2.s_display();
            break;
        case 5:
            goto exit;
            break;
        default:
            cout<<"\nEnter a valid choice";
            break;

        }

    }
}
else if(type == 'c' || type == 'C')
{
    c1.details();
    while(1)
    {
        cout<<"\nChoose your option";
        cout<<"\n1) Balance";
        cout<<"\n2) Withdraw";
        cout<<"\n3) Deposit";
        cout<<"\n4) Display details";
        cout<<"\n5) Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;

        switch(choice)
        {
        case 1:
            c1.c_display();
            break;
        case 2:
            c1.c_withdraw();
            break;
        case 3:
            c1.c_deposit();
            break;
        case 4:
            c1.display();
            c1.c_display();
            break;
        case 5:
            goto exit;
            break;
        default:
            cout<<"\nEnter a valid choice";
            break;
        }
    }
}
else{
    cout<<"\nEnter a valid account type";
}
exit:
    cout<<"\nThank you for using our service";
    return 0;
}
