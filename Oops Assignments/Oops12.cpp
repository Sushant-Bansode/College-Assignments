#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
    int data;
    node *next, *prev;
};
class cinema_hall
{
public:
    node *h[15][11];
    cinema_hall()
    {
        int i = 0;
        for (i = 0; i < 15; i++)
        {
            h[i][0] = new node;
            h[i][0]->data = i;
            h[i][0]->next = h[i][1];
            h[i][0]->prev = NULL;
        }
        for (i = 0; i < 15; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                h[i][j] = new node;
                h[i][j]->data = 0;
                if (j < 10)
                    h[i][j]->next = h[i][j + 1];
                else
                    h[i][j]->next = NULL;
                h[i][j]->prev = h[i][j - 1];
            }
        }
    }
    int check(int row, int seat)
    {
        return (h[row][seat]->data);
    }
    void book()
    {
        int row, seat, check_seat, ch;
    xyz:
        cout << "enter the row number (rows are from 0 to 14)" << endl;
        cin >> row;
        cout << "enter seat number(seat are from 1 to 10)" << endl;
        cin >> seat;
        check_seat = check(row, seat);
        if (check_seat == 0)
        {
            h[row][seat]->data = 1;
            cout << "succesfully booked" << endl;
            cout << "want to book more 1)yes" << endl;
            cin >> ch;
            if (ch == 1)
            {
                goto xyz;
            }
        }
        else
        {
            cout << "seat not available try different seat"
                 << endl;
            goto xyz;
        }
    }
    void cancel()
    {
        int row, seat, check_seat;
        cout << "enter the row number (rows are from 0 to 14)" << endl;
        cin >> row;
        cout << "enter seat number(seat are from 1 to 10)" << endl;
        cin >> seat;
        check_seat = check(row, seat);
        if (check_seat == 1)
        {
            h[row][seat]->data = 0;
            cout << "succesfully cancelled"
                 << endl;
        }
        else
        {
            cout << "seat not booked,cancelation is not possible"
                 << endl;
        }
    }
    void display()
    {
        cout << endl
             << "number 1=seat not available (already booked)" << endl
             << "       0=seat available" << endl
             << endl;
        cout << "        ";
        for (int j = 1; j < 11; j++)
        {
            cout << j << " ";
        }
        cout << endl;
        for (int i = 0; i < 15; i++)
        {
            cout << "row " << setw(2) << i << "|";
            for (int j = 1; j < 11; j++)
            {
                cout << " " << h[i][j]->data;
            }
            cout << endl;
        }
        cout << "         all eyes here" << endl;
        cout << "     -----------------------" << endl
             << "     |       PUSHPA        |" << endl
             << "     -----------------------" << endl
             << endl;
    }
};

int main()
{
    int i = 0, choice;
    cinema_hall p;
    while (1)
    {
        cout << endl;
        cout << "menu" << endl
             << "1)booking" << endl
             << "2)canceling" << endl
             << "3)display availability/occupancy" << endl
             << "4)exit" << endl
             << "enter the choice:";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            p.book();
            break;
        case 2:
            p.cancel();
            break;
        case 3:
            p.display();
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "wrong choice" << endl;
            break;
        }
    }
    return 0;
}