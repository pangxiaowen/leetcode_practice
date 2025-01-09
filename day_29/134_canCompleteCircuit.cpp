#include <iostream>
#include <numeric>
#include <stdint.h>
#include <vector>

int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
{
    for (int i = 0; i < gas.size(); i++)
    {
        int res = gas[i] - cost[i];
        int next = (i + 1) % gas.size();
        while (res > 0 && next != i)
        {
            res = res + gas[next] - cost[next];
            next = (next + 1) % gas.size();
        }

        if (res >= 0 && next == i)
        {
            return i;
        }
    }

    return -1;
}

int canCompleteCircuit_v2(std::vector<int> &gas, std::vector<int> &cost)
{
    int curSum = 0;
    int min = INT_MAX;

    for (int i = 0; i < gas.size(); ++i)
    {
        int res = gas[i] - cost[i];
        curSum += res;
        if (curSum < min)
        {
            min = curSum;
        }
    }

    if (curSum < 0)
        return -1;
    if (min >= 0)
        return 0;

    for (int i = gas.size() - 1; i >= 0; --i)
    {
        int res = gas[i] - cost[i];
        min += res;
        if (min >= 0)
        {
            return i;
        }
    }

    return -1;
}

int canCompleteCircuit_v3(std::vector<int> &gas, std::vector<int> &cost)
{
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); ++i)
    {
        curSum += gas[i] - cost[i];
        totalSum += gas[i] - cost[i];

        if (curSum < 0)
        {
            start = i + 1;
            curSum = 0;
        }
    }

    if (totalSum < 0)
        return -1;
    return -1;
}

int main()
{
    std::vector<int> gas{1, 2, 3, 4, 5};
    std::vector<int> cost{3, 4, 5, 1, 2};

    std::cout << canCompleteCircuit(gas, cost) << std::endl;
}