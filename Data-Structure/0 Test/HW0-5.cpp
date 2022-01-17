#include <iostream>
using namespace std;
 
int main()
{
    while (1)
    {
        long year;
        cin >> year;
        if (year == -1)
        {
            break;
        }
 
        long female = 1;
        long male = 0;
 
        for (int i = 0; i < year; i++)
        {
            long female_next = male + 1;
            long male_next = male + female;
            female = female_next;
            male = male_next;
        }
        cout << male << ' ' << female + male << endl;
    }
 
 
 
    return 0;
}