#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<unordered_map>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count frequency
        unordered_map<char,int> freq;
        for (char t : tasks){
            freq[t]++;
        }

        // Step 2: Max heap (frequencies)
        priority_queue<int> pq;
        for (auto &it : freq){
            pq.push(it.second);
        }

        // Step 3: Cooldown queue -> {remainingCount, availableTime}
        queue<pair<int,int>> cooldown;

        int time = 0;

        // Step 4: Process tasks
        while (!pq.empty() || !cooldown.empty()) {
            time++;

            // If a task finishes cooldown, move back to heap
            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            // Execute highest frequency task
            if (!pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                cnt--;

                // If task still has remaining executions
                if (cnt > 0) {
                    cooldown.push({cnt, time + n + 1}); 
                }
            }
        }

        return time;
    }
};
