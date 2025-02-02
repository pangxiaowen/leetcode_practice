# 93.复原IP地址

```
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。
示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
```

### 思路：

字符串分割任务， 穷举所有可能性，使用穷举的一般使用回溯的方式，个人理解就是for循环的另外一种形式，由于循环层数不确定，因此该用递归的方式进行编程。

### 要点：

1. 判断分割出来的字符是否合法，合法再进行下一步。

2. 由于输出是添加了'.'后的结果，因此在递归的过程中要插入'.'，会导致str长度变化

3. 注意字符串插入和删除的方式

   ```
   str.insert(str.begin() + i + 1, ',');
   str.erase(str.begin() + i + 1);
   
   str.erase(i+1) // 删除i+1后面所有的字符
   ```

4. 终止条件，分隔符插入三个就到了结束部分，判断后续的部分是否满足要求即可。



# 78.子集

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例: 输入: nums = [1,2,3] 输出: [ [3],  [1],  [2],  [1,2,3],  [1,3],  [2,3],  [1,2],  [] ]

### 思路

如果排列与组合问题，是求回溯树的叶子节点，那么子集问题就是求回溯树的节点问题，遍历所有节点。

### 要点

1. 结果的存储位置，空节点也需要存储。





