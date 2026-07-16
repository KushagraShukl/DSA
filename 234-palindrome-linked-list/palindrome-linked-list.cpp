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
        vector<int> l;
        ListNode* curr = head;
        while(curr){
            l.push_back(curr->val);
            curr = curr->next;
        }
        for(int i = 0 ; i<l.size(); i++){
            if (l[i] != l[l.size() - i - 1]) return false;
        }
        return true;
    }
};