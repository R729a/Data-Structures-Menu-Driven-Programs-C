#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void display(int arr[], int n)
{
    printf("\nArray: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int n, int element, int index)
{
    if (n >= MAX)
    {
        printf("Array overflow! cannot insert\n");
        return -1;
    }

    for (int i = n - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return n + 1;
}

int indDeletion(int arr[], int n, int index)
{
    int deleted = arr[index];
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("%d element deleted successfully\n", deleted);
    return n - 1;
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nSorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void linearSearch(int arr[], int target, int n)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            printf("%d element found at the index %d.\n", arr[i], i);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("element not found\n");
    }
}

int main()
{
    int target, i, n;
    int index, element;
    int arr[MAX];
    int option = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Input: Elements of the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\n-------MENU---------\n");
        printf("1.Display array\n");
        printf("2.Insert element in array\n");
        printf("3.Delete a element in array\n");
        printf("4.search element by linear search\n");
        printf("5.Sort using bubble sort \n");
        printf("6.Exit\n");

        printf("Choose the option:");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            
            display(arr, n);
            break;
        case 2:

            printf("Insert an element in array");
            printf("\nEnter the element:");
            scanf("%d", &element);

            printf("enter the index in which you want the element :");
            scanf("%d", &index);

            if (index >= 0 && index <= n)
            {
                indInsertion(arr, n, element, index);
                n++;
            }
            else
            {
                printf("Invalid index!\n");
            }

            break;
        case 3:

            printf("Enter the index to delete:-");
            scanf("%d", &index);

            if (index >= 0 && index < n)
            {
                indDeletion(arr, n, index);
                n--;
            }
            else
            {
                printf("Invalid index!\n");
            }
            
            break;
        case 4:

            printf("find by linear search\n");
            printf("\nEnter the element to found:");
            scanf("%d", &target);
            linearSearch(arr, target, n);
            break;
        case 5:

            bubbleSort(arr, n);

            break;
        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
