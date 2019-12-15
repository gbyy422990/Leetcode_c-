//
// Created by bin gao on 2019-12-09.
//

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        typedef pair<int, string> PIS;
        priority_queue<PIS> q;


        int n = words.size();
        for(int i = 0; i < n; i++) hash[words[i]]++;

        for(auto item: hash){
            PIS t(-item.second, item.first);
            q.push(t);
            if(q.size() > k) q.pop();
        }
        vector<string> res(k);
        for(int i = k - 1; i >=0; i--){
            res[i] = q.top().second;
            q.pop();
        }
        return res;
    }
};