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
    bool isPalindrome(ListNode* head) {
        //total travesal while getting elements out of the stack
        
        stack<int> st;
        
        ListNode* start = head;
        
        while(start)
        {
            st.push(start->val);
            
            start = start->next;
        }
        
        while(head)
        {
            if(st.top()!=head->val)
            {
                return false;
            }
            st.pop();
                
            head = head->next;
        }
        
        return true;
    }
};