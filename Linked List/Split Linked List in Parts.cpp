class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        ListNode* curr=head;
        int size=0;
        for(ListNode* curr=head;curr!=NULL;curr=curr->next){
            size++;
        }
     for(int i=0;i<k;i++)
     {
          if(curr==0)
          {
              ans.push_back(NULL);
              continue;
          }
          ans.push_back(curr);

          if(i<size%k)
          {
              for(int j=0;j<size/k;j++)
                  curr=curr->next;
                  ListNode* temp=curr->next;
                  curr->next=NULL;
                  curr=temp;
          }

          else
          {
              for(int j=0;j<size/k-1;j++)
                  curr=curr->next;
                  ListNode* temp=curr->next;
                  curr->next=NULL;
                  curr=temp;
          }
      }
   return ans;
    }
};
