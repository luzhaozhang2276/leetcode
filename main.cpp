#include <bits/stdc++.h>
//#include <random>
//#include <chrono>

using namespace std;

void inline swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

int inline randRange(int low, int high)
{
    uniform_int_distribution<int> u(low, high);
    mt19937 rand_generator(chrono::high_resolution_clock::now().time_since_epoch().count());
    return u(rand_generator);
}

int partition(int nums[], int low, int high)
{
    int id = randRange(low, high);
    swap(nums[id], nums[high]);

    int i=0,j=0;
    for (i = low, j = low; j < high; ++j)
    {
        if (nums[j] <= nums[high])
        {
                swap(nums[i++], nums[j]);
        }
    }
    swap(nums[i], nums[j]);
    return i;
}

void quickSort(int nums[], int begin, int end)
{

    if (begin >= end) return;

    int index = partition(nums, begin, end);
    if (index>begin)
        quickSort(nums, begin, index-1);
    if (index<end)
        quickSort(nums, index+1, end);
}


int main() {
    int data[] = {5,9,1,2,8,6,3,7};
//    //int data[] = {5,9,2,1,4,7,5,8,3,6};
//
    for (auto p:data)
        cout << p << ' ';
    cout << endl;

    quickSort(data, 0, 7);

    cout << endl;
    for (auto p:data)
        cout << p << ' ';
    cout << endl;

    cout << "\nFinish" << endl;
    return 0;
}
