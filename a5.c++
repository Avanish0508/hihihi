#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
void buildHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void insert(vector<int> &arr, int value)
{
    arr.push_back(value);
    int index = arr.size() - 1;
    while (index > 0 && arr[index] < arr[(index - 1) / 2])
    {
        swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}
int main()
{
    vector<int> arr = {1, 5, 6, 8, 9, 7, 3};
    buildHeap(arr);
    cout << "Min Heap: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    int newValue = 4;
    insert(arr, newValue);
    cout << "Min Heap after inserting " << newValue << ": ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
