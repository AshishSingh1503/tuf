#include<iostream>
using namespace std;
#include<queue>

class MedianFinder {
public:
    priority_queue<int> small; 
    priority_queue<int, vector<int>, greater<int>> large; 

    MedianFinder() {
        
    }
    
    void addNum(int num) {
    
        small.push(num);

        if (!large.empty() && small.top() > large.top()) {
            int n = small.top();
            large.push(n);
            small.pop();
        }

        if (small.size() > large.size() + 1) {
            int n = small.top();
            large.push(n);
            small.pop();
        }
        else if (large.size() > small.size()) {
            int n = large.top();
            small.push(n);
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() == large.size()) {
            return (small.top() + large.top()) / 2.0;  
        }
        return small.top(); 
    }
};
