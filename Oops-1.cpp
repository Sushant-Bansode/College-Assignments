#include <iostream>
#include <string.h>
using namespace std;
class Bank_details
{
private:
string name;
long int account_no;
string acc_type;
float balance;
public:
void display();
void deposit();
void withdraw();
void input();
Bank_details(){
cout << "\nEnter the following details:\n";
cout << "Enter name: ";
cin >> name;
cout << "\nEnter Account Number: ";
cin >> account_no;
cout << "\nAccount Type: ";
cin >> acc_type;
cout << "\nEnter Balance: ";
cin >> balance;
}
};


void Bank_details :: deposit(){
float amt;
cout << "\nEnter amount to Deposit: ";
cin >> amt;
balance = balance + amt;
cout << "\nYour Balance is: " << balance;
}


void Bank_details :: withdraw(){
float amt;
cout << "\nEnter amount to withdraw: ";
cin >> amt;
if(balance>=amt)
{
balance = balance - amt;
cout << "\nYour balance is: " << balance;
}
else
{
cout << "\nYour Balance is Insufficient!!!";
}
}


void Bank_details :: display(){
cout << "\nName: " << name;
cout << "\nAccount Number: " << account_no;
cout << "\nAccount type: " << acc_type;
cout << "\nYour balance is: " << balance;
}


void Bank_details :: input(){
int choice, flag=1;
while (flag==1)
{
cout << "\n\nEnter choice here from above reference:\n";
cout << "1. Deposit\n";
cout << "2. Withdraw\n";
cout << "3. Display\n";
cout << "4. Exit\n";
cout << "\nEnter your choice here: ";
cin >> choice;
switch (choice)
{
case 1:
deposit();
break;
case 2:
withdraw();
break;
case 3:
display();
break;
case 4:
cout << "\nThank You!!!";
flag = 0;
break;
default:
cout << "\nInvalid Input!!!";
}
}
}


int main()
{
int no;
cout << "\nEnter no of account holders: ";
cin >> no;
Bank_details a[no];
int i;
cout << "\nFor which person do you want to perform operation? ";
cin>>i;
a[i-1].input( );
}
