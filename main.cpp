#include <bits/stdc++.h>
using namespace std;


/// NC140. 排序
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        quickSort(arr, 0, arr.size()-1);
        return arr;
    }

private:
    void quickSort(vector<int>& arr, int l, int r) {
        if (l >= r)
            return;

        // partition 函数
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l])
                --j;
            while (i < j && arr[i] <= arr[l])
                ++i;

            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);    // 交换哨兵位置

        quickSort(arr, l, i-1);    // 递归左子数组
        quickSort(arr, i+1, r);    // 递归右子数组
    }
};



int main() {
    vector<int> nums = {5,2,3,1,4};

    Solution solve;
    for (auto num : solve.MySort(nums))
        cout << num << ' ';

    cout << "\nFinish";
    return 0;
}