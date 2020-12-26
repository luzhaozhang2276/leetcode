#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        m_data.push(x);
        if (m_min.empty() || x <= m_min.top())  // 此处改为<=,能够省略相同最小值的入栈,节省空间
            m_min.push(x);
//        else
//            m_min.push(m_min.top());

    }

    void pop() {
        if (m_data.empty() || m_min.empty())
            return;
        if (m_data.top() == m_min.top())    // 相等才出栈
            m_min.pop();

        m_data.pop();
    }

    int top() {
        return m_data.top();
    }

    int min() {
        return m_min.top();
    }

private:
    stack<int> m_data;      // 数据栈
    stack<int> m_min;       // 辅助栈

};

int main() {

    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-1);
    cout << minStack->min() << endl;     // -3.
    cout << minStack->top() << endl;     // 0.
    minStack->pop();
    cout << minStack->min() << endl;     // -1.

    cout << "\nFinish" << endl;
    return 0;
}
