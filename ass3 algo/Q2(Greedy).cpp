#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> task_count;
int frequency=0,ans=0;
for(auto task:tasks){
    frequency= max(frequency,++task_count[task]);

}
for(auto countTask : task_count){
    if(countTask.second==frequency){
        ans++;
    }
}
return max((int)tasks.size(),ans+(frequency-1)*(n+1));

}

int main() {
    vector<vector<char>> examples = {
            {'A', 'A', 'A', 'B', 'B', 'B'},
            {'A', 'C', 'A', 'B', 'D', 'B'},
            {'A', 'A', 'A', 'B', 'B', 'B'}
    };
    vector<int> cooldowns = {2, 1, 3};

    for (size_t i = 0; i < examples.size(); ++i) {
        int result = leastInterval(examples[i], cooldowns[i]);
        cout << "Example " << i + 1 << ": Minimum intervals required: " << result << endl;
    }

}
