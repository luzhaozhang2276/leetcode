#include <bits/stdc++.h>
using namespace std;

#if 0
/// 基于partition函数的快排
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size())
            return arr;

        quickSort(arr, 0, arr.size()-1);    // 快排

        vector<int> res;
        res.assign(arr.begin(), arr.begin()+k);     // 赋值前k个元素
        return res;
    }

private:
    /// 基于partition函数的快速排序
    void quickSort(vector<int>& arr, int l, int r) {
        // 递归终止条件
        if (l >= r)     // 子数组长度为 1, 终止递归
            return;

        // 调用 partition() 进行划分,得到index
        int index = partition(arr, l, r);

        // 递归调用
        quickSort(arr, l, index-1);     // 递归左子数组
        quickSort(arr, index+1, r);     // 递归右子数组
    }

    int partition(vector<int>& arr, int l, int r) {
        /// partition函数
        // (哨兵划分操作,此处取arr[l] 作为基准/哨兵, 即首元素)
        int i = l, j = r;
        while (i < j) {
            // 从右往左: 查找 首个小于哨兵的元素
            while (i < j && arr[j] >= arr[l])
                j--;
            // 从左往右: 查找 首个大于哨兵的元素
            while (i < j && arr[i] <= arr[l])
                i++;
            // 交换哨兵位置
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        return i;
    }

};

#elif 0
/// 基于快排的数组划分
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size())
            return arr;
        quickSort(arr, 0, arr.size()-1, k);    // 快排

        vector<int> res;
        res.assign(arr.begin(), arr.begin()+k);     // 赋值前k个元素
        return res;
    }

private:
    /// 基于partition函数的快速排序
    void quickSort(vector<int>& arr, int l, int r, int k) {
        // 递归终止条件
        if (l >= r)     // 子数组长度为 1, 终止递归
            return;

        // 调用 partition() 进行划分,得到index
        int index = partition(arr, l, r);

        // 递归调用
        if (index > k)
            quickSort(arr, l, index-1, k);     // 递归左子数组
        if (index < k)
            quickSort(arr, index+1, r, k);     // 递归右子数组
    }

    int partition(vector<int>& arr, int l, int r) {
        /// partition函数
        // (哨兵划分操作,此处取arr[l] 作为基准/哨兵, 即首元素)
        int i = l, j = r;
        while (i < j) {
            // 从右往左: 查找 首个小于哨兵的元素
            while (i < j && arr[j] >= arr[l])
                j--;
            // 从左往右: 查找 首个大于哨兵的元素
            while (i < j && arr[i] <= arr[l])
                i++;
            // 交换哨兵位置
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        return i;
    }

};

#elif 1
/// 使用大顶堆(优先队列)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (k <= 0)
            return res;
        if (k >= arr.size())
            return arr;

        // 构建大顶堆(优先队列)
        priority_queue<int> Q;
        for (int i = 0; i < k; ++i)
            Q.push(arr[i]);

        // 遍历剩余的元素,保留最小的k个元素
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < Q.top()) {
                Q.pop();
                Q.push(arr[i]);
            }
        }

        for (int i = 0; i < k; ++i) {
            res.emplace_back(Q.top());
            Q.pop();
        }

        return res;
    }
};

#elif 1
/// 调用sort() 进行排序(快排)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i)
            res.emplace_back(arr[i]);

        return res;
    }
};
#endif

int main() {
//    vector<int> nums = {4,5,1,6,2,7,3,8};
    vector<int> nums = {0,0,0,2,0,5};

    Solution solve;
    vector<int> res = solve.getLeastNumbers(nums, 0);

    for (auto p:res)
        cout << p << " ";
    cout << endl;

    cout << "\nFinish";
    return 0;
}
