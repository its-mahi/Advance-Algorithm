#include <bits/stdc++.h>
using namespace std;

void string_matching(int state_transition_table[4][2], int n, int m, string t) {
    cout << "Pattern occurred at indexes: ";
    int q = 0;

    for (int i = 0; i < n; i++) {
        q = state_transition_table[q][t[i] - 'a'];

        if (q == m) {
            cout << i - m + 1 << " "; // Pattern found at this index
        }
    }
}

int main() {
    string s = "abaabbabbaabbb"; // The input text
    int n = s.size(); // Size of the input text
    string pattern = "aab"; // The pattern to search for
    int m = pattern.size(); // Size of the pattern

    int state_transition_table[4][2] = { 1, 0, // Finite automaton's state transition table
                                         2, 0,
                                         1, 3,
                                         1, 0 };

    string_matching(state_transition_table, n, m, s); // Call the pattern matching function

    return 0;
}
