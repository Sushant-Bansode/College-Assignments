# include <iostream>
# include <string>
using namespace std;
static int no;
class Student_Database
{
private:
string name[10];
int roll_no[10];
int std[10];
string division[10];
int day_dob[10];
int month_dob[10];
int year_dob[10];
string blood_grp;
int blood_sign[10];
char add[100][10];
long int tele_no[10];
public:
Student_Database()
{
cout << "***Student Data***" << endl << endl;
cout << "OPTIONS:" << endl << endl;
cout << "1. Input Data" << endl;
cout << "2. Display Data" << endl;
cout << "3. Exit" << endl << endl;
cout << "**********************************************" << endl;
}
void input();
void inline display();
~Student_Database()
{
cout << "**********************************************" << endl;
cout << "Destructor Invoked!" << endl;
}
};
int main()
{
int choice;
Student_Database a;
while(choice!=3)
{
cout << "Enter your choice here: ";
cin >> choice;
cout << endl;
switch (choice)
{
case 1:
a.input();
break;
case 2:
a.display();
break;
case 3:
cout << "Thank You!!! :)" << endl;
cout << endl << endl;
break;
default:
cout << "Invalid Input!!! :(" << endl;
}
}
return 0;
}
void Student_Database :: input()
{
cout << "Enter number of students: ";
cin >> no;
cout << endl;
for(int i=0; i<no; i++)
{
cout << "Enter details for student " << i+1 << " :" << endl << endl;
cout << "Enter your name: ";
cin >> name[i];
cout << endl;
cout << "Enter your Roll No: ";
cin >> roll_no[i];
cout << endl;
cout << "Enter your Class: ";
cin >> std[i];
cout << endl;
cout << "Enter your Division: ";
cin >> division[i];
cout << endl;
cout << "Enter your Day of DOB: ";
cin >> day_dob[i];
cout << endl;
cout << "Enter your Month of DOB: ";
cin >> month_dob[i];
cout << endl;
cout << "Enter your Year of DOB: ";
cin >> year_dob[i];
cout << endl;
cout << "Enter your Blood Group(Without sign): ";
cin >> blood_grp[i];
cout << endl;
cout << "Enter your sign of Blood Group:(0 >> -ve & 1 >> +ve) ";
cin >> blood_sign[i];
cout << endl;
cout << "Enter your Address: ";
cin >> add[i];
cout << endl;
cout << "Enter your Telephone/Mobile Number: ";
cin >> tele_no[i];
cout << endl;
}
}
void Student_Database :: display()
{
cout << endl << endl;
cout << "**********************************************" << endl;
for(int i=0; i<no; i++)
{
cout << "Info of student " << i+1 << " : "<< endl << endl;
cout << "Your name: " << name[i] << endl;
cout << "Your Roll Number: " << roll_no[i] << endl;
cout << "Your Class: " << std[i] << endl;
cout << "Your Division: " << division[i] << endl;
cout << "Your DOB: " << day_dob[i] << " / " << month_dob[i] << " / " <<
year_dob[i] << endl;
cout << "Your Blood Group: " << blood_grp[i];
if(blood_sign[i]==1)
{
cout << "+" << endl;
}
else
{
cout << "-" << endl;
}
cout << "Your Address: " << add[i] << endl;
cout << "Your Number: " << tele_no[i] << endl;
cout << endl << endl;
}
}
