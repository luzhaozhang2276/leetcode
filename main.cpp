#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

/// NC78. 反转链表

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *cur = pHead, *pre = nullptr;
        while (cur != nullptr) {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main() {
    Solution solve;

    cout << "\nFinish";
    return 0;
}