)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode* nxtPtr=head->next;
        ListNode* prevPtr=NULL;
        
        while(head->next)
        {
            head->next=prevPtr;
            prevPtr=head;
            head=nxtPtr;
            if(nxtPtr->next) nxtPtr=nxtPtr->next;
        }
        head->next=prevPtr;
        prevPtr=NULL;
        return head;
    }
};