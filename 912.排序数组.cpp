/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (56.57%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    211.9K
 * Total Submissions: 375.1K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        srand(time(NULL));
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void qsort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
        {
            return;
        }
        int tmp = rand() % (r - l + 1) + l;
        swap(nums[l], nums[tmp]);
        int x = l, y = r;
        int t = nums[l];
        int i = l + 1;
        while (i <= y)
        {
            if (nums[i] < t)
            {
                swap(nums[i], nums[x]);
                i++;
                x++;
            }
            else if (nums[i] == t)
            {
                i++;
            }
            else
            {
                swap(nums[i], nums[y]);
                y--;
            }
        }
        qsort(nums, l, x - 1);
        qsort(nums, y + 1, r);
    }
};
// @lc code=end
