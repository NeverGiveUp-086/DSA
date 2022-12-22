class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(head==NULL || head->next==NULL)
        return head;
        
        Node* curr=head;
        int zero=0;
        int one=0;
        int two=0;
        //we count the no of zero one and two in the linked list 
        //one by one 
        while(curr!=NULL){
            if(curr->data==0){
                 zero++;
            }
            else if(curr->data==1){
                one++;
            }
            else {
            two++;
            }
            
             curr=curr->next;
        }
        //then we update the value in the original linked list 
        // by the no of times zero one and two occurs
        
        curr=head;
        int i=0;
        for(;i<zero;i++){
            curr->data=0;
            curr=curr->next;
        }
        for(;i<zero+one;i++){
            curr->data=1;
            curr=curr->next;
        }
        for(;i<zero+one+two;i++){
            curr->data=2;
            curr=curr->next;
        }
        // we return the original linked list bcz we have update the value in the 
        // original linked list
        return head;
    }
};
