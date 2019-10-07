//
// Created by bin gao on 2019-10-03.
//


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        /* //直观方法，复杂度O(n^2)
        const int n = height.size();
        vector<int> left_max(n), right_max(n);

        left_max[0] = height[0];
        for(int i = 1; i < n; i++){
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        right_max[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            res += min(left_max[i], right_max[i]) - height[i];
        }
        return res;
        */

        //单调递增栈，时间复杂度O(n^2)
        stack<int> stk;
        int res = 0;
        for(int i = 0; i < height.size(); i++){
            int last = 0;
            while(stk.size() > 0 && height[stk.top()] <= height[i]){
                int t = stk.top();
                stk.pop();
                res += (i - t - 1) * (height[t] - last);
                last = height[t];
            }
            if(stk.size()) res += (i - stk.top() - 1) * (height[i] - last);
            stk.push(i);
        }
        return res;
    }
};