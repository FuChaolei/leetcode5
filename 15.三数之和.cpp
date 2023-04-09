/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (33.42%)
 * Likes:    3738
 * Dislikes: 0
 * Total Accepted:    638.8K
 * Total Submissions: 1.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^5
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size();
        vector<vector<int>> res;
        while (l < r)
        {
            if (l && nums[l - 1] == nums[l])
            {
                l++;
                continue;
            }
            int x = l + 1, y = r - 1;
            int t = -nums[l];
            while (x < y)
            {
                if (nums[x] + nums[y] == t)
                {
                    res.push_back({nums[l], nums[x], nums[y]});
                    while (x < y && nums[x] == nums[x + 1])
                    {
                        x++;
                    }
                    while (x < y && nums[y] == nums[y - 1])
                    {
                        y--;
                    }
                    x++;
                    y--;
                }
                else if (nums[x] + nums[y] < t)
                {
                    x++;
                }
                else
                {
                    y--;
                }
            }
            l++;
        }
        return res;
    }
};
// @lc code=end
