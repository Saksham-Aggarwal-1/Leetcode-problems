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
    bool check_palin(vector<int> arr)
    {
        int n = arr.size();
        for(int i=0;i<n/2;i++)
        {
            if(arr[i] != arr[n-i-1])
                return false;
        }
        
        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(head)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        
        return check_palin(arr);
    }
};