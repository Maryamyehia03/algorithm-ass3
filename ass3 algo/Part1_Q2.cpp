#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
int TXT(const string& s) {
    int n = s.size();


    for (int i = 0; i < n; ++i) {
        if(s[i]=='w'||s[i]=='m')
            return 0;     //Can't send w or m
    }
    vector<int> dp(n+1 , 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] += dp[i - 1];

        // W
        if ( i>1 && s[i - 2] == 'u' && s[i - 1] == 'u') {
            dp[i] =(dp[i]+ dp[i - 2])% MOD;
        }

        // M
        if ( i>1 && s[i - 2] == 'n' && s[i - 1] == 'n') {
            dp[i] =(dp[i]+ dp[i - 2])% MOD;
        }
    }

    return dp[n];
}

int main() {
    string s;
    cin >> s;
    cout << TXT(s) << endl;
    return 0;
}
