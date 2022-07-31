#include<bits\stdc++.h>
#include<conio.h>
using namespace std;

class ATM
{
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;
public:
    void setData(long int _account_No, string _name, int _PIN, double _balance, string _mobile_No)
    {
        account_No = _account_No;
        name = _name;
        PIN = _PIN;
        balance = _balance;
        mobile_No = _mobile_No;
    }
    long int getAccountNo()
    {
        return account_No;
    }
    string getName()
    {
        return name;
    }
    int getPIN()
    {
        return PIN;
    }
    double getBalance()
    {
        return balance;
    }
    string getMobileNo()
    {
        return mobile_No;
    }
    void setMobileNo(string oldNumber, string newNumber)
    {
        if(oldNumber== mobile_No) {
            mobile_No = newNumber;
            cout << "Successfully updated Mobile number\n";
        }
        else
        {
            cout << "Incorrect!!! Old mobile number\n";
        }
        _getch(); //getch is to hold the screen(untill user press any key)

    }
    void cashWithDraw(int amount_a)
    {
        if(amount_a > 0 and amount_a < balance)
        {
            balance -= amount_a;
            cout << "Please collect your cash\n";
            cout << "Available Balance is : " << balance << endl;
        }
        else
        {
            cout << "Invalid input or Insufficient Balance\n";
        }
        _getch();
    }
    void getUserDetails()
    {
        cout << "Name       : " << name << endl;
        cout << "Account No : " << account_No << endl;
        cout << "Balance    : " << balance << endl;
        cout << "Mobile No  : " << mobile_No << endl;
    }
};

int main() {
    int choice = 0, enterPIN = 0;
    long int enterAccountNo = 0;

    system("cls"); // for screen clean while going one menu to another

    ATM user1;

    user1.setData(123456789, "Sakib", 12345, 60500.50, "01860607460");

    do
    {
        system("cls");
        cout << "\n___WELCOME TO BMW ATM___\n";
        cout << "\nEnter Your Account Number\n";
        cin >> enterAccountNo;
        cout << "\nEnter the PIN\n";
        cin >> enterPIN;

        if(enterAccountNo == user1.getAccountNo() and enterPIN == user1.getPIN())
        {
            do
            {
                system("cls");
                int amount = 0;
                string oldNo, newNo;
                cout << "\nMenu\n";
                cout << "\nSelect Options\n";
                cout << "\n1. Check Balance\n";
                cout << "\n2. Cash Withdraw\n";
                cout << "\n3. Show User Details\n";
                cout << "\n4. Update Mobile Number\n";
                cout << "\n5. Exit\n";

                cin >> choice;

                switch(choice)
                {
                    case 1:
                        cout << "Your Bank Balance is : " << user1.getBalance();
                        _getch();
                        break;
                    case 2:
                        cout << "\nEnter the amount\n";
                        cin >> amount;
                        user1.cashWithDraw(amount);
                        _getch();
                        break;
                    case 3:
                        user1.getUserDetails();
                        _getch();
                        break;
                    case 4:
                        cout << "Enter Old Mobile Number : ";
                        cin >> oldNo;
                        cout << "Enter New Mobile Number : ";
                        cin >> newNo;
                        user1.setMobileNo(oldNo, newNo);
                        _getch();
                        break;
                    case 5:
                        exit(0);
                    default:
                        cout << "Please Enter Valid Data!!!\n";
                }

            }while(1);
        }
        else {
            cout << "\nInvalid Account No or PIN\n";
            _getch();
        }
    }
    while(1);
}
