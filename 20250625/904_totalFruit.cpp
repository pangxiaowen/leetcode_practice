#include <map>
#include <set>
#include <unordered_map>
#include <vector>
// 你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i]
// 是第 i 棵树上的水果 种类 。

// 你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：
// 你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
// 你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果
// 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
// 一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。

// 给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。

// 输入：fruits = [0,1,2,2]
// 输出：3
// 解释：可以采摘 [1,2,2] 这三棵树。
// 如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。

// 滑动窗口
// 求窗口的最大长度
// 窗口内部水果的种类不能超过两种

int totalFruit(std::vector<int> &fruits)
{
    int result = 0;
    int start = 0;
    std::unordered_map<int, int> cache; // {水果种类, 最后一次出现的位置}
    for (int i = 0; i < fruits.size(); i++)
    {
        cache[fruits[i]]++;
        while (cache.size() > 2)
        {
            auto it = cache.find(fruits[start]);
            it->second--;
            if (it->second == 0)
            {
                cache.erase(it);
            }
            ++start;
        }
        result = std::max(result, i - start + 1);
    }

    return result;
}