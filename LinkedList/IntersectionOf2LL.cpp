/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
    if(l1==NULL||l2==NULL) return NULL;
    ListNode* d1=l1;
    ListNode* d2=l2;
    while(d1!=d2){
      d1=d1==NULL?l2:d1->next;
      d2=d2==NULL?l1:d2->next;
    }
    return d1;
    }
};