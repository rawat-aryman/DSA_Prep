#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define eb              emplace_back
#define em              emplace
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
string str;
    cin >> str;  // take input string from user
    
    if (isdigit(str[str.length()-1])) {  // check if last character is a digit
        string length = to_string(str.length()).substr(str.length()-2);  // take last two characters of string length
        if (stoi(length) > 9) {  // check if length is more than 9
            cout << "-1" << endl;
        }
        else {
            cout << length << endl;
        }
    }
    else {  // if last character is a character
        string length = to_string(str.length());  // take length of string
        if (stoi(length) > 9) {  // check if length is more than 9
            cout << "-1" << endl;
        }
        else {
            cout << length << endl;
        }
    }
}

int32_t main()
{
    solve();
}

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string str;
//     cin >> str;  // take input string from user
    
//     if (isdigit(str[str.length()-1])) {  // check if last character is a digit
//         string length = to_string(str.length()).substr(str.length()-2);  // take last two characters of string length
//         if (stoi(length) > 9) {  // check if length is more than 9
//             cout << "-1" << endl;
//         }
//         else {
//             cout << length << endl;
//         }
//     }
//     else {  // if last character is a character
//         string length = to_string(str.length());  // take length of string
//         if (stoi(length) > 9) {  // check if length is more than 9
//             cout << "-1" << endl;
//         }
//         else {
//             cout << length << endl;
//         }
//     }
//     return 0;
// }
