class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left=new ListNode(0);
        ListNode* currl=left;
        ListNode* right=new ListNode(0);
        ListNode* currr=right;

         
        ListNode* curr=head;
           
         while(curr!=NULL){
             if(curr->val<x){
                 currl->next=curr;
                  curr=curr->next;
                  currl=currl->next;   
             }
             else{
                 currr->next=curr;
                 currr=currr->next;
                 curr=curr->next;
             }
         }
            currr->next=NULL;
            currl->next=right->next;

            return left->next;
    }
};
