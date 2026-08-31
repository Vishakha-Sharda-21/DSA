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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, prev = -1;
        int mn = INT_MAX, mx = -1;
        int pos = 1;

        ListNode *a = head, *b = head->next;

        while (b && b->next) {
            if ((b->val > a->val && b->val > b->next->val) ||
                (b->val < a->val && b->val < b->next->val)) {

                if (first == -1)
                    first = pos;
                else {
                    mn = min(mn, pos - prev);
                    mx = pos - first;
                }

                prev = pos;
            }

            a = b;
            b = b->next;
            ++pos;
        }

        return {mn == INT_MAX ? -1 : mn, mx};
    }
};
