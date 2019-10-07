//
// Created by bin gao on 2019-10-02.
//

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        for(auto c: t) hash[c]++;
        int cnt = hash.size();

        //hash存的是现在找到的字符串还缺的元素，hash[s[i]] == 1表示，现在还缺一个s[i]没找到。
        string res;
        for(int i = 0, j = 0, c = 0; i < s.size(); i++){
            if(hash[s[i]] == 1) c++;
            hash[s[i]]--;
            while(hash[s[j]] < 0){
                hash[s[j]]++;
                j++;
            }
            if(c == cnt){
                if(res.empty() || res.size() > i - j + 1) res = s.substr(j, i-j+1);
            }
        }
        return res;
    }
};