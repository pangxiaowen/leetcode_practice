# Day_24

## 93.复原IP地址

### 题目
```
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。
示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
```

### 思路：

1. 判断分割出来的字符是否合法，合法再进行下一步。

2. 由于输出是添加了'.'后的结果，因此在递归的过程中要插入'.'，会导致str长度变化

3. 注意字符串插入和删除的方式

   ```
   str.insert(str.begin() + i + 1, ',');
   // TODO
   str.erase(str.begin() + i + 1); // 迭代器删除

   str.erase(i+1) // 删除i+1后面所有的字符
   ```

4. 终止条件，分隔符插入三个就到了结束部分，判断后续的部分是否满足要求即可。



## 78.子集

### 题目

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例: 输入: nums = [1,2,3] 输出: [ [3],  [1],  [2],  [1,2,3],  [1,3],  [2,3],  [1,2],  [] ]

### 思路

1. 如果排列与组合问题，是求回溯树的叶子节点，那么子集问题就是求回溯树的节点问题，遍历所有节点。
2. 结果的存储位置，空节点也需要存储。

## 子集II

### 题目

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

    输入: [1,2,2]
    输出: [ [2], [1], [1,2,2], [2,2], [1,2], [] ]

### 思路

1. 包含重复元素，且解集中不能包含重复的子集， ---> 需要去重 --> 首先需要排序。
2. 去重的方法，如果将回溯理解为一个树，去重就是在层这个部分进行的。
   ```
   if( i > begin && nums[i] == nums[i-1])
      continue;
   ```
3. 使用used进行去重

   ```
   if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
   {
      continue;
   }
   ```





