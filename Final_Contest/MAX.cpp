#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, id, num;
    cin>>q;
    map<int, int> mp;

    while(q--){
        cin>>id;
        if(id == 1){
            cin>>num;
            mp[num]++;
        }
        
    }
    return 0;
}