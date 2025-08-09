#include<stdio.h>
int main () {
    int i , n , arr[20];
    printf("enter the number of element of the arrays :");
    scanf("%d",&n);
    for(int i = 0; i<n ; i++) {
        printf("\n arr[%d] = ",i);
        scanf("%d",&arr[i]);

    }
    printf ("\n the array elements are ");
    for(i= 0; i<n; i++ ) {
        printf("\t %d",arr[i]);
           }
           return 0;
}