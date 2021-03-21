#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// 206. 反转链表
#if 0
/// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 终止条件
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* nex = reverseList(head->next);
        head->next->next = head;    // 分解成单次处理
        head->next = nullptr;       // 避免回环

        return nex;     // nex 始终不变
    }
};

#elif 1
/// 迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *prev = nullptr;
        while (cur != nullptr) {
            auto tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }
};

#endif

int main() {
    vector<int> nums = {1,2,3,4,5};
    ListNode dummy(0);
    ListNode *ptr = &dummy;
    for (auto num : nums) {
        ptr->next = new ListNode(num);
        ptr = ptr->next;
    }

    Solution solve;
    auto p = solve.reverseList(dummy.next);
    while (p != nullptr) {
        cout << p->val << ' ';
        p = p->next;
    }

    cout << "\nFinish";
    return 0;
}