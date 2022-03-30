/*
剑指 Offer 59 - II. 队列的最大值
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1
*/
class MaxQueue {
	queue<int> numQ;
	deque<int> maxQ;
public:
	MaxQueue() {
	}

	int max_value() {
		if (numQ.empty())
		{
			return -1;
		}
		else
		{
			return maxQ.front();
		}
	}

	void push_back(int value) {
		int m = value;
		numQ.push(m);
		while (!maxQ.empty() && maxQ.back() <= m)
		{
			maxQ.pop_back();
		}
		maxQ.push_back(m);
	}

	int pop_front() {
		if (numQ.empty())
		{
			return -1;
		}
		else
		{
			int dequeueNum = numQ.front();
			numQ.pop();
			if (dequeueNum == maxQ.front())
			{
				maxQ.pop_front();
			}
			return dequeueNum;
		}
	}
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */