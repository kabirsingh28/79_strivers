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
    
ListNode* SortedMerge(ListNode* a, ListNode* b)
{
    ListNode* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->val <= b->val) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

ListNode* sortList(ListNode* head){
    if(head==NULL || head->next==NULL) return head;

    ListNode* temp=NULL;
    ListNode* slow=head;
    ListNode* fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }

    temp->next=NULL;

    ListNode* l1=sortList(head);
    ListNode* l2=sortList(slow);

    return SortedMerge(l1,l2);
}
};