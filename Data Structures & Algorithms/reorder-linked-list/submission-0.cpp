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
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        int size=0;
        ListNode* t=head;
        while(t!=nullptr){
            size++;
            st.push(t);
            t=t->next;
        }
        t=head;
        for(int i=0;i<size/2;i++){
            ListNode* fast=t->next;
            t->next=st.top();
            st.pop();
            t=t->next;
            t->next=fast;
            t=t->next;
        }
        t->next=nullptr;
    }
};
