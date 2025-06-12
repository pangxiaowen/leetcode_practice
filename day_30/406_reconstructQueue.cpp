#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

// 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个
// people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

// 请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j]
// = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

// 输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
// 输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

// [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]

// 先根据身高进行排序, 从大到小
// [7, 0] [7, 1] [6, 1] [5, 0] [5, 2] [4, 4]

// 然后根据k向前插入即可

static bool compare(const std::vector<int> &a, const std::vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    std::sort(std::begin(people), std::end(people), compare);

    std::vector<std::vector<int>> result;

    for (int index = 0; index < people.size(); index++)
    {
        // 这里的index可以理解为， 前面正好有 index 个身高大于或等于 hi 的人。
        int pos = people[index][1];
        result.insert(result.begin() + pos, people[index]);
    }

    return result;
}

int main()
{
    std::vector<std::vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};

    reconstructQueue(people);

    return 0;
}