#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int is_palindrome(string str){
    int len = str.size();
    for(int i = 0, k = len -1; i < len && i <= k; i++, k--){
        if(str[i] != str[k]){
            return 0;
        }
    }
    return 1;
}
int main() {
    
    string str;
    cin>>str;
    if(is_palindrome(str) ==  1){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}