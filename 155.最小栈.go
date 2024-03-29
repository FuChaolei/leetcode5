/*
 * @lc app=leetcode.cn id=155 lang=golang
 *
 * [155] 最小栈
 *
 * https://leetcode.cn/problems/min-stack/description/
 *
 * algorithms
 * Medium (58.55%)
 * Likes:    1385
 * Dislikes: 0
 * Total Accepted:    416.6K
 * Total Submissions: 711.5K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 *
 * 实现 MinStack 类:
 *
 *
 * MinStack() 初始化堆栈对象。
 * void push(int val) 将元素val推入堆栈。
 * void pop() 删除堆栈顶部的元素。
 * int top() 获取堆栈顶部的元素。
 * int getMin() 获取堆栈中的最小元素。
 *
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 *
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 *
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 *
 *
 *
 *
 * 提示：
 *
 *
 * -2^31 <= val <= 2^31 - 1
 * pop、top 和 getMin 操作总是在 非空栈 上调用
 * push, pop, top, and getMin最多被调用 3 * 10^4 次
 *
 *
*/

// @lc code=start
type pair struct {
	first, second int
}
type MinStack struct {
	st []pair
}

func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(val int) {
	tmp := pair{
		first:  val,
		second: val,
	}
	if len(this.st) == 0 {
		this.st = append(this.st, tmp)
		fmt.Println(tmp.second)
		return
	}
	top := this.st[len(this.st)-1].second
	if top < val {
		tmp.second = top
	}
	this.st = append(this.st, tmp)
}

func (this *MinStack) Pop() {
	this.st = this.st[:len(this.st)-1]
}

func (this *MinStack) Top() int {
	top := this.st[len(this.st)-1].first
	return top
}

func (this *MinStack) GetMin() int {
	top := this.st[len(this.st)-1].second
	return top
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
// @lc code=end

