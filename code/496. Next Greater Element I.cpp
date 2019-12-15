//
// Created by bin gao on 2019-11-27.
//

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> hash;

        for(int i = nums2.size() - 1; i >=0; i--){

            while(stk.size() && stk.top() <= nums2[i]) stk.pop();
            hash[nums2[i]] = stk.size() ? stk.top(): -1;
            stk.push(nums2[i]);
        }
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++){
            res.push_back(hash[nums1[i]]);
        }
        return res;
    }
};