#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    stringstream strem(str);
    string word;
    string result = "";

    while (strem >> word)
    {
        reverse(word.begin(), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (!result.empty())
        {
            result += " ";
        }
        result += word;
    }

    cout << result << endl;
    return 0;
}