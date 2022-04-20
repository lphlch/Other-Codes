'''
630. 课程表 III
这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中 courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。

你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。

返回你最多可以修读的课程数目。

630. Course Schedule III
There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

You will start on the 1st day and you cannot take two or more courses simultaneously.

Return the maximum number of courses that you can take.
'''
class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        classInfo=sorted(courses,key=lambda x:x[1])
        n=len(classInfo)
        
        choose=[]
        now=0
        for duration,end in classInfo:
            heappush(choose,-duration)
            now=now+duration
            if now>end:
                now=now+heappop(choose)
                
        return len(choose)