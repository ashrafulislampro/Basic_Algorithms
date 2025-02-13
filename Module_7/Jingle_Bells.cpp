#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n, temp, count = 0, len, ele = 1;
    cin >> n;
    temp = n;
    while (temp > 1)
    {
        temp -= 2;
        count++;
    }
    len = 6 + count;
    for (int i = 1; i <= len; i++)
    {
        for (int k = len - i; k >= 1; k--)
        {
            cout << " ";
        }
        for (int j = 1; j <= ele; j++)
        {
            cout << '*';
        }
        ele += 2;
        cout << endl;
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int k = 5; k >= 1; k--)
        {
            cout << " ";
        }
        for (int j = 1; j <= n; j++)
        {
            cout << '*';
        }
        
        cout << endl;
    }
    
    
    return 0;
}
