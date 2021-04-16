class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            
        }

        void mergeKList(vector<ListNode*> & lists, int from, int to)
        {
            if(from == to)
            {
                return;
            }

            int mid = (from + to) / 2;

            mergeKList(lists, from, mid);
            mergeKList(lists, mid + 1, to);

            merge(lists, from, to);
        }

        void merge(vector<>)


        
};
