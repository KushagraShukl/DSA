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
    ListNode* revList(ListNode* head){
        ListNode* p = NULL;
        ListNode* curr = head;
        ListNode* n = NULL;

        while(curr){
            n = curr->next;
            curr->next = p;
            p = curr;
            curr = n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = revList(slow->next);

        ListNode* c1 = head;
        ListNode* c2 = newHead;

        while(c2){
            if(c1->val != c2->val){
                slow->next = revList(newHead);
                return false;
            }
            c1 = c1->next;
            c2 = c2->next;
        }
        slow->next = revList(newHead);
        return true;

    }
};