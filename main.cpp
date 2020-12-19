#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 1
/// 递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr)
            return l2 == nullptr ? l1 : l2;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

#elif 1
/// 伪头结点
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            } else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1!= nullptr ? l1 : l2;
        return dummy.next;
    }
};

#endif

/// 生成链表
ListNode* createList(const vector<int> &number)
{
    auto *list = new ListNode(0);
    list->next = nullptr;
    ListNode *res = list;
    for (auto &p:number)
    {
        res->next = new ListNode(p);
        res = res->next;
    }

    res = list->next;
    delete list;

    return res;
}

/// 可视化链表
void printList(ListNode* ptr)
{
    while (ptr != nullptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    /// 数据生成 ptr
    vector<int> number1 = {1,3,5,6,7};
    vector<int> number2 = {2,3,4,6,8};

    ListNode *ptr1 = createList(number1);
    ListNode *ptr2 = createList(number2);

    Solution slove;
    ListNode* ptr = slove.mergeTwoLists(ptr1, ptr2);

    cout << "compute: ";
    printList(ptr);

    cout << "\nFinish" << endl;
    return 0;
}
