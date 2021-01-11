#include <bits/stdc++.h>
using namespace std;

#if 1
/// 单调栈
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> sta;
        int root = static_cast<int>(1e10);

        for (int i = postorder.size() - 1; i >= 0; --i) {
            if (postorder[i] > root)
                return false;

            while (!sta.empty() && (sta.top() > postorder[i])) {
                root = sta.top();
                sta.pop();
            }
            sta.push(postorder[i]);
        }
        return true;
    }
};
#elif 1

/// 递归分治
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size()-1);
    }

    bool recur(vector<int>& postorder, int l, int r) {
        // 递归终止条件
        if (l >= r)
            return true;

        // 划分左右子树
        int p = l;
        while (postorder[p] < postorder[r])
            p++;
        int m = p;

        // 判断子树是否为二叉搜索树
        // (在划分时,已经能够保证左子树的正确性,此处只需要判断右子树)
        while (postorder[p] > postorder[r])
            p++;

        // p == r : 直到最后一个(即根节点)才退出,说明根节点之前的区间(右子树)正确
        // 递归判断左子树和右子树
        return p == r && recur(postorder, l, m-1) && recur(postorder, m, r-1);
    }
};

#elif 1
/// 剑指offer版本
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty())
            return true;

        int root = postorder.back();

        int i;
        for (i = 0; i < postorder.size() - 1; ++i)
        {
            if (postorder[i] > root)
                break;
        }

        for (int j = i; j < postorder.size() - 1; ++j)
        {
            if (postorder[j] < root)
                return false;
        }

        bool left = true;
        if (i > 0)
        {
            vector<int> lvec(postorder.begin(), postorder.begin()+i);
            left = verifyPostorder(lvec);
        }

        bool right = true;
        if (i < postorder.size() - 1)
        {
            vector<int> rvec(postorder.begin()+i, postorder.end() - 1);
            right = verifyPostorder(rvec);
        }

        return (left && right);
    }
};

#endif

int main() {
    vector<int> num = {1,3,2,6,5};

    Solution solve;
    string result = solve.verifyPostorder(num) ? "True" : "False";
    cout << "result: " << result << endl;

    cout << "\nFinish";
    return 0;
}
