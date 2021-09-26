#include "c.h"

// 快速排序
int Partition(int Arr[], int low, int high)
{
    int pivot = Arr[low];
    while (low < high)
    {
        while (low < high && Arr[high] >= pivot)
            --high;
        Arr[low] = Arr[high];
        while (low < high && Arr[low] <= pivot)
            ++low;
        Arr[high] = Arr[low];
    }
    Arr[low] = pivot;
    return low;
}

void QuickSort(int Arr[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(Arr, low, high);
        QuickSort(Arr, low, pivotpos - 1);
        QuickSort(Arr, pivotpos + 1, high);
    }
}

// 堆排序
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Heapify(int Arr[], int p, int len)
{
    Arr[0] = Arr[p];
    int child = 2 * p;
    while (child <= len)
    {
        if (child + 1 <= len && Arr[child + 1] > Arr[child])
            child++;
        if (Arr[child] > Arr[0])
        {
            Arr[p] = Arr[child];
            p = child;
            child = 2 * p;
        }
        else
            break;
    }
    Arr[p] = Arr[0];
}

void HeapSort(int Arr[], int len)
{
    int i;
    for (i = len / 2; i > 0; i--)
        Heapify(Arr, i, len);
    for (i = len - 1; i > 1; i--)
    {
        int temp;
        temp = Arr[1];
        Arr[1] = Arr[i];
        Arr[i] = temp;
        Heapify(Arr, 1, i - 1);
    }
}

//归并排序
void Merge(int Arr[], int temp[], int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (Arr[i] <= Arr[j])
            temp[k++] = Arr[i++];
        else
            temp[k++] = Arr[j++];
    }
    while (i <= mid)
        temp[k++] = Arr[i++];
    while (j <= high)
        temp[k++] = Arr[j++];
}

void mergePass(int Arr[], int temp[], int n, int len)
{
    int i = 0;
    while (i + 2 * len - 1 <= n - 1)
    {
        Merge(Arr, temp, i, i + len - 1, i + 2 * len - 1);
        i = i + 2 * len;
    }
    if (i + len - 1 < n - 1)
        Merge(Arr, temp, i, i + len - 1, n - 1);
    else
    {
        for (int j = i; j < n; j++)
            temp[j] = Arr[j];
    }
}

void mergeSort(int Arr[], int size)
{
    int temp[size];
    int len = 1;
    while (len < size)
    {
        mergePass(Arr, temp, size, len);
        len *= 2;
        mergePass(temp, Arr, size, len);
        len *= 2;
    }
}

int main()
{
    int Arr[10] = {0, 1, 3, 5, 23, 2, 5, 34, 18, 41};
    // QuickSort(Arr, 0, 9);
    // HeapSort(Arr, 10);
    mergeSort(Arr, 10);
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", Arr[i]);
    }
    return 0;
}