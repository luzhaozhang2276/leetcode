#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// 142. 环形链表 II
/// 快慢双指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (true) {
            if (fast == nullptr || fast->next == nullptr)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};

int main() {
    Solution solve;

    cout << "\nFinish";
    return 0;
}