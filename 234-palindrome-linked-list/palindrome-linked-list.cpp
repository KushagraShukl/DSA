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
    ListNode* revLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* n = NULL;

        while(cur){
            n = cur->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }

        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = revLL(slow->next);

        ListNode *c1 = head, *c2 = newHead;

        while(c2){
            if(c1->val != c2->val){
                slow->next = revLL(newHead);
                return false;
            }
            c1 = c1->next;
            c2 = c2->next;
        }

        slow->next = revLL(newHead);
        return true;

        
    }
};