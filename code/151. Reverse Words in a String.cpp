//
// Created by bin gao on 2019-10-03.
//

class Solution {
public:
    string reverseWords(string s) {
        //先反转每个单词，再反转整个string

        //当前实际存的位置的终点在说明地方
        int k = 0;
        for(int i = 0; i < s.size(); i++){

            //把连续的空格过滤掉。
            while(i<s.size() && s[i] == ' ') i++;

            if(i == s.size()) break;
            //此时i已经是不为空格的位置了，下面找到连续一段不为0的空格
            int j=i;
            while(j<s.size() && s[j] != ' ') j++;
            //反转字符串里面的单个单词
            reverse(s.begin() + i, s.begin() + j);
            //
            if (k != 0) s[k++] = ' ';
            while(i < j) s[k++] = s[i++];
        }
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};