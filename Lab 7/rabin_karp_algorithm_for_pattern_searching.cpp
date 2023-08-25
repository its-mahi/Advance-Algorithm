#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string t;
    cout << "Enter a numbers in which you want to find pattern : ";
    cin >> t;
    
    string p;
    cout << "Enter a pattern which you want to find in a main string : ";
    cin >> p;
    
    int q;
    cout << "Enter a value of q : ";
    cin >> q;
    
    int n = t.size();
    int m = p.size();
    
    int numt = 0;
    int nump = 0;
    
    for(int i=0 ; i<m ; i++) {
        numt = numt*10 + t[i]-'0';
        nump = nump*10 + p[i]-'0';
    }
    
    int mod_temp = pow(10, m-1);
    
    for(int i=0 ; i<n-m-1 ; i++) {
        if(numt%q == nump%q) {
            if(numt == nump) {
                cout << "Pattern is matched at : " << i << endl;
            }
        }
        
        numt = (numt % mod_temp)*10 + t[i+m]-'0';
    }

    return 0;
}
