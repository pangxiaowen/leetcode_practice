#include <iostream>
#include <vector>

int bin_search(const std::vector<int> &vec, int target)
{
    // 左闭右开
    int left = 0;
    int right = vec.size();

    while (left < right) // left == right是没有意义的
    {
        int mid = left + (right - left) / 2;

        if (vec[mid] < target)
        {
            left = mid + 1;
        }
        else if (vec[mid] > target)
        {
            right = mid;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int bin_search_v2(const std::vector<int> &vec, int target)
{
    // 左闭右闭
    int left = 0;
    int right = vec.size() - 1;
    while (left <= right) // left == right 是能够取到值的
    {
        int mid = left + (right - left) / 2; // 求中点的索引

        if (vec[mid] > target) // target在左区间
        {
            right = mid - 1;
        }
        else if (vec[mid] < target) // target在右区间
        {
            left = mid + 1;
        }
        else if (vec[mid] == target)
        {
            return mid;
        }
    }

    return -1;
}

int bin_search_v3(std::vector<int> &vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (vec[mid] == target)
        {
            return mid;
        }
        else if (vec[mid] < target)
        {
            left = mid + 1;
        }
        else if (vec[mid] > target)
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> vec{-1, 0, 3, 5, 9, 12};

    {
        int index = bin_search(vec, 9);
        std::cout << index << std::endl;
    }
    {
        int index = bin_search_v2(vec, 9);
        std::cout << index << std::endl;
    }

    return 0;
}