#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        } else if(list2 == nullptr){
            return list1;
        }

        ListNode* temp = new ListNode(0);
        ListNode* current = temp;

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val > list2->val){
                current->next = list2;
                list2 = list2->next;
            } else {
                current->next = list1;
                list1 = list1->next;
            }
            current = current->next;
        }

        if(list1 != nullptr){
            current->next = list1;
        } else {
            current->next = list2;
        }

        return temp->next;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create list 1: 1 -> 3 -> 5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    // Create list 2: 2 -> 4 -> 6
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    std::cout << "list 1: ";
    printList(l1);
    std::cout << "list 2: ";
    printList(l2);

    // create class solution
    Solution solution;

    // merge 2 list
    ListNode* mergedList = solution.mergeTwoLists(l1, l2);

    std::cout << "The list after merge: ";
    printList(mergedList);

    // free memory
    delete l1;
    delete l2;
    delete mergedList;

    return 0;
}