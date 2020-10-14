#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}     // 构造函数
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {

        return vector<int> ();
    }
};

int main() {
    ListNode *front = (ListNode*)malloc(sizeof(ListNode));
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->val = 1;


    Solution s;

    cout << "\nFinish" << endl;
    return 0;
}
