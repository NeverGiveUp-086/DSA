int getNthFromLast(Node *head, int n)
{
       // Your code here
       int count=0;
       // we find the length of the linked list
      for(Node* curr=head;curr!=NULL;curr=curr->next){
          count++;
      }
      
    //   Node* curr=head;
    //   while(curr!=NULL){
    //       count++;
    //       curr=curr->next;
    //   }
    
    //if no is greater than the size of the linked list
    // then return -1;
      if(count<n)
      return -1;
       Node* temp=head;
       for(int i=1;i<=count-n;i++){
           temp=temp->next;
       }
   
       return temp->data;
}

// two pointer  method
int getNthFromLast(Node *head, int n)
{
       //two pointer approach
      if(head==NULL)
      return NULL;
      
      //here we take the first pointer int n+1th place from the initial
      // and second pointer will be head of the node 
       Node* first=head;
       for(int i=0;i<n;i++){
           if(first==NULL)
           return -1;
           first=first->next;
       }
       Node* second=head;
       while(first!=NULL){
           second=second->next;
           first=first->next;
       }
       return second->data;
}

