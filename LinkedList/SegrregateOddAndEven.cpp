/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* tail=head;
    ListNode* temp=head;
    int cnt=1;
    while (tail->next != NULL) {
      tail = tail->next;
      cnt++;
    }
    int i=1;
    while(i<=cnt){
        if(i%2==0){
            ListNode* newNode = new ListNode(temp->val);
            tail->next=newNode;
            tail=tail->next;
            temp->val=temp->next->val;
            temp->next=temp->next->next;

        } 
        else {
            temp = temp->next;
        }
         i++;
    }
    return head;
    }
};