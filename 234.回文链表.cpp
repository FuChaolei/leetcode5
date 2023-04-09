/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (52.33%)
 * Likes:    1483
 * Dislikes: 0
 * Total Accepted:    490.2K
 * Total Submissions: 936.6K
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,2,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 *
 *
 *
 *
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 *
 */

// @lc code=start
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
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }
        ListNode *l1 = head, *l2 = head;
        while (l2->next && l2->next->next)
        {
            l1 = l1->next;
            l2 = l2->next->next;
        }
        ListNode *pre = l1, *cur = l1->next;
        while (cur && cur->next)
        {
            ListNode *tail = cur->next;
            cur->next = tail->next;
            tail->next = pre->next;
            pre->next = tail;
        }
        cur = pre->next;
        while (cur)
        {
            if (cur->val != head->val)
            {
                return false;
            }
            cur = cur->next;
            head = head->next;
        }
        return true;
    }
};
// @lc code=end
