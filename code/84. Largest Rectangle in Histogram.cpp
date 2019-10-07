//
// Created by bin gao on 2019-10-02.
//

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        int res = 0;
        const int n = heights.size();
        vector<int> right(n), left(n);
        stack<int> stk;

        for(int i = 0; i < n; i++){
            while(stk.size() > 0 && heights[stk.top()] >= heights[i]) stk.pop();
            if(stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }

        while(stk.size()) stk.pop();
        for(int i = n - 1; i >= 0; i--){
            while(stk.size() > 0 && heights[stk.top()] >= heights[i]) stk.pop();
            if(stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }
        for(int i = 0; i < n; i++){
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};