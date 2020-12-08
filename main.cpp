#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;

        if (head->val == val)
            return head->next;

        /// 双指针
        /*
        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur != nullptr && cur->val != val)
        {
            pre = cur;
            cur = cur->next;
        }
        if (cur != nullptr)
            pre->next = cur->next;
        */

        /// 单指针
        /*
        ListNode *ptr = head;
        while (ptr->next != nullptr)
        {
            if (ptr->next->val == val)
            {
                ListNode *pNext = ptr->next;
                ptr->next = pNext->next;
                delete pNext;
                return head;
            }
            ptr = ptr->next;
        }
        */

        /// 递归
        head->next = deleteNode(head->next, val);

        return head;
    }
};



int main() {
    vector<int> number = {4,5,1,9};

    auto *list = new ListNode(0);
    ListNode *ptr = list;
    for (auto &p:number)
    {
        ptr->next = new ListNode(p);
        ptr = ptr->next;
    }

    ptr = list->next;
    delete list;



    Solution s;
    ListNode *res = s.deleteNode(ptr, 5);

    cout << "print:" << endl;
    while (res)
    {
        cout << res->val << endl;
        res = res->next;
    }


    cout << "\nFinish" << endl;
    return 0;
}
