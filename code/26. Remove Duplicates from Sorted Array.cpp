//
// Created by bin gao on 2019-10-01.
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]) nums[j++] = nums[i];
        }
        return j;
    }
};