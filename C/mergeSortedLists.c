#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode* node){
    while (node != NULL){
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;
    
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = temp;

    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if(list1 != NULL){
        current->next = list1;
    } else if (list2 != NULL) {
        current->next = list2;
    }

    return temp->next;
}

int main() {
    // 
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 3;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 5;
    l1->next->next->next = NULL;

    //
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 1;
    l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 3;
    l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    //
    printf("Danh sach lien ket 1: ");
    printList(l1);
    printf("Danh sach lien ket 2: ");
    printList(l2);

    // 
    struct ListNode* mergedList = mergeTwoLists(l1, l2);

    // 
    printf("Danh sach lien ket sau khi hop nhat: ");
    printList(mergedList);

    // 
    free(l1);
    free(l2);
    free(mergedList);

    return 0;
}