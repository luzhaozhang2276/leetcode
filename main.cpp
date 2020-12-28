#include <bits/stdc++.h>
using namespace std;

#if 1
// 精简版
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stackData;
        auto ppop = popped.begin();
        for (auto p:pushed)
        {
            stackData.push(p);
            while (!stackData.empty() && stackData.top() == *ppop) {
                stackData.pop();
                ppop++;
            }
        }

        return stackData.empty();
    }
};

#elif 1
// 常规解法
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.empty() && popped.empty())
            return true;

        stack<int> stackData;
        auto pPush = pushed.begin();
        auto pPop  = popped.begin();

        while (pPop != popped.end())
        {
            while (stackData.empty() || stackData.top() != *pPop)
            {
                if (pPush == pushed.end())
                    break;
                stackData.push(*(pPush++));
            }

            if (stackData.top() != *pPop)
                break;

            stackData.pop();
            pPop++;
        }

        return stackData.empty() && pPop == popped.end();
    }
};
#endif

int main() {
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};

    Solution solve;
    string result = solve.validateStackSequences(pushed, popped) ? "True" : "False";
    cout << "result: " << result << endl;

    cout << "\nFinish";
    return 0;
}
