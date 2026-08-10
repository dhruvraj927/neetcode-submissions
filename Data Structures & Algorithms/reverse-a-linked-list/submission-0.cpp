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
    void fun(ListNode*& t1,ListNode* t2,bool& cross){
        if(t2==nullptr) return;
        fun(t1,t2->next,cross);
        if(t1==t2 || t2->next==t1) {
            cross=true;
            return ;}
        if(cross) return;    
        int data=t1->val;
        t1->val=t2->val;
        t2->val=data;
        t1=t1->next;
    }
    ListNode* reverseList(ListNode* head) {
        int l=0;
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* temp = head;
        // while(temp->next){
        //     l++;
        //     temp=temp->next;
        // }
        ListNode* t2 = head;
        int i=0;
        bool cross=false;
        fun(temp,t2,cross);
        return head;

    }
};
