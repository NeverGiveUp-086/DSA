class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergelist(Node* h1,Node* h2){
        // if first list is null then we return the second list 
        // if seond list is null then we print the first list 
        if(h1==NULL || h2==NULL)
        return (h1==NULL)?h2:h1;
        
        // we create the dummy node 0;
        Node* ans=new Node(0);
        
        Node* curr=ans;
        while(h1!=NULL && h2!=NULL){
            if(h1->data<h2->data){
                curr->next=h1;
                h1=h1->next;
            }
            else{
                curr->next=h2;
                h2=h2->next;
            }
            curr=curr->next;
        }
        //if h1 is not null then we add it to the 
        // next to the ans list 
        if(h1!=NULL){
            curr->next=h1;
        }
        //if h2 is not null then we add it to the 
        // next to the ans list 
        if(h2!=NULL){
            curr->next=h2;
        }
        // and we return the ans ka next bcz ans is dummy node 
        return ans->next;
    }
    Node* mergeSort(Node* head) {
        //if head is null or head->next is null 
        // we return the head
        if(head==NULL || head->next==NULL)
        return head;
        
        Node* slow=head;
        Node*fast=head->next;
        
        //we divide the list into two part from mid using 
        // slow amd fast pointer 
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       
       //second node will be slow ka next 
        Node* headb=slow->next;
        slow->next=NULL;
        
        //then we again call them on recursive 
        // to sort the divided array 
        Node* l1=mergeSort(head);
        Node* l2=mergeSort(headb);
        
        // the we merge both the sorted array 
        return mergelist(l1,l2);
    }
};
