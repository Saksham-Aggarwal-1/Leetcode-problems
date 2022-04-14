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
    int solve(vector<int> arr)
    {
        int ans = INT_MIN, n = arr.size();
        for(int i=0;i<n/2;i++)
        {
            ans = max(ans, arr[i]+arr[n-i-1]);
        }
        
        return ans;
    }
    
    int pairSum(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        return solve(arr);
    }
};