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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int c = 0;
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        while(t1 || t2 || c){
            int x1=0,x2=0;
            if(t1){
                x1 = t1->val;
                t1 = t1->next;
            }
            if(t2){
                x2 = t2->val;
                t2 = t2->next;
            }
            int n = x1+x2+c;
            int rem = n%10;
            ans->next = new ListNode(rem);
            c = n/10;
            ans=ans->next;
        }
        ListNode* res = temp->next;
        return res;
    }
};
