#include <stdio.h>

int Create(int a[], int *n) {
    printf("Please Enter the Number of elements you want in the new array ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("\nElement %d ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Array Created Successfully \n");
}

int Display(int a[], int *n) {
    printf("The Currently stored Array is:\n");
    for (int i = 0; i < *n; i++)
        printf("%d\n", a[i]);
    printf("End of Array \n");
}

int Insert(int a[], int *n) {
    int i, pos;
    printf("Enter the position you want to add element in the array at ");
    scanf("%d", &pos);
    pos--;
    for (i = *n; i > pos; i--)
        a[i] = a[i - 1];
    printf("Enter the No you want to add to index : %d or Position : %d\n", pos, pos + 1);
    scanf("%d", &a[pos]);
    (*n)++;
    printf("Inserted Successfully \n");
}

int Delete(int a[], int *n) {
    int pos;
    printf("Enter the position you want to delete from the array ");
    scanf("%d", &pos);
    for (int i = pos - 1; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
    printf("Deletion Successful \n");
}

int LinSearch(int a[], int *n) {
    int req, i;
    printf("Please enter the no you want to find ");
    scanf("%d", &req);
    for (i = 0; i < *n && a[i] != req; i++);
    if (i == *n) {
        printf("Number not found\n");
        return;
    }
    printf("Number found at Position %d\n", i + 1);
}

int Exit(int *option) {
    *option = 0;
}

int main() {
    int option = 1, n = 0;
    int arr[50];
    while (option != 0) {
        printf("Enter the option number you want to use\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Linear Search\n");
        printf("0. Exit\n");
        printf("Choosing Create Option Will Delete the Previous Array Completely\n");
        scanf("%d", &option);
        switch (option) {
        case 0:
            Exit(&option);
            break;
        case 1:
            Create(arr, &n);
            break;
        case 2:
            Display(arr, &n);
            break;
        case 3:
            Insert(arr, &n);
            break;
        case 4:
            Delete(arr, &n);
            break;
        case 5:
            LinSearch(arr, &n);
            break;
        default:
            printf("Invalid input please try again\n");
            break;
        }
    }
    return 0;
}
