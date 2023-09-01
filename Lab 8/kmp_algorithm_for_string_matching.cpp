/**
 * @author : its_mahi
 * Code : KMP String Matching Algorithm (Knuth-Morris-Pratt Algorithm)
 * 
 * Desc : two string "text" and "pattern" are there. we have to find, is there "pattern" exist in "text" string. it must be a continuous(substring). not subsequence.
 * there is a concept of pie table. to optimise from brute force.
*/


#include <bits/stdc++.h>
using namespace std;

void create_pie_table(string pat, vector<int> &pie) {
    int k=0;
    pie[1] = 0;
    int count = 0;
    int m = pat.size();
    
    for(int q=2 ; q<m ; q++) {
        bool t = pat[k+1] != pat[q];
        count++;
        
        while(k>0 && t) {
            k = pie[k];
            t = pat[k+1] != pat[q];
            count++;
        }
        
        if(!t) {
            k++;
        }
        
        pie[q] = k;
    }
}

int main() {
    
    string text;
    cin >> text;
    int n = text.size();
    
    string pat;
    cin >> pat;
    int m = pat.size();
    
    pat = "0" + pat;
    
    vector<int> pie(m+1, -1);
    
    create_pie_table(pat, pie);
    
    int q = 0; //no. of matched char.
    
    for(int i=0 ; i<n ; i++) {
        while(q>0 && pat[q+1] != text[i]) {
            q = pie[q];
        }
        if(pat[q+1] == text[i]) {
            q++;
        }
        if(q == m) {
            cout << "Patter occurs at " << i-m+1 << " index" << endl;
            q = pie[q];
        }
    }
    
    cout << "execution end" << endl;

    return 0;
}
