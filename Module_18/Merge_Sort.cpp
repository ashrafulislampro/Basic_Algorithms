#include <bits/stdc++.h>
using namespace std;
void conquer(int arr[], int l, int mid, int r)
{
    int n = mid - l + 1;
    int a[n];
    int k = l;
    for (int i = 0; i < n; i++)
    {
        a[i] = arr[k++];
    }
    int m = r - mid;
    int b[m];
    k = mid + 1;
    for (int i = 0; i < m; i++)
    {
        b[i] = arr[k++];
    }

    int i = 0, j = 0, curr = l;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            arr[curr++] = a[i++];
        else
            arr[curr++] = b[j++];
    }

    while (i < n)
    {
        arr[curr++] = a[i++];
    }
    while (j < m)
        arr[curr++] = b[j++];
}
void divide(int arr[], int l, int r)
{
    int mid = (l + r) / 2;
    if (l >= r)
    {
        return;
    }
    divide(arr, l, mid);
    divide(arr, mid + 1, r);
    conquer(arr, l, mid, r);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    divide(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}