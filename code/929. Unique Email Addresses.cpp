//
// Created by bin gao on 2019-10-04.
//

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        //给点的邮箱地址，拆成两部分（用户名和域名），再把新的用户名和域名拼在一起，剩下的就是判断有多少个新的email
        //开一个hash表，hash自带去重
        unordered_set<string> hash;
        for(int i = 0; i < emails.size(); i++){
            //找到@的位置
            int at = emails[i].find('@');
            string name;
            //遍历一遍@前的元素
            for(auto c: emails[i].substr(0, at)){
                if(c == '+') break;
                else if(c != '.') name += c;
            }
            string domain = emails[i].substr(at + 1);
            hash.insert(name + '@' + domain);
        }
        return hash.size();
    }
};