// 1. we put all the node in the vector ans then we sort the vector and then again we put the element in the listnode and return the list node
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& l) {
        vector<int>arr;
        
        for(int i=0;i<l.size();i++){
            ListNode* curr=l[i];
                while(curr!=NULL)
                {
                    arr.push_back(curr->val);
                    curr=curr->next;
                }
        }
        sort(arr.begin(),arr.end());
      if(arr.size()==0){
          return NULL;
      }
       ListNode* dummy=new ListNode(0);
       ListNode* currd=dummy;
       
       for(int i=0;i<arr.size();i++){
     ListNode* nn=new ListNode(arr[i]);
         currd->next=nn;
         currd=currd->next;
       }
       return dummy->next;
    }
};

//second approach using priority queue 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& l) {
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<l.size();i++){
            ListNode* curr=l[i];
                while(curr!=NULL)
                {
                    pq.push(curr->val);
                    curr=curr->next;
                }
        }
        
      if(pq.size()==0){
          return NULL;
      }
       ListNode* dummy=new ListNode(0);
       ListNode* currd=dummy;
       
       while(pq.size()>0){
     ListNode* nn=new ListNode(pq.top());
         pq.pop();
         currd->next=nn;
         currd=currd->next;
       }
       return dummy->next;
    }
};

//third approach Divide and conquer

class Solution {
public:
     ListNode* mergeList(ListNode* h1,ListNode* h2){
             if(h1==NULL || h2==NULL)
             return (h1==NULL)?h2:h1;

             ListNode* ans=new ListNode(0);
             ListNode* curr=ans;

             while(h1!=NULL && h2!=NULL){
                 if(h1->val<h2->val){
                     curr->next=h1;
                     h1=h1->next;
                 }
                 else{
                  curr->next=h2;
                  h2=h2->next;
                 }
                 curr=curr->next;
             }
             if(h1!=NULL){
                 curr->next=h1;
             }
             if(h2!=NULL){
                 curr->next=h2;
             }
         return ans->next;
     }
    ListNode* mergeKLists(vector<ListNode*>&l) {
        ListNode* head=NULL;
        for(int i=0;i<l.size();i++){
       head=mergeList(head,l[i]);
        }
        return head;
    }
};
