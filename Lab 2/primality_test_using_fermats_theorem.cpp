/**
 * @author : its-mahi
*/

//Primality Test using Fermat's theorem.
#include <bits/stdc++.h>
using namespace std;

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

bool isPrime(int n) {
    if(n <= 1 || n == 4) return false; //Special case of 4 which gives false ouput
    
    if(n <= 3) return true;
    //Iterating K times. Here, K is parameter. Taking K = 100.
    int k = 10;
    
    srand(time(NULL)); // To generate new Random no everytime.
    while(k > 0) {
        int a = 2 + rand() % (n-3); // To generate range 2 <= a <= (n-2).
        if(__gcd(n, a) != 1) return false; //Composite no.
        
        if(Power(a, n-1, n) != 1) return false;
        
        k--;
    }
    return true; //if n passes all K iterations, it is Prime no.
}

int main() {
    int n;
    cout << "Enter a value of n to check whether it is Prime or not:\n";
    cin >> n;
    
    if(isPrime(n)) {
        cout << n << " is Prime no.";
    } else {
        cout << n << " is NOT Prime no.";
    }
    return 0;
}
