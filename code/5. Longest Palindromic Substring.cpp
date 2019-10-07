//
// Created by bin gao on 2019-10-04.
//

class Solution {
public:
    string longestPalindrome(string s) {
        //暴力做
        string res;
        for(int i = 0; i < s.size(); i++){
            for(int m = i, n = i; m >= 0 && n < s.size() && s[m] == s[n]; m--, n++){
                if (n - m + 1 > res.size()) res = s.substr(m, n - m + 1);
            }
        }

        for(int i = 0; i < s.size(); i++){
            for(int m = i, n = i + 1; m >= 0 && n < s.size() && s[m] == s[n]; m--, n++){
                if (n - m + 1 > res.size()) res = s.substr(m, n - m + 1);
            }
        }
        return res;
    }
};