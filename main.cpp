#include <iostream>
#include <bitset>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// 148. 排序链表
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        /// step 1 : quit
        if (head == nullptr || head->next == nullptr)
            return head;

        /// step 2.1 : cut
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tmp = slow->next;
        slow->next = nullptr;

        /// step 3 : recurse
        ListNode* left = sortList(head);
        ListNode* right = sortList(tmp);

        /// step 2.2 : merge
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                ptr->next = left;
                left = left->next;
            } else {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        ptr->next = (left != nullptr) ? left : right;

        return dummy->next;
    }
};

int main() {


    return 0;
}