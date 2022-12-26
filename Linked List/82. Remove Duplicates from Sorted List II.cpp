// baisc link traversal
ListNode* deleteDuplicates(ListNode* head) {
        

      ListNode* dummy=new ListNode(0);
      dummy->next=head;
      ListNode* prev=dummy;
       

       while(head!=NULL){
           
       if(head->next!=NULL && head->val==head->next->val){
                 while( head->next!=NULL && head->val==head->next->val){
                 head=head->next;
                 }
                 prev->next=head->next;
       }
       else{
            prev=prev->next;
       }
       head=head->next;
       }
         return dummy->next;
    }

// recursive approach

    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
  
        ListNode* ptr=head->next;
        if(ptr->val==head->val)
        {
            while(ptr!=NULL && ptr->val==head->val)
                   ptr=ptr->next;
                return deleteDuplicates(ptr);
        }
            else
            {
                head->next=deleteDuplicates(ptr);
                return head;
            }
    }
