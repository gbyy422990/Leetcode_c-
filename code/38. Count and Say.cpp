//
// Created by bin gao on 2019-10-03.
//

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 0; i < n - 1; i++){
            string ns;
            for(int j = 0, k = 0; j < s.size();){
                while(s[k] == s[j] && k < s.size()) k++;
                ns += to_string(k - j) + s[j];
                j = k;
            }

            s = ns;
        }
        return s;
    }
};