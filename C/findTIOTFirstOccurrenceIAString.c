#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int s1 = strlen(haystack);
    int s2 = strlen(needle);

    for(int i = 0; i < s1 - s2 + 1; i++){
        if(strncmp(haystack + i, needle, s2) == 0){
            return i;
        }
    }

    return -1;
}

void checkPresentOrNot(char* haystack, char* needle){
    int ret = strStr(haystack, needle);
    if (ret == -1)
        printf("%s is not present in %s\n\n", needle, haystack);
    else
        printf("%s present in %s and index %d\n\n", needle, haystack, ret);
}
int main(){

    //Example 1
    char haystack1[] = "sadbutsad";
    char needle1[] = "sad";
    checkPresentOrNot(haystack1, needle1);

    //Example 2
    char haystack2[] = "leetcode";
    char needle2[] = "leeto";
    checkPresentOrNot(haystack2, needle2);
    
   //Example 3
    char haystack3[] = "banana";
    char needle3[] = "na";
    checkPresentOrNot(haystack3, needle3);

    return 0;
}