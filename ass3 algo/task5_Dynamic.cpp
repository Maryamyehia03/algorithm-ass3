#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int n, vector<int>& a) {
    // Initialize dp array with 1
    vector<int> dp(n, 1);

    // Fill the dp array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum value in dp array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << longestIncreasingSubsequence(n, a) << endl;

    return 0;
}
