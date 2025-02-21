#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str;
    while (getline(cin, str))
    {
        stringstream strem(str);
        string word;
        string result = "";
        while (strem >> word)
        {
            result += word;
        }
        sort(result.begin(), result.end());
        cout << result << endl;
    }
    return 0;
}