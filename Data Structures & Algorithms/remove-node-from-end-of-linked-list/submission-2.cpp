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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t = head;
        int cnt=0;
        while(t){
            t=t->next;
            cnt++;
        }
        if(n>cnt){
            n=n%cnt;
        }
        int k = cnt-n;
        ListNode* t1 = head;
        while(k>1){
            t1=t1->next;
            k--;
        }
        if(t1->next && k!=0)
        t1->next = t1->next->next;
        if(k==0)
        {
            if(head->next)
            return head->next;
            else
            return NULL;
        }
        return head;
    }
};
