//
// Created by bin gao on 2019-10-01.
//

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int j = 0, i = numbers.size() - 1; j < numbers.size(); j++){
            while(i - 1 > j && numbers[i - 1] + numbers[j] >= target) i--;
            if(numbers[i] + numbers[j] == target) return {j+1, i+1};
        }
        return {-1, -1};
    }
};