'''
93. 复原 IP 地址
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

93. Restore IP Addresses
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

'''
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n=len(s)
        if n<4:
            return []
        result=[]
        self.dfs(s,0,'',result)
        return result
        
    def dfs(self,s,count,st,result):
        if count>4:
            return
        
        if count==4 and s=='':
            result.append(st[:-1])
            return 
        
        n=len(s)
        for i in range(n):
            if s[0]!='0' and 0<int(s[:i+1])<=255:
                self.dfs(s[i+1:],count+1,st+s[:i+1]+'.',result)
            elif s[:i+1]=='0':
                self.dfs(s[i+1:],count+1,st+s[:i+1]+'.',result)
            