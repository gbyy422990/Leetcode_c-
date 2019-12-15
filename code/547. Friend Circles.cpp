//
// Created by bin gao on 2019-12-07.
//

class Solution {
public:
    vector<int> p;
    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }


    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();

        for(int i = 0; i < n; i++){
            p.push_back(i);
        }

        int res = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(M[i][j] == 1){
                    if(find(i) != find(j)){
                        p[find(i)] = find(j);
                        res--;
                    }
                }
            }
        }
        return res;
    }
};