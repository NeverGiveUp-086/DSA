
class Solution {
public:
     ListNode* reverse(ListNode* head){
         ListNode* curr=head;
         ListNode* prev=NULL;
         ListNode* nxt=NULL;

         while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
         }
          return prev;
     }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* nl1=reverse(l1);
        ListNode* nl2=reverse(l2);
       
        ListNode* ans=new ListNode(0);
        ListNode* curr=ans;
         int carry=0;
         
         while(nl1!=NULL || nl2!=NULL || carry!=0){
             int sum=0;
             if(nl1!=NULL){
                 sum+=nl1->val;
                 nl1=nl1->next;
             }
             if(nl2!=NULL){
                 sum+=nl2->val;
                 nl2=nl2->next;
             }
              sum+=carry;

              carry=sum/10;

              curr->next=new ListNode(sum%10);
              curr=curr->next;
         }
         return reverse(ans->next);
    }
};
