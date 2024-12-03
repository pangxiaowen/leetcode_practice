#include <iostream>
#include <unordered_set>

int get_sum(int x)
{
    int res = 0;
    while (x)
    {
        res = res + (x % 10) * (x % 10);
        x = x / 10;
    }

    return res;
}

bool is_happy(int x)
{
    std::unordered_set<int> cache;

    while (true)
    {
        x = get_sum(x);
        if (cache.find(x) != cache.end())
        {
            return false;
        }
        else
        {
            cache.insert(x);
        }

        if (x == 1)
        {
            return true;
        }
    }
}

int main()
{
    int x = 19;
    std::cout << is_happy(x) << std::endl;
}