## 209.长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

### 思路

1. 对于求连续的子数组是否满足什么条件， 采用滑动窗口的方式进行实现。右部加入元素，然后判断是否满足条件，如果不满足，则将左边的元素删除，知道余下的子数组满足条件为止。

2. 求最小的时候， 需要初始化一个最大的结果， int i = INT32_MAX;

3. 使用滑动窗口的时候，需要确定窗口内是什么？如何移动窗口的起始位置？如何移动窗口的终止位置？

## 59. 螺旋矩阵 II

给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

### 思路

1. 正方形矩阵，对于每一圈， 处理 n - offset个值, 方便循环处理。
2. 终止条件是什么？ n / 2 --> 计算出需要循环多少圈。
3. 对于特殊情况如何处理， 中心点只有一个值的时候， 即n是奇数的时候。

## 58. 区间和

给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。

### 思路

1. 一般做法，记录每个输入的值， 给定区间后进行for循环相加。但是此时计算量比较大。可以考虑在输入的时候做一些预计算，如前缀和。
2. 前缀和 在涉及计算区间和的问题时非常有用！ 在输入的时候顺便进行前缀和的计算， 然后通过前缀和计算区间和问题。

## 44. 开发商购买土地

在一个城市区域内，被划分成了n * m个连续的区块，每个区块都拥有不同的权值，代表着其土地价值。目前，有两家开发公司，A 公司和 B 公司，希望购买这个城市区域的土地。

现在，需要将这个城市区域的所有区块分配给 A 公司和 B 公司。

然而，由于城市规划的限制，只允许将区域按横向或纵向划分成两个子区域，而且每个子区域都必须包含一个或多个区块。

为了确保公平竞争，你需要找到一种分配方式，使得 A 公司和 B 公司各自的子区域内的土地总价值之差最小。

注意：区块不可再分。

### 思路

1. 暴力解法, 考虑横竖的所有情况， 寻找最小的分配方式。
2. 构建暴力解法的过程中，我们能够发现， 计算了很多次横向或者纵向的和，那我们可以考虑预计算这部分和，将横向划分和纵向划分分开考虑。
3. 总价值是可以预先计算出来的，如果遇到切分问题，一定要注意，总量是很好计算的，记得要计算总量。
