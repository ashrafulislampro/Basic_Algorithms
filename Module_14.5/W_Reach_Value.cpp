#include <bits/stdc++.h>
using namespace std;
bool isTrue;
long long input;
void rec(long long n)
{
    if (n == input)
    {
        isTrue = true;
        return;
    }
    if (n > input)
    {
        return;
    }

    rec(n * 10);
    rec(n * 20);
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> input;
        isTrue = false;
        if (input == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            rec(1);
            cout << (isTrue ? "YES" : "NO") << endl;
        }
    }
    return 0;
}