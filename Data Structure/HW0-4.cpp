//2021/9/14
 
#include <iostream>
using namespace std;
 
int main()
{
    int sum;
    char str[1000] = { 0 };
    while (gets(str) != NULL)
    {
        sum = 0;
        if (str[0] == '#')
        {
            break;
        }
        for (int i = 0;str[i]!=0; i++)
        {
            if (str[i] == ' ')
            {
                continue;
            }
            sum += (i + 1) * (str[i] + 1 - 'A');
        }
        cout << sum << endl;
    }
    return 0;
}