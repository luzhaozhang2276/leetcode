#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while (A != B) {
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }
};

void generateList(ListNode *headA, ListNode *headB) {
    vector<int> A = {4, 1};
    vector<int> B = {5, 0, 1, 8, 4, 5};

    ListNode *ptr = headB, *pinter;
    for (int p:B) {
        ptr->next = new ListNode(p);
        ptr = ptr->next;
        if (p == 8)
            pinter = ptr;
    }

    ptr = headA;
    for (int p:A) {
        ptr->next = new ListNode(p);
        ptr = ptr->next;
    }
    ptr->next = pinter;

}


int main() {
    auto *headA = new ListNode(0);
    auto *headB = new ListNode(0);
    generateList(headA, headB);
    headA = headA->next;
    headB = headB->next;

    Solution solve;
    cout << "node = " << solve.getIntersectionNode(headA, headB)->val << endl;

    cout << "\nFinish";
    return 0;
}
