#include <stdio.h>

int main() {
    int a[50], i, j, k, n;

    printf("Please Enter the Number of elements you want in the new array ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nElement %d ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("The Current Array is:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    printf("\n");

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                for (k = j; k < n - 1; k++)
                    a[k] = a[k + 1];
                n--;
                j--;
            }
        }
    }

    printf("The Updated Array is:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    return 0;
}
