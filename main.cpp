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

/// 23. 合并K个升序链表

#if 0
/// 两两合并(分治法)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        int n = lists.size();
        while (n > 1) {
            int idx = 0;
            for (int i = 0; i < n; i += 2) {
                if (i == n - 1)
                    lists[idx++] = lists[i];
                else
                    lists[idx++] = merge2Lists(lists[i], lists[i+1]);
            }

            n = idx;
        }

        return lists[0];
    }

private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;

        if (l2 == nullptr)
            return l1;

        if (l1->val < l2->val) {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }
};

#elif 0
/// 两两合并(分治法+递归二分法)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        return merge(lists, 0, lists.size()-1);
    }

private:
    ListNode* merge(vector<ListNode*>& lists, int lo, int hi) {
        if (lo == hi)           // 终止条件
            return lists[lo];

        int mid = lo + (hi - lo) / 2;
        auto l1 = merge(lists, lo, mid);
        auto l2 = merge(lists, mid+1, hi);
        return merge2Lists(l1, l2);
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;

        if (l2 == nullptr)
            return l1;

        if (l1->val < l2->val) {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }
};

#elif 1
/// 小顶堆(优先队列)
class Solution {
public:
    // 运算符重载 < : 实现小顶堆

    struct status {
        int val;
        ListNode *ptr;
        bool operator < (const status &rhs) const {
            return rhs.val < val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<status> heap;
        for (auto node : lists) {
            if (node)
                heap.push({node->val, node});
        }

        ListNode dummy;
        ListNode *tail = &dummy;
        while (!heap.empty()) {
            auto p = heap.top();
            heap.pop();
            tail->next = p.ptr;
            tail = tail->next;
            if (p.ptr->next)
                heap.push({p.ptr->next->val, p.ptr->next});
        }
        return dummy.next;
    }
};

#endif

int main() {
    vector<ListNode*> lists;
    vector<int> nums1 = {};
    vector<int> nums2 = {-1,5,11};
    vector<int> nums3 = {};
    vector<int> nums4 = {6,10};
    lists.emplace_back(create(nums1));
    lists.emplace_back(create(nums2));
    lists.emplace_back(create(nums3));
    lists.emplace_back(create(nums4));

    Solution solve;
    auto p = solve.mergeKLists(lists);
    while (p != nullptr) {
        cout << p->val << " -> ";
        p = p->next;
    }

    cout << "\nFinish";
    return 0;
}