#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return nullptr;

        ListNode *pAhead = head;
        ListNode *pBehind = head;

        for (int i = 0; i < k - 1; ++i)
        {
            pAhead = pAhead->next;
            if (pAhead == nullptr)
                return nullptr;
        }

        while (pAhead->next)
        {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }

        return pBehind;
    }
};


int main() {
    vector<int> number = {1,2,3,4,5};

    auto *list = new ListNode(0);
    ListNode *ptr = list;
    for (auto &p:number)
    {
        ptr->next = new ListNode(p);
        ptr = ptr->next;
    }

    ptr = list->next;
    delete list;

    Solution solve;

    auto p = solve.getKthFromEnd(ptr,2);
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }

    cout << "\nFinish" << endl;
    return 0;
}
