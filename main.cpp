#include <bits/stdc++.h>
using namespace std;

class MaxQueue {
    queue<int> que;
    deque<int> deq;
public:
    MaxQueue() {

    }

    int max_value() {
        return deq.empty() ? -1 : deq.front();
    }

    void push_back(int value) {
        que.push(value);
        while (!deq.empty() && deq.back() < value)
            deq.pop_back();
        deq.push_back(value);
    }

    int pop_front() {
        if (que.empty())
            return -1;
        if (deq.front() == que.front())
            deq.pop_front();
        int val = que.front();
        que.pop();
        return val;
    }
};

int main() {
    auto *obj = new MaxQueue;
    obj->push_back(1);
    obj->push_back(2);
    cout << obj->max_value() << endl;
    cout << obj->pop_front() << endl;
    cout << obj->max_value() << endl;

    cout << "\nFinish";
    return 0;
}
