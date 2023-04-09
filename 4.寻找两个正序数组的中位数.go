/*
 * @lc app=leetcode.cn id=4 lang=golang
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (40.68%)
 * Likes:    4401
 * Dislikes: 0
 * Total Accepted:    482.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 *
 *
 * 示例 4：
 *
 *
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 *
 *
 * 示例 5：
 *
 *
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0
 * 0
 * 1
 * -10^6
 *
 *
 *
 *
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 *
 */

// @lc code=start
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	n1 := len(nums1)
	n2 := len(nums2)
	if n2 < n1 {
		return findMedianSortedArrays(nums2, nums1)
	}
	k := (n1 + n2 + 1) / 2
	l, r := 0, n1
	for l < r {
		mid1 := (r-l)/2 + l
		mid2 := k - mid1
		if nums2[mid2-1] > nums1[mid1] {
			l = mid1 + 1
		} else {
			r = mid1
		}
	}
	m1 := l
	m2 := k - l
	var l1, l2 int
	if m1 <= 0 {
		l1 = math.MinInt32
	} else {
		l1 = nums1[m1-1]
	}
	if m2 <= 0 {
		l2 = math.MinInt32
	} else {
		l2 = nums2[m2-1]
	}
	resl := max(l1, l2)
	if (n1+n2)%2 == 1 {
		return float64(resl)
	}
	var r1, r2 int
	if m1 >= n1 {
		r1 = math.MaxInt32
	} else {
		r1 = nums1[m1]
	}
	if m2 >= n2 {
		r2 = math.MaxInt32
	} else {
		r2 = nums2[m2]
	}
	resr := min(r1, r2)
	return float64(resl+resr) / 2.0
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end

