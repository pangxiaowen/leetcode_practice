#include <algorithm>
#include <iterator>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出
// s 则返回 true。

// 转化为完全背包问题
// 构成s的子串是否再字典中出现。
// 也就是从字典中选取若干个单词，使得它们的拼接结果等于 s，且个数不限。

// 下标含义
// dp[j] 的含义是字符串长度为 j 的子串是否可以被拆分成字典中的单词。

// DP 公式
// dp[j] = dp[j-i] & dp[i]，其中 i 是字典中单词的长度。

// 初始化
// dp[0] = true，表示空字符串可以被拆分。

bool wordBreak_(std::string s, std::vector<std::string> &wordDict)
{
    // dp[j] : 字符串长度为j的话，dp[j]为true，表示可以拆分为一个或多个在字典中出现的单词。
    // 如果dp[j] 能被拆分， 那么一定存在dp[i] 为true 且 dp[j-i]为true
    // dp[j] = dp[i] && dp[j-i]

    // 本题对顺序有要求，不能随意打乱
    // 先遍历背包，再遍历物品

    std::unordered_set<std::string> word_set(wordDict.begin(), wordDict.end());
    std::vector<int> dp(s.size() + 1, 0);
    dp[0] = true;

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::string word = s.substr(j, i - j);
            if (word_set.find(word) != word_set.end() && dp[j])
            {
                dp[i] = true;
            }
        }
    }

    return dp[s.size()];
}

// 回溯
bool backTracking(std::string &s, std::vector<std::string> &wordDict, std::vector<bool> &cache,
                  int start)
{
    if (start == s.size())
        return true;

    if (!cache[start])
        return cache[start];

    for (int i = start; i < s.size(); i++)
    {
        auto sub_str = s.substr(start, i - start + 1);

        if (std::find(std::begin(wordDict), std::end(wordDict), sub_str) != std::end(wordDict))
        {
            if (backTracking(s, wordDict, cache, i + 1))
            {
                return true;
            }
        }
    }

    cache[start] = false;
    return false;
}

bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    // dp[j] : 字符串长度为j的话，dp[j]为true，表示可以拆分为一个或多个在字典中出现的单词。
    // 如果dp[j] 能被拆分， 那么一定存在dp[i] 为true 且 dp[j-i]为true
    // dp[j] = dp[i] && dp[j-i]

    std::unordered_set<std::string> word_set(wordDict.begin(), wordDict.end());
    std::vector<int> dp(s.size() + 1, 0);
    dp[0] = true;

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::string word = s.substr(j, i - j);
            if (word_set.find(word) != word_set.end() && dp[j])
            {
                dp[i] = true;
            }
        }
    }

    return dp[s.size()];
}