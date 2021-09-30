#include <iostream>

using namespace std;

class account
{
protected:
    string name;
    long ac_no;
    long balance;
    long deposite;
    long withdrawl;
    string check_book;
public:
    string account_type;
    void get()
    {
        cout<<"Enter costumers name(without surname)-";
        cin>>name;
        ac_no=17292248;
        cout<<"Welcome Mr. "<<name<<" in \"Rajesh corporation bank\"\n";
        cout<<"Your Account No. is-"<<ac_no<<"\n";
        cout<<"Plaese Maintain 500$ Balance your account-:";

    }
    void bal()
    {
        cout<<"\nyour current balance is-"<<balance<<"$";
    }

    void sete()
    {
        balance=500;
        deposite=0;
        withdrawl=0;
        if(account_type=="current"||account_type=="fd"||account_type=="FD")
                check_book="available";
        if(account_type=="saving")
                check_book="not available";
    }
    void ca()
    {
        cout<<"check book availability-"<<check_book;
    }
};
class s_ac : public account
{

public:
     void with()
    {
        cout<<"Enter amount to withdraw-";
        cin>>withdrawl;
        if(balance>=withdrawl)
        {
        cout<<"Transaction successful-:";
        balance-=withdrawl;
        }
        else
            cout<<"you have insufficient balance-:";

    }
     void dep()
    {
        cout<<"Enter amount to deposit-";
        cin>>deposite;
        cout<<"Transaction successful-:";
        balance+=deposite;
    }
    void status()
    {
        cout<<"#Name- "<<name<<endl;
        cout<<"#Account no.- "<<ac_no<<endl;
        cout<<"#Account type- "<<account_type<<endl;
        cout<<"#Check book availability- "<<check_book<<endl;
        cout<<"#Last deposit- "<<deposite<<endl;
        cout<<"#Last withdrawal- "<<withdrawl<<endl;
        cout<<"#Current balance- "<<balance<<"$";
    }
};
class c_ac : public account
{
    long pen;
public:
     void with()
    {
        cout<<"Enter amount to withdraw-";
        cin>>withdrawl;
        cout<<"Transaction successful-:";
        balance-=withdrawl;
    }
     void dep()
    {
        cout<<"Enter amount to deposit-";
        cin>>deposite;
        cout<<"Transaction successful-:";
        balance+=deposite;
    }
    void penalty()
    {
        if(balance<500)
        {
            pen=100;
            balance-=pen;
            cout<<"\n100$ penalty is been deducted from your \naccount due to minimum account maintain-ens";
        }
    }
     void status()
    {
        cout<<"#Name- "<<name<<endl;
        cout<<"#Account no.- "<<ac_no<<endl;
        cout<<"#Account type- "<<account_type<<endl;
        cout<<"#Check book availability- "<<check_book<<endl;
        cout<<"#Last deposit- "<<deposite<<endl;
        cout<<"#Last withdrawal- "<<withdrawl<<endl;
        cout<<"#Current balance- "<<balance<<"$";
    }

};
class fix : public account
{
protected:
    int period;
    float rate;
    long amount_after;
    float intr;
public:
    void total()
    {
        intr=(float)period*rate*(float)balance;
        intr/=100;
        amount_after+=intr;
    }
    void getm()
    {
        cout<<"enter the amount-";
        cin>>deposite;
        balance=deposite;
    }
    void disp()
    {
        cout<<"Entered amount="<<deposite<<endl;
        cout<<"Rate="<<rate<<endl;
        cout<<"Period-"<<period<<endl;
        cout<<"amount after maturity is="<<amount_after;
    }
};
class shot : public fix
{
public:
    void clac()
    {
        amount_after=deposite;
        rate=6;
        period=1;
        total();
    }
};
class mid : public fix
{
public:
    void clac()
    {
        amount_after=deposite;
        rate=8;
        period=3;
        total();
    }
};
class lon : public fix
{
public:
    void clac()
    {
        amount_after=deposite;
        rate=10;
        period=5;
        total();
    }
};
void shape()
{
    cout<<endl;
    for(int i=0;i<51;i++)
        cout<<"*";
    cout<<endl;
}
int main()
{
    int x;
    string t;
    shape();
    cout<<":-This is a program to open an bank account-:\n";
    cout<<"\t\t  Or\n\t :-to do a fix deposit-:";
    shape();
    cout<<"    $Enter a type of account to open$\n\n";
    cout<<"\t||saving||current||FD||\n\nEnter your choice-";
    cin>>t;

    if(t=="saving")
    {
        shape();
        s_ac s;
        s.account_type=t;
        s.get();
        s.sete();
        do
        {
            shape();
            cout<<"01-status\n";
            cout<<"02-balance\n";
            cout<<"03-withdraw\n";
            cout<<"04-deposit\n";
            cout<<"05-check book availability\n";
            cout<<"00-quit";
            cout<<"\nEnter your choice-";
            cin>>x;
            shape();
            switch(x)
            {
            case 01:s.status();break;
            case 02:s.bal();break;
            case 03:s.with();s.bal();break;
            case 04:s.dep();s.bal();break;
            case 05:s.ca();break;
            case 00:break;
            default:cout<<"Enter appropriate no.-:";

            }

        }
        while(x!=00);

    }
     else if(t=="current")
    {
        shape();
        c_ac c;
        c.account_type=t;
        c.get();
        c.sete();
        do
        {
            shape();
            cout<<"01-status\n";
            cout<<"02-balance\n";
            cout<<"03-withdraw\n";
            cout<<"04-deposit\n";
            cout<<"05-check book availability\n";
            cout<<"00-quit";
            cout<<"\nEnter your choice-";
            cin>>x;
            shape();
            switch(x)
            {
            case 01:c.status();break;
            case 02:c.bal(); break;
            case 03:c.with();c.penalty();break;
            case 04:c.dep();break;
            case 05:c.ca();break;
            case 00:break;
            default:cout<<"Enter appropriate no.-:";

            }

        }while(x!=00);

    }
    else if(t=="fd"||t=="FD")
    {
        shape();
        int a;
        cout<<"01- short-term fd (interest rate-06%, period-1 year)\n";
        cout<<"02- mid-term   fd (interest rate-08%, period-3 years)\n";
        cout<<"03- long-term  fd (interest rate-10%, period-5 years)";shape();
        cout<<"Enter your choice no-";
        cin>>a;
        if(a==01)
        {
            shape();
            shot s;
            s.get();
            s.sete();
            shape();
            s.getm();
            s.clac();
            shape();
            s.disp();
        }
        else if(a==02)
        {
            shape();
            mid s;
            s.get();
            s.sete();
            shape();
            s.getm();
            s.clac();
            shape();
            s.disp();
        }
        else if(a==03)
        {
            shape();
            lon s;
            s.get();
            s.sete();
            shape();
            s.getm();
            s.clac();
            shape();
            s.disp();
        }
        else
        cout<<"enter appropriate choice-:";

    }
    else
        cout<<"enter appropriate choice-:";

    shape();
    return 0;
}
