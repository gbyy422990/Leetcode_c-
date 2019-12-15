//
// Created by bin gao on 2019-12-01.
//

class MyHashMap {
public:
    /** Initialize your data structure here. */
    const int N = 20011;
    vector<list<pair<int, int>>> h;

    MyHashMap() {
        h = vector<list<pair<int, int>>>(N);
    }

    list<pair<int, int>>::iterator find(int key){
        int t = key % N;
        for(auto it = h[t].begin(); it != h[t].end(); it++){
            if(it->first == key) return it;
        }
        return h[t].end();
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto it = find(key);
        int t = key % N;
        if(it == h[t].end()) h[t].push_back({key, value});
        else it->second = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto it = find(key);
        int t = key % N;
        if(it != h[t].end()) return it->second;
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto it = find(key);
        int t = key % N;
        if(it != h[t].end()) h[t].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */