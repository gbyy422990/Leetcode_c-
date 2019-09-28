class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0, left=-1, n=s.size();
        unordered_map<int, int> m;
        for (int i=0; i<n; ++i){
            if (m.count(s[i]) && m[s[i]]>left){
                left=m[s[i]];
            }
            m[s[i]]=i;
            res=max(res, i-left);
        }
        return res;
    }
};
