/**
 * @author : its-mahi
*/

//Finding Probabilty of Wrong ans.
#include <bits/stdc++.h>
using namespace std;

int f_liars = 0;
unsigned long long Power(unsigned long long a, unsigned long long n, unsigned long long p) {
    unsigned long long res = 1;
    
    a = a%p;
    
    while(n > 0) {
        if(n & 1) res = (res * a) % p; //If n is Odd, then multiply a.
        
        n = n >> 1; // n /= 2.
        a = (a * a) % p;
    }
    return res;
}

void count_fliars(int n) {
    for(int a = 2; a <= n-2; a++) {
        if(Power(a, n-1, n) == 1) f_liars++;
    }
}

int main() {
    int n;
    cout << "Enter a value of n to check whether it is Prime or not:\n";
    cin >> n;
    
    count_fliars(n);
    cout << "Probability of wrong answer is : " << f_liars/(double) (n-3); 
    
    return 0;
}
