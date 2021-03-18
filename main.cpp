#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* create (vector<int>& nums) {
    auto *list = new ListNode(0);
    ListNode *ptr = list;
    for (auto &p:nums)
    {
        ptr->next = new ListNode(p);
        ptr = ptr->next;
    }

    ptr = list->next;
    delete list;
    return ptr;
}

/// 25. K 个一组翻转链表

#if 0
/// 迭代
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyHead = new ListNode(0,head);
        ListNode *pre = dummyHead;
        while (head) {
            ListNode *tail = pre;
            // 剩余 >= k
            for (int i = 0; i < k; ++i) {
                if (tail->next == nullptr)
                    return dummyHead->next;
                tail = tail->next;
            }

            /// 交换处理
            ListNode* nex = tail->next;
            // 处理内部
            tie(head, tail) = ReverseList(head, tail);  // C++17标准
            // 处理边界
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return dummyHead->next;
    }

private:
    pair<ListNode*, ListNode*> ReverseList(ListNode *head, ListNode *tail) {
        ListNode *prev = tail->next;
        ListNode *p = head;
        while (prev != tail) {
            ListNode *nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }

        return {tail, head};
    }
};

#elif 1
/// 递归
class Solution {
public:
    ListNode* reverse(ListNode* head,ListNode *tail) {  //反转链表模板，建议背熟
        auto p1 = head, p2 = head->next;

        while (p2 != tail) {
            auto p3 = p2->next;
            p2->next = p1;
            p1 = p2, p2 = p3;
        }

        return p1;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;

        auto tail = head;
        for (int i = 0; i < k; i ++ ) {                 //遍历k个节点
            if (!tail) return head;                     //不足k个节点则不反转，直接返回
            tail = tail->next;                          //使尾结点与头结点相距k
        }

        auto newHead = reverse(head, tail);             //反转长度为k的链表
        head->next = reverseKGroup(tail, k);            //递归将下一段反转链表接到当前段的尾部

        return newHead;
    }
};

#endif

int main() {
    vector<int> nums = {1,2,3,4,5};

    Solution solve;
    auto p = solve.reverseKGroup(create(nums), 1);
    while (p != nullptr) {
        cout << p->val << " -> ";
        p = p->next;
    }

    cout << "\nFinish";
    return 0;
}