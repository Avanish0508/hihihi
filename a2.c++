#include <iostream>
#include <algorithm>
using namespace std;
void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; ++i)
    {
        int index = arr[i] / exp;
        count[index % 10]++;
    }
    for (int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; --i)
    {
        int index = arr[i] / exp;
        output[count[index % 10] - 1] = arr[i];
        count[index % 10]--;
    }
    for (int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n)
{
    int max_value = *max_element(arr, arr + n);
    int exp = 1;
    while (max_value / exp > 0)
    {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}
int main()
{
    int input_list[] = {136, 487, 358, 469, 570, 247, 598, 639, 205, 609};
    int n = sizeof(input_list) / sizeof(input_list[0]);
    radixSort(input_list, n);
    cout << "Sorted list:";
    for (int i = 0; i < n; ++i)
    {
        cout << " " << input_list[i];
    }
    cout << endl;
    return 0;
}