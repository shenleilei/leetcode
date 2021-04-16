/*
 * in: 1->4->3->2->5->2
 * out: 1->2->2->4->3->5 
 * */


class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode* smallHead = new ListNode(-1);
            ListNode* bigHead = new ListNode(-1);

            auto small = smallHead;
            auto big = bigHead;

            while(head)
            {
                if(head->val < x)
                {
                    small->next = head;
                    small = small->next;
                }
                else
                {
                    big->next = head;
                    big = big->next;
                }

                head = head->next;
            }

            big->next = nullptr;
            small->next = bigHead->next;

            return smallHead->next;
        }

};
