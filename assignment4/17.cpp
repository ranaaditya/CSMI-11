#include<bits/stdc++.h>
using namespace std;

int main() {
    int n=1;
    list<int> l , r;
    map<int,int> mp;
    cout << "Enter number of elements in list" << endl;
    cin >> n;
    cout << "enter the numbers one by one :" << endl;

    for(int i=0; i<n; i++) {
    int x;
    cin >> x;

    if(mp.find(x) != mp.end()) r.push_back(x);
    else 
    {
    l.push_back(x);
    mp[x] = x;
    }
    }

cout << "Repeated elements in list are :";
    for(auto x : r) {
        cout << x <<"\t";
    }


    return 0;
}