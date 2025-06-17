#include <iostream>
#include <vector>

std::vector<std::vector<std::string>> result;
std::vector<std::string> path;

bool is_palindrome(const std::string &s, int start, int end)
{
    // 当 start == end 的时候直接不进行for循环，返回true
    for (size_t i = start, j = end; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }

    return true;
}

void backtring(std::string str, int start_index)
{
    if (start_index >= str.size())
    {
        result.push_back(path);
        return;
    }

    if (str.empty())
        return;

    for (size_t i = start_index; i < str.size(); ++i)
    {
        // 判断str是否是回文
        if (is_palindrome(str, start_index, i))
        {
            std::string s = s.substr(start_index, i - start_index + 1);
            path.push_back(s);
        }
        else
        {
            continue;
        }

        backtring(str, i + 1);
        path.pop_back();
    }
}

bool is_palindromev2(const std::string str, int start, int end)
{

    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

void backtringv2(std::string str, int start_index)
{
    if (start_index == str.size())
    {
        result.push_back(path);
        return;
    }

    for (int i = start_index; i < str.size(); i++)
    {
        // 判断当前区间是否是回文子串
        if (is_palindromev2(str, start_index, i))
        {
            // 记录当前的回文子串
            std::string sub_str = str.substr(start_index, i - start_index + 1);
            path.push_back(sub_str);

            // 判断剩下的部分
            backtringv2(str, i + 1);

            path.pop_back();
        }
    }
}

void computePalindrome(const std::string &s)
{
    // 确认下标含义
    // 包含i，j 元素的，[i,j] 子串是否为回文子串
    std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));

    // DP公式
    // dp[i][j]
    // if(i == j)   // 只有一个元素
    //  dp[i][j] = true;
    // if(j-i == 1 && s[i] == s[j]) // 只有两个元素且相等
    //  dp[i][j] = true;
    // if(s[i] == s[j] && dp[i+1] == dp[j-1]) // 多个元素
    //  dp[i][j] = true

    // 初始化
    // 全为false即可

    // 遍历顺序
    // dp[i][j] 依赖于 dp[i+1][j-1]
    // 因此 i的遍历顺序为从大到小， j为从小到大, 且j>=i, 因为j是右界限

    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (i == j)
            {
                dp[i][j] = true;
            }
            else if (j - i == 1 && s[i] == s[j])
            {
                dp[i][j] = true;
            }
            else if (s[i] == s[j] && dp[i + 1] == dp[j - 1])
            {
                dp[i][j] = true;
            }
        }
    }
}

using namespace std;
vector<vector<string>> partition(string s)
{
    if (s.empty())
        return result;
    backtringv2(s, 0);
    return result;
}

int main()
{

    std::string s = "aab";

    backtring(s, 0);

    return 0;
}