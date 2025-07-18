# Day_25

## 递增子序列

### 题目

给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

示例:

    输入: [4, 6, 7, 7]
    输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

    输入：nums = [4,4,3,2,1]
    输出：[[4,4]]


### 思路

1. 该问题是组合，因此要避免元素相同的组合， 仍需要for(int i = begin; xxx; ++i)。
2. 整型数组不是有序的，之前有序的去重方式不能使用， 改用set/map进行去重。
3. 递增子序列，要求子序列，因此不能排序。

## 全排列

### 题目

给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

    输入: [1,2,3]
    输出: [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]

### 思路

1. 由于没有重复的数字，不用考虑去重的问题。
2. 在取得一个数字后， 将这个数字从集合中删除， 然后在剩下的集合中去选择新的数据。


## 全排列 II

### 题目

给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：

    输入：nums = [1,1,2]
    输出： [[1,1,2], [1,2,1], [2,1,1]]

### 思路

1. 相比上一个全排列，本题中会出现重复的元素，因此排列问题要考虑去重。如 nums = [ 1, 1, 2], 可以生成两个 [1, 1, 2] 的排序，就是两个1的顺序不同导致的。
2. 关于排列问题，先选取一个元素，然后再在剩下的元素中选取，为了避免在此复制剩下的元素，使用一个数组记录元素是否使用过更加友好。
3. 关于去重的问题，对于回溯问题，我们可以将其转为一个树型结构，因此考虑层去重 以及 枝去重。
    * 对元素进行排序, 层去重，可以使用set/map 去记录改层中有哪些元素被使用过。来达到去重的目的。
    * 对元素进行排序，使得重复的元素是连续存储的，我们可以使用nums[i-1] == nums[i] 来判断是否为重复的元素。此时 i需要大于0。
    由于[1, 1, 2] 这种情况是合法的， 我们不能仅仅使用nums[i-1] == nums[i]进行剪枝， 同时需要 used[i - 1] == false。判断他们是属于同一层的元素。
    或者used[i - 1] == true。判断他们是属于同一枝的元素。选择其中一个使用即可。

