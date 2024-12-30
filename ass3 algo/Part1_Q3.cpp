#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k, m; // max weight, # of bags
        cin >> k >> m;

        vector<pair<int, int>> bags(m); // each bag has {weight, value}
        for (int i = 0; i < m; i++) {
            cin >> bags[i].first >> bags[i].second;
        }

        // dp[i][w] i=# of items +1 , w= maxCapacity+1 
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= m; i++) { // i=0 no items are available
            int weight = bags[i - 1].first;
            int value = bags[i - 1].second;
            for (int w = 0; w <= k; w++) {
                if (w < weight) {
                    // If the current item's weight is more than the weight limit
                    //copy the value as the upper cell
                    dp[i][w] = dp[i - 1][w];
                } else {
                    // max(weight of the cell above me , the weight of current bag(value) + use the remaining weight to choose another one)
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight] + value);
                }
            }
        }

        // maximum value is in dp[m][k]
        int maxValue = dp[m][k];
        cout << "Hey stupid robber, you can get " << maxValue << "." << endl;
    }

    return 0;
}

//3
//34 5
//178 12
//30 1
//13 7
//34 8
//87 6
//900 1
//900 25
//100 10
//27 16
//131 9
//132 17
//6 5
//6 23
//56 21
//100 25
//1 25
//25 25
//100 2

