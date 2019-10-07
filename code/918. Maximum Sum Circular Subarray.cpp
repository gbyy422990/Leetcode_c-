//
// Created by bin gao on 2019-10-03.
//

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        const int n = A.size();
        //把数组A复制一份,把环型构造成一个2n大小的链
        for(int i = 0; i < n; i++) A.push_back(A[i]);

        //求前缀和
        vector<int> sum(2 * n + 1);
        for(int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + A[i - 1];

        deque<int> q;
        int res = INT_MIN;
        q.push_back(0);
        for(int i = 1; i <= 2 * n; i++){
            if(q.size() > 0 && i - n > q.front()) q.pop_front();
            if(q.size()) res = max(res, sum[i] - sum[q.front()]);
            while(q.size() > 0 && sum[q.back()] >= sum[i]) q.pop_back();
            q.push_back(i);
        }
        return res;
    }
};