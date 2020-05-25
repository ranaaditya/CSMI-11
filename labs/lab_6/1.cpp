/* 
*@author Aditya Rana 
*@url https://github.com/ranaaditya
*/

#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main() {
    ll first = 0, second = 1;   // let assume that first -> 0 and second is -> 1
    int n = 1;
    cout << "Enter the number for fibbonnacci series : ";
    cin >> n;

    ll *v = new ll[n];
    v[0] = 0;
    v[1] = 1;

    for(ll i = 2; i < n; i++) {
        v[i] = v[i-2] + v[i-1];
    }

cout << "------------------------GENERATING \t" << n <<"\tFIBONACCI NUMBERS -----------------------------------\n";
    for(ll i = 0; i < n; i++ ){
        cout << v[i] << "\n";
    }
    delete(v);
    return 0;
}