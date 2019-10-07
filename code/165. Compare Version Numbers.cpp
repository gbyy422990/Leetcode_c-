//
// Created by bin gao on 2019-10-04.
//

class Solution {
public:
    int compareVersion(string version1, string version2) {

        //定义两个指针位置i和j分别指向两个string的0位置
        int i = 0, j = 0;
        while(i < version1.size() || j < version2.size()){
            int x = i, y = j;
            //计算version1字符串里面从0位置开始往后的第一个.出现的位置
            while(x < version1.size() && version1[x] != '.') x++;

            //计算version2字符串里面从0位置开始往后的第一个.出现的位置
            while(y < version2.size() && version2[y] != '.') y++;

            //判断一下i和x，以及j和y是否相等，相等即说明到了最后位置，那么此时再往后面的都是0，所以当i==x时，a = 0.
            //注意有些容易漏掉的细节，例如当一个字符串结束了，但另一个字符串没有结束，那么结束了的字符串之后的数字就一直是0。
            int a = i == x? 0: atoi(version1.substr(i, x - i).c_str());
            int b = j == y? 0: atoi(version2.substr(j, y - j).c_str());

            if(a > b) return 1;
            else if(a < b) return -1;

            i = x + 1, j = y + 1;
        }
        return 0;
    }
};