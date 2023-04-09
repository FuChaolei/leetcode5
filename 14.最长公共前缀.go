/*
 * @lc app=leetcode.cn id=14 lang=golang
 *
 * [14] 最长公共前缀
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (42.84%)
 * Likes:    2409
 * Dislikes: 0
 * Total Accepted:    916.9K
 * Total Submissions: 2.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 *
 *
 * 示例 2：
 *
 *
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
func longestCommonPrefix(strs []string) string {
	n := len(strs)
	res := ""
	if n == 0 {
		return res
	}
	for i := 0; i < len(strs[0]); i++ {
		c := strs[0][i]
		for j := 0; j < len(strs); j++ {
			if i >= len(strs[j]) || strs[j][i] != c {
				return res
			}
		}
		res += string(c)
	}
	return res
}

// @lc code=end

