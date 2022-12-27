#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    map<string, int> Person;
    int choice, t;
    char name[20];
    while (1)
    {
        cout << "\nMENU" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Name: ";
            cin >> name;
            cout << "Telephone no.: ";
            cin >> t;
            Person.insert(std::pair<string, int>(name, t));
            break;
        }
        case 2:
        {
            cout << "Enter name: ";
            cin >> name;
            std::map<string, int>::iterator it = Person.find(name);
            if (it != Person.end())
                std::cout << "Telephone no.: " << Person.find(name)->second << '\n';
            break;
        }
        case 3:
        {
            for (map<string, int>::iterator it = Person.begin(); it != Person.end(); ++it)
                cout << (*it).first << "  " << (*it).second << endl;
            break;
        }
        case 4:
        {
            cout << "Enter name: ";
            cin >> name;
            map<std::string, int>::iterator it = Person.find(name);
            Person.erase(it);
            break;
        }
        case 5:
            return 0;
        default:
            cout << "Wrong input\n";
        }
    }
    return 0;
}