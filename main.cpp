#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

/// NC50. 链表中的节点每k个一组翻转

#if 1
/// 迭代
class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* pre = dummyHead;
        while (head != nullptr) {
            // 寻找当前组k的尾节点
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                if (tail->next == nullptr)
                    return dummyHead->next;
                tail = tail->next;
            }

            // 反转操作
            ListNode* nex = tail->next;
            tie(head, tail) = ReverseLists(head, tail);    // 内部反转
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return dummyHead->next;
    }

private:
    pair<ListNode*, ListNode*> ReverseLists(ListNode* head, ListNode* tail) {
        auto *prev = tail->next;
        auto *ptr = head;
        while (prev != tail) {
            auto *nex = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nex;
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
    Solution solve;

    cout << "\nFinish";
    return 0;
}