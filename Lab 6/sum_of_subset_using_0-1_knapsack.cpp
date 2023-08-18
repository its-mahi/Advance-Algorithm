/**
 * @author : its_mahi
 * Code : Sub of Subset using 0/1 Knapsack. Decision Problem
 * 
 * Desc : Implementing Sum of Subset Problem using 0/1 Knapsack problem. here this is only decision problem which will give only true or false.
*/

#include <bits/stdc++.h>
using namespace std;

bool knapsack(vector<int> p, vector<int> w, int cap, int max_profit) {
    int n = p.size();
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=cap ; j++) {
            if(j<w[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], p[i]+dp[i-1][j-w[i]]);
            }
        }
    }
    
    if(dp[n][cap] >= max_profit) { // dp[n][cap] will never be greater than max_profit because cap is same as max_profit
        return true;
    }
    else {
        return false;
    }
}

void sum_of_subset(vector<int> arr, int sum) {
    if(knapsack(arr, arr, sum, sum) == true) {
        cout << "Subset is present in arr with sum : " << sum << endl;
    }
    else {
        cout << "Subset is not present in arr with sum : " << sum << endl;
    }
}

int main() {
    
    int n;
    cout << "Number of element present in array : ";
    cin >> n;
    
    
    cout << "Enter all element : ";
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++) {
        cin >> arr[i];
    }
    
    int sum;
    cout << "Required sum : ";
    cin >> sum;
    
    sum_of_subset(arr, sum);
    
    return 0;
}
