//Paste your code here
//NOTE: If you use java, your Main class must be named solution
//2021/9/7 
 
#include <iostream>
using namespace std;
 
int main()
{
    double money[12];
    double sum = 0;
    for (int i = 0; i < 12; i++)
    {
        cin >> money[i];
        sum += money[i];
    }
    cout << "¥" <<sum / 12 << endl;
    return 0;
}