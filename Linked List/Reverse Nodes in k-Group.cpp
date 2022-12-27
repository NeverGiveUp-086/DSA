class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* ksizechecker=head;
        for(int i=0;i<k;i++){
            if(ksizechecker==NULL)
            return head;
            ksizechecker=ksizechecker->next;
        } 
         ListNode* curr=head;
         ListNode* prev=NULL;
         ListNode* nxt=NULL;
         int count=0;
         while(curr!=NULL && count<k){
             nxt=curr->next;
             curr->next=prev;
             prev=curr;
             curr=nxt;
             count++;
         }
         if(curr!=NULL){
             head->next=reverseKGroup(curr,k);
         }
               return prev;
    }
};
