/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(0);
        ListNode* t = temp;
        while(list1 && list2){
            if(list1->val <= list2->val){
                t->next = new ListNode(list1->val);
                list1 = list1->next;
                t=t->next;
            }
            else{
                t->next = new ListNode(list2->val);
                list2 = list2->next;
                t=t->next;
            }
        }
        while(list1){
            t->next = new ListNode(list1->val);
            list1 = list1->next;
            t=t->next;
        }
        while(list2){
            t->next = new ListNode(list2->val);
            list2 = list2->next;
            t=t->next;
        }
        return temp->next;
    }
};
