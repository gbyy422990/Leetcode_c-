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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = 0; i <= n; i++) p.push_back(i);

        for(int i = 0; i < n; i++){
            int first = edges[i][0], second = edges[i][1];
            if(find(first) != find(second)){
                p[find(first)] = find(second);
            }
            else return {first, second};
        }
        return {-1, -1};
    }
};