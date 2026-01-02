#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<unordered_map>

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if (hand.size()%groupSize!=0){
            return false;
        }
        if (groupSize==1){
            return true;
        }

        unordered_map<int,int> freq;
        for (int i : hand) {
            freq[i]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &it : freq) {
            pq.push(it.first);
        }

        while (!pq.empty()) {
            int start = pq.top();  

            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                if (freq[card] == 0){
                    return false;
                }

                freq[card]--;

                if (freq[card] == 0) {
                    if (card != pq.top()){
                        return false;
                    }
                    pq.pop();
                }
            }
        }

        return true;
    }
};
