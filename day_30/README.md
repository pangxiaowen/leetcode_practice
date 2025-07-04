## 根据身高重建队列

### 题目

假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

### 思路

1. 遇到有两个变化量的题目，先确定其中一个，再去考虑另外一个。
2. 首先根据身高进行排序，如果身高相同，则ki小的排在前面。
3. 此时身高的顺序已经确定，在考虑次序的问题。
4. 我们只要遍历排序后的升高，根据hi插入数组即可。


## 用最少数量的箭引爆气球

### 题目

在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。

一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。

### 思路

1. 每次射箭，尽可能多的射爆气球。
2. 按照xstart 进行排序，从小到大， 如果 end > points[i][xstart], 说明这两个气球可以同时被射爆炸
3. 更新end =  std::min(end, points[i][xend]), 两个气球可以同时被射爆炸的时候的end。


## 无重叠区间

### 题目

给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意: 可以认为区间的终点总是大于它的起点。 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

### 思路

1. 首先进行排序，按照终点进行排序

[1, 2], [1, 3], [2, 3], [3, 4]

[1, 3], [1, 2], [2, 3], [3, 4]

2. 判断前一个节点的start 是否小于当前节点的end，如果是true，则删除前一个节点。即删除范围更大的元素

## 划分字母区间

### 题目

字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8] 解释： 划分结果为 "ababcbaca", "defegde", "hijhklij"。 每个字母最多出现在一个片段中。 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

### 思路

1. 统计每一个字符最后出现的位置
2. 遍历字符串，同时记录遍历过的元素中最远出现的位置， 如果当前的位置等于最远的位置，则说明可以进行分段。因为遍历过的元素不会出现在段外。


