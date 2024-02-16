#include <stdio.h>


void printArray(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++){
        printf("%d ", nums[i]);
    }
}

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1) 
        return numsSize;
    
    int temp[numsSize];
    int j = 0;
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] != nums[i + 1]){
            temp[j++] = nums[i];
        }
    }
    temp[j++] = nums[numsSize - 1];

    for(int i = 0; i < j; i ++){
        nums[i] = temp[i];
    }
    return j;
}

int main(){

    //example 1
    int nums1[] = {1,1,2};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("The initial array1: ");
    printArray(nums1, n1);
    printf("\nSize of the initial array1: %d \n", n1);

    n1 = removeDuplicates(nums1, n1);
    printf("The array1 after remove duplicates: ");
    printArray(nums1, n1);
    printf("\nSize of the initial array1 after remove dulicates: %d \n", n1);


    //example 2
    int nums2[] = {0,0,1,1,1,2,2,3,3,4};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("\n\nThe initial array2: ");
    printArray(nums2, n2);
    printf("\nSize of the initial array2: %d \n", n2);

    n2 = removeDuplicates(nums2, n2);
    printf("The array1 after remove duplicates: ");
    printArray(nums2, n2);
    printf("\nSize of the initial array2 after remove dulicates: %d \n", n2);

    return 0;
}