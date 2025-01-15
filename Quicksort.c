#include <stdio.h>

void show(int a[])
{
    for (int i = 0; i <= 8; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int partition(int a[], int low, int high)
{
    int i, j, pivot, temp;
    pivot = a[low];
    printf("pivot=%d\n", pivot);
    i = low;
    j = high;
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            printf("swapped %d with %d\n", a[i], a[j]);
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    if (low < j)
    {
        printf("swapped pivot %d with %d\n", a[low], a[j]);
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
    }
    return j;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        show(a);
        int j = partition(a, low, high);
        quickSort(a, low, j);
        quickSort(a, j + 1, high);
        show(a);
    }
}

int main()
{
    int a[] = {10, 16, 8, 12, 15, 6, 3, 9,5};
    quickSort(a, 0, 9);
    show(a);
}