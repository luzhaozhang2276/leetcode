#include <bits/stdc++.h>
using namespace std;

/// NC93. 设计LRU缓存结构

struct DLinkedNode {
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class Solution {
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size, capacity;
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        if (k < 1)
            return {};

        size = 0;
        capacity = k;

        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;

        if (operators.empty())
            return{};

        vector<int> res;
        for (auto op : operators) {
            if (op[0] == 1)
                put(op[1], op[2]);
            else if (op[0] == 2)
                res.push_back(get(op[1]));
        }

        return res;
    }

    int get(int _key) {
        if (!cache.count(_key))     // 不存在
            return -1;
        else {      // 存在
            moveToHead(cache[_key]);
            return cache[_key]->value;
        }
    }

    void put(int _key, int _value) {
        if (!cache.count(_key)) {   // 不存在
            auto* ptr = new DLinkedNode(_key, _value);
            addToHead(ptr);
            cache[_key] = ptr;
            ++size;
            if (size > capacity) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
        else {      // 存在
            cache[_key]->value = _value;
            moveToHead(cache[_key]);
        }
    }

private:
    void addToHead(DLinkedNode* node) {
        auto ptr = head->next;
        head->next = node;
        node->prev = head;
        node->next = ptr;
        ptr->prev = node;
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};




int main() {


    cout << "\nFinish";
    return 0;
}