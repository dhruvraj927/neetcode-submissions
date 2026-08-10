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
 
    ListNode* reverseList(ListNode* head) {
       
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* t1 = nullptr;
       
        ListNode* t2 = head;
        ListNode* dummy=head->next;
        while(dummy){
            t2->next=t1;
            t1=t2;
            t2=dummy;
            dummy=dummy->next;
        }
        t2->next=t1;
        return t2;


    }
};
