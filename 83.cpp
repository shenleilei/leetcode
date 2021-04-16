class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            auto h = head;
            while(h)
            {
                if(h->next == nullptr)
                {
                    break;
                }
                
                auto next = h->next;
                while(next && next->val == h->val)
                {
                    next = next->next;
                }

                h->next = next;
                h = next;
            }

            return head;
                
        }
        
};
