#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// 19. 删除链表的倒数第 N 个结点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0,head);
        ListNode *fast = head, *slow = dummy;
        while (n--)
            fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};

int main() {
    vector<int> nums {1,2,3,4,5};
    ListNode head;
    ListNode *ptr = &head;
    for (auto num : nums) {
        ptr->next = new ListNode(num);
        ptr = ptr->next;
    }
    ptr = head.next;

    Solution solve;
    auto p = solve.removeNthFromEnd(ptr, 2);

    cout << "\nFinish";
    return 0;
}