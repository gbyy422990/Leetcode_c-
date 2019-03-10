/* 使用一个HashMap，来建立数字和其坐标位置之间的映射，我们都知道HashMap是常数级的查找效率，这样，我们在遍历数组的时候，
用target减去遍历到的数字，就是另一个需要的数字了  */
# 方法一
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        # 定义一个哈希表
        unordered_map<int, int> indies;
        # 遍历一下整个数组，然后存到哈希表里，哈希表的key为nums， value为其索引
        for (int i=0;i<nums.size();i++){
            indies[nums[i]] = i;
        }
        for (int i=0;i<nums.size();i++){
            int res = target - nums[i];
            # 判断一下res是否存在在哈希表里面 and 这个res在indies里面不存在
            if (indies.count(res) && indies[res] != i){
                # 返回其索引
                return {i, indies[res]};
            }
        }
        return {};
    }
};


# 方法二
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1, n = s.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.count(s[i]) && m[s[i]] > left) {
                left = m[s[i]];  
            }
            m[s[i]] = i;
            res = max(res, i - left);            
        }
        return res;
    }
};
