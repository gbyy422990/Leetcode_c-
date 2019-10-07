//
// Created by bin gao on 2019-10-02.
//

class Solution {
public:
    int work(string s){
        int res = 0;
        for(int i = 0, start = 0, cnt = 0; i < s.size(); i++){
            if(s[i] == '(') cnt++;
            else{
                cnt--;
                if(cnt < 0){
                    start = i + 1;
                    cnt = 0;
                }
                else if(cnt == 0){
                    res = max(res, i - start + 1);
                }
            }
        }
        return res;
    }

    int longestValidParentheses(string s) {
        int res = work(s);
        reverse(s.begin(), s.end());

        //左括号数量大于右括号数量的话，就没办法让总和=0，也就无法匹配到合法的括号对，为了解决这个问题，可以
        //再从右往左再做一遍即可.
        for(auto &c: s) c ^= 1;
        return max(res, work(s));
    }
};