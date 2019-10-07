//
// Created by bin gao on 2019-10-03.
//

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(q.size() > 0 && i - k + 1 > q.front()) q.pop_front();
            while(q.size() > 0 && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if(i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};