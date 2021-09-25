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

void Heapify(int Arr[], int i, int len)
{
    Arr[0] = Arr[i];
    int child = 2 * i;
    while (child <= len)
    {
        if (child <= len - 1 && Arr[child] < Arr[child + 1])
            child++;
        if (Arr[0] < Arr[child])
        {
            Arr[i] = Arr[child];
            i = child;
            child = 2 * i;
        }
        else
            break;
    }
    Arr[i] = Arr[0];
}

void BuildMaxHeap(int Arr[], int len)
{
    for (int i = len / 2; i > 0; i--)
    {
        Heapify(Arr, i, len);
    }
}

void HeapSort(int Arr[], int len)
{
    BuildMaxHeap(Arr, len);
    for (int i = len; i > 1; i--)
    {
        swap(Arr[1], Arr[i]);
        Heapify(Arr, 1, i - 1);
    }
}

//归并排序
void Merge(int Arr[], int temp[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (Arr[i] <= Arr[j])
        {
            temp[k++] = Arr[i++];
        }
        else
        {
            temp[k++] = Arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = Arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = Arr[j++];
    }
}

void mergePass(int Arr[], int temp[], int n, int len)
{
    int i, j;
    i = 0;
    while (i + 2 * len - 1 < n)
    {
        Merge(Arr, temp, i, i + len - 1, i + 2 * len - 1);
        i = i + 2 * len;
    }
    if (i + len - 1 < n - 1)
        Merge(Arr, temp, i, i + len - 1, n - 1);
    else
    {
        for (j = i; j < n; j++)
        {
            temp[j] = Arr[j];
        }
    }
}

void mergeSort(int Arr[], int size)
{
    int temp[size];
    int len = 1;
    while (len < size)
    {
        mergePass(Arr, temp, size, len);
        len = 2 * len;
        mergePass(temp, Arr, size, len);
        len = 2 * len;
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