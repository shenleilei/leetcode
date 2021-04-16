class Solution {
    public:
        ListNode* getMid(ListNode* head)
        {
            auto p = head;
            head = head->next;
            while(head && head->next)
            {
                p = p->next;
                head = head->next->next;
            }

            return p;
        }

        ListNode* sortList(ListNode* head) {
            if(head == nullptr || head->next == nullptr)
            {
                return head;
            }

            ListNode* mid = getMid(head);   
            auto right = mid->next;
            mid->next = nullptr;

            auto l = sortList(head);
            auto r = sortList(r);
            return merge(l, r);
        }

        ListNode* merge(ListNode* l, ListNode* r)
        {
            ListNode* head = new ListNode();
            auto p = head;

            while(l && r)
            {
                if(l->val < r->val)
                {
                    head->next = l;
                    l = l->next;
                }
                else
                {
                    head->next = r;
                    r = r->next;
                }

                head = head->next;
            }

            if(l)
            {
                head->next = l;
            }
            if(r)
            {
                head->next = r;
            }

            return p->next;
        }


        
};
