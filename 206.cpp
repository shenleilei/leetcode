class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if(!head || !head->next) return head;

            ListNode* hair = new ListNode(-1);
            hair->next = head;

            auto p = head->next;
            head->next = nullptr;
            while(p)
            {
                auto q = p->next;
                auto next = hair->next;
                hair->next = p;
                p->next = next;
                p = q;
            }

            return hair->next;
                
        }
        
};
