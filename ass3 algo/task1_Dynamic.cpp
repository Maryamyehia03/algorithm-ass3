#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimal difference
vector<int> minimal_difference(vector<vector<int>> &test_cases , int total_sum) {
    vector<int> results;

    for (auto &case_data : test_cases) {
        vector<int> &coins = case_data;

        std::sort(coins.begin(), coins.end());

        vector<bool> dp(total_sum / 2 + 1, false);

        dp[0] = true;

        //1 2 4 5

        for (int coin : coins) {
            for (int j = total_sum / 2; j >= coin; --j) {
                dp[j] = dp[j] || dp[j - coin];
            }
        }

        int max_sum = 0;
        for (int s = total_sum / 2; s >= 0; --s) {
            if (dp[s]) {
                max_sum = s;
                break;
            }
        }

        results.push_back(total_sum - 2 * max_sum);
    }

    return results;
}

int main() {
    int n , sum =0;
    cin >> n;

    vector<vector<int>> test_cases(n);
    for (int i = 0; i < n; ++i) {
        int m ;
        cin >> m;

        vector<int> coins(m);
        for (int j = 0; j < m; ++j) {
            cin >> coins[j];
        }
        test_cases[i] = coins;
        sum = 0 ;
    }
    vector<int> results = minimal_difference(test_cases , sum);

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}

//2
//3
//2 3 5
//4
//1 2 4 5