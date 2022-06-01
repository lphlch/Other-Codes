'''
365. 水壶问题
有两个水壶，容量分别为 jug1Capacity 和 jug2Capacity 升。水的供应是无限的。确定是否有可能使用这两个壶准确得到 targetCapacity 升。

如果可以得到 targetCapacity 升水，最后请用以上水壶中的一或两个来盛放取得的 targetCapacity 升水。

你可以：

装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空

365. Water and Jug Problem
You are given two jugs with capacities jug1Capacity and jug2Capacity liters. There is an infinite amount of water supply available. Determine whether it is possible to measure exactly targetCapacity liters using these two jugs.

If targetCapacity liters of water are measurable, you must have targetCapacity liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full, or the first jug itself is empty.
'''



from queue import Queue


class Solution:
    def canMeasureWater(self, jug1Capacity: int, jug2Capacity: int, targetCapacity: int) -> bool:
        q=Queue()
        checked=set()
        q.put((0,0))
        checked.add((0,0))
        
        while not q.empty():
            jug1,jug2=q.get()
            if jug1==targetCapacity or jug2==targetCapacity or jug1+jug2==targetCapacity:
                return True
            else:
                children=[(jug1,jug2Capacity),(jug1Capacity,jug2),(0,jug2),(jug1,0)]
                
                if jug1+jug2>=jug1Capacity:
                    children.append((jug1Capacity,jug1+jug2-jug1Capacity))
                else:
                    children.append((jug1+jug2,0))
                
                if jug1+jug2>=jug2Capacity:
                    children.append((jug1+jug2-jug2Capacity,jug2Capacity))
                else:
                    children.append((0,jug1+jug2))
                    
                for child in children:
                    if child not in checked:
                        q.put(child)
                        checked.add(child)
        
        return False