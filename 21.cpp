class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            auto head = new ListNode();
            auto p = head;

            while(l1 && l2)
            {
                if(l1->val < l2->val)
                {
                    p->next = l1;
                }
                else
                {
                    p->next = l2;
                }

                p = p->next;
            }

            if(l1) p->next = l1;
            if(l2) p->next = l2;

            return head->next;
        
};
