//
// Created by bin gao on 2019-12-09.
//

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> smaller;
    priority_queue<int> larger;
    MedianFinder() {

    }

    void addNum(int num) {
        if(larger.size() == 0 || num >= larger.top()) smaller.push(num);
        else{
            larger.push(num);
            smaller.push(larger.top());
            larger.pop();
        }
        if(smaller.size() > larger.size() + 1){
            larger.push(smaller.top());
            smaller.pop();
        }
    }

    double findMedian() {
        if((smaller.size() == larger.size())){
            return (smaller.top() + larger.top()) / 2.0;
        }
        else return smaller.top();

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */