//IT-A-35_Vedant_Oza
//10.Implementation of any one Sorting Technique considering a real-world application.
//Sort (Modular/Procedural)
#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void BubbleSort(int a[], int size)
{
    for (int i = 0; i < size - 2; i++)
    {
        int f = 0;
        for (int j = 0; j <= size - 2 - i; j++) //5-2-0=3 (0,1,2,3)
        {
            if (a[j] > a[j + 1])
            {
                f = 1;
                swap(&a[j], &a[j + 1]);
            }
        }
        if (f == 0)
            break;
    }
}
void InsertionSort(int a[], int size)
{
    int i, j, x;
    for (i = 1; i < size; i++)
    {
        j = i - 1;
        x = a[i];
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}
void SelectionSort(int a[], int size)
{
    int i, j, k;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i, k = i; j < size; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        swap(&a[i], &a[k]);
    }
}
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}
void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}
void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];
    for (i = l; i <= h; i++)
        A[i] = B[i];
}
void IMergeSort(int A[], int n)
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 <= n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
    }
    if (p / 2 < n)
        Merge(A, 0, p / 2 - 1, n);
}
void MergeSort(int A[], int l, int h)//Recursive
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;

        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}
int main()
{
    int size;
    printf("Enter size of Array:");
    scanf("%d", &size);
    int a[size];
    printf("Enter array Elements:");
    for (int i = 0; i < size; i++)
        scanf("%d", &a[i]);
    printf("Array Before sorting:");
    display(a, size);
    // BubbleSort(a, size);
    //InsertionSort(a, size);
    SelectionSort(a, size);
    // QuickSort(a, 0, size);
    // IMergeSort(a, size);
    // MergeSort(a, 0, size);
    printf("Array After sorting: ");
    display(a, size);
    return 0;
}
// //Static Bubble Sort Monolithic
// #include <stdio.h>
// int main()
// {
//     int size, f = 0;
//     printf("Enter size of Array:");
//     scanf("%d", &size);
//     int a[size];
//     printf("Enter array Elements:");
//     for (int i = 0; i < size; i++)
//         scanf("%d", &a[i]);
//     printf("Array Before sorting:");
//     for (int i = 0; i < size; i++)
//         printf("%d ", a[i]);
//     printf("\n");
//     for (int i = 0; i < size - 1; i++)
//     {
//         for (int j = 0; j < size - 1 - i; j++)
//         {
//             if (a[j] > a[j + 1])
//             {
//                 f = 1;
//                 int t = a[j];
//                 a[j] = a[j + 1];
//                 a[j + 1] = t;
//             }
//         }
//         if (f == 0)
//             break;
//     }
//     printf("Array After sorting:");
//     for (int i = 0; i < size; i++)
//         printf("%d ", a[i]);
//     printf("\n");
//     return 0;
// }
// // Dynamic Buuble sort (Modular/Procedural)
// #include <stdio.h>
// #include <stdlib.h>
// int size, *a, i, j;
// void create()
// {
//     a = (int *)malloc(size * sizeof(int));
//     printf("Enter Array Elements:\n");
//     for (int k = 0; k < size; k++)
//     {
//         scanf("%d", &a[k]);
//     }
// }
// void swap()
// {
//     int t;
//     t = a[j];
//     a[j] = a[j + 1];
//     a[j + 1] = t;
// }
// void BubbleSort()
// {
//     int f = 0;
//     for (i = 0; i < size - 1; i++)
//     {
//         for (j = 0; j < size - 1 - i; j++)
//         {
//             if (a[j] > a[j + 1])
//             {
//                 f = 1;
//                 swap();
//             }
//         }
//         if (f == 0)
//             break;
//     }
// }
// void display(int a[])
// {
//     for (int k = 0; k < size; k++)
//     {
//         printf("%d ", a[k]);
//     }
//     printf("\n");
// }
// int main()
// {
//     printf("Enter size of Array:");
//     scanf("%d", &size);
//     create();
//     BubbleSort(&a, size);
//     display(a);
//     return 0;
// }