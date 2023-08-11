/**
 * @author : its_mahi
 * Code : Horsepools String Matching Algorithm
 * 
 * Desc : two string "text" and "pattern" are there. we have to find is there "pattern" exist in "text" string. it must be a continuous(substring). not subsequence.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string text;
    cout << "Enter your text : ";
    getline(cin, text, '\n');
    
    string pattern;
    cout << "Enter your pattern to find in text : ";
    getline(cin, pattern, '\n');
    
    int n = text.size();
    int m = pattern.size();
    
    map<char, int> shift_table;
    bool foo = false;
    
    // Creating Shift Table
    int k = m-1;
    for(int i=0 ; i<m-1 ; i++) {
        shift_table[pattern[i]] = k;
        k--;
    }
    
    for(int i=0 ; i<=n-m ; ) {
        int p = i+m-1;
        int q = m-1;
        
        while(q >= 0 && p >= 0 && pattern[q] == text[p]) {
            p--;
            q--;
        }
        
        if(q == -1) {
            cout << "Pattern matched at : " << i << endl;
            i++;
            foo = true;
        }
        else {
            if(shift_table[text[i+m-1]] > 0) {
                i += shift_table[text[i+m-1]];
            }
            else {
                i += m;
            }
        }
    }
    
    if(foo == false) {
        cout << "No match is present" << endl;
    }
    
    cout << "computation is done" << endl;
    
    return 0;
}
