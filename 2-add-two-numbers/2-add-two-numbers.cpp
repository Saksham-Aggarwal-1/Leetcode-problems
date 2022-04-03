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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* res;
        ListNode* ans = new ListNode(0);
        res = ans;
        
        int carry = 0;
        while(ptr1 || ptr2)
        {
            int x = (ptr1 != NULL)? ptr1->val:0;
            int y = (ptr2 != NULL)? ptr2->val:0;
            int sum = (x+y+carry);
            carry = (sum)/10;
            
            ans->next = new ListNode(sum%10);
            if(ptr1) ptr1 = ptr1->next;
            if(ptr2) ptr2 = ptr2->next;
            ans = ans->next;
        }
        
        if(carry)
        {
            ans->next = new ListNode(carry);
            ans = ans->next;
            ans->next = NULL;
        }
        
        return res->next;
    }
};