#include<stdio.h>

int main() {
    int Array[3][3]={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int sor, soc;
    printf("\n");

    printf("Original Array:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", Array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0; i<3; i++) {
        sor = 0; 
        for(int j=0; j<3; j++) {
            sor = sor + Array[i][j];
        }
        printf("Sum of row %d is %d\n", i+1, sor);
        }
    printf("\n");    

    for(int j=0; j<3; j++) {
        soc = 0; 
        for(int i=0; i<3; i++) {
            soc = soc + Array[i][j];
        }
        printf("Sum of column %d is %d\n", j+1, soc);
    }
    return 0;
}