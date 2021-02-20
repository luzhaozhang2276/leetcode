#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {

    }

    void addNum(int num) {
        if (maxheap.size() != minheap.size()) {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        } else {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }

    double findMedian() {
        return maxheap.size() == minheap.size() ?
               ((maxheap.top() + minheap.top())*0.5) :
               minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {

    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;


    cout << "\nFinish";
    return 0;
}
