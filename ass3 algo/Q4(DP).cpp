#include"iostream"
#include "vector"
#include "algorithm"
#include "math.h"
using namespace std;
void treaserHunter(int TotalAvaiableTime,int ConstantMultiplier,const vector<pair<int,int>>& treasure){
    int treaserSize = treasure.size();
    vector<int>dp(TotalAvaiableTime+1,0);

    vector<int>previous(TotalAvaiableTime+1,-1);
    for(int i=0;i<treaserSize;i++){
        int descentTime = treasure[i].first;

                int ascentTime = treasure[i].second;
                int timeNeeded = 3*ConstantMultiplier*descentTime;

                for(int j = TotalAvaiableTime;j>=timeNeeded;j--){
                    if(dp[j-timeNeeded] + ascentTime>dp[j]){
                        dp[j]=dp[j-timeNeeded]+ascentTime;
                        previous[j]=i;
                    }
                }
    }
    int MaxGold = dp[TotalAvaiableTime];

    vector<pair<int,int>>selected_treasure;
    int currentTime = TotalAvaiableTime;
    while (currentTime>0&&previous[currentTime]!=-1){
        int index = previous[currentTime];
        selected_treasure.push_back(treasure[index]);
        currentTime-=3*ConstantMultiplier*treasure[index].first;
    }
    reverse(selected_treasure.begin(),selected_treasure.end());
    cout<<MaxGold<<"\n";
cout<<selected_treasure.size()<<"\n";
for(const auto&t:selected_treasure){
    cout<<t.first<<" "<<t.second<<"\n";
}
cout<<"\n";
}





int main(){
    int t,w;
    while (cin >> t >> w) {
        if (!(1 <= t && t <= 1000 && 1 <= w && w <= 1000)) break;  // End of input

        int n;
        cin >> n;

        vector<pair<int, int>> treasures(n);

        for (int i = 0; i < n; i++) {
            cin >> treasures[i].first >> treasures[i].second;
        }

        // Solve the problem with dynamic programming

        treaserHunter(t, w, treasures);
    }

}