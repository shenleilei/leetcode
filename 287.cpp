// nums = [1,3,4,2,2]
/* 有如下映射关系
 * 0->1
 * 1->3
 * 3->2
 * 2->4
 * 4->2
 * 2->4
 * 4->2
 * 最终会形成一个0->1->3->2->4->2->4(2->4->2循环)循环链表，因此我们可以用求循环链表入口的办法来做这个题
*/

/* 不要关心是值，还是索引下标，全部看成是链表节点
 * */

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            auto fast = 0;
            auto slow = 0;
            do
            {
                fast = nums[nums[fast]];
                slow = nums[slow];
            }while(fast != slow)
            
            auto p = 0;
            while(slow != p)
            {
                p = nums[p];
                slow = nums[slow];
            }

            return p;
        }
        
};
