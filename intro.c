#include<stdio.h>
int linearSearch(int arr[],int x,int n) {
    for(int i = 0 ; i< n ; i++) {
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){

    int n;
    printf("Enter size: ");
    scanf("%d\n",&n);



    // printf("Enter elements of array:  ");
    int arr[n];
    for(int i = 0 ; i < n ; i++) {
        // printf("Enter %d element: ", i);
        scanf("%d",&arr[i]);
    }

    int x;
    printf("Enter x : ");
    scanf("%d", &x); 


   int index = linearSearch(arr,x,n);
   if(index == -1){
    printf("key not found");
   }
   else {
    printf("The keyis found at index : %d", i);

   }


return 0; 
}