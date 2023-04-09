/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.71%)
 * Likes:    1288
 * Dislikes: 0
 * Total Accepted:    207.4K
 * Total Submissions: 310.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 *
 * 进阶：
 *
 *
 * 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 
 *
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
    ListNode *sortList(ListNode *head)
    {
        int l = 0;
        ListNode *tmp = head;
        while (tmp)
        {
            l++;
            tmp = tmp->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        for (int i = 1; i < l; i <<= 1)
        {
            ListNode *cur = dummy.next;
            ListNode *pre = &dummy;
            while (cur)
            {
                ListNode *left = cur;
                ListNode *right = mysplit(cur, i);
                cur = mysplit(right, i);
                auto merged = merge(left, right);
                pre->next = merged.first;
                pre = merged.second;
            }
        }
        return dummy.next;
    }
    pair<ListNode *, ListNode *> merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *pre = &dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                pre->next = l1;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        if (l1)
        {
            pre->next = l1;
        }
        if (l2)
        {
            pre->next = l2;
        }
        while (pre->next)
        {
            pre = pre->next;
        }
        return {dummy.next, pre};
    }
    ListNode *mysplit(ListNode *head, int l)
    {
        while (l > 1 && head != nullptr)
        {
            head = head->next;
            l--;
        }
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *res = head->next;
        head->next = nullptr;
        return res;
    }
};
// @lc code=end
