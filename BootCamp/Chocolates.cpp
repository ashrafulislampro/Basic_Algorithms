#include <bits/stdc++.h>
using namespace std;

int get_chocolate(int wrappers) {
    if (wrappers < 3) return 0;  

    int new_chocolates = wrappers / 3;  
    int remaining_wrappers = wrappers % 3;  

    
    return new_chocolates + get_chocolate(new_chocolates + remaining_wrappers);
}

int main() {
    int T;
    cin >> T;  

    while (T--) {
        int N;
        cin >> N;  

        int chocolates = N / 5;  
        chocolates += get_chocolate(chocolates);  

        cout << chocolates << endl;
    }
    return 0;
}
