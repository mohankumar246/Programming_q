/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
     ListNode *prev = 0;
     ListNode *curr = head;
     ListNode *next = 0;
     
     if(head)
     {
         next = head->next;
         if(next)
            head = next;
     } 
        
     while(curr && next)
     {
        if(prev) 
            prev->next = next;
        
        curr->next = next->next;
        next->next = curr;
        
        prev       = curr;
        curr       = curr->next;
        
        if(curr)
            next   = curr->next;
        else
            next   = NULL; 
     }
  
     return head;

    }
};