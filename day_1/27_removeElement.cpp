#include <iostream>
#include <vector>

int remove(std::vector<int> &vec, int target)
{
    for (auto it = vec.begin(); it != vec.end();)
    {
        if (*it == target)
        {
            it = vec.erase(it);
        }
        else
        {
            it++;
        }
    }

    return vec.size();
}

int remove_v2(std::vector<int> &vec, int target)
{
    int count = 0;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (vec[i] == target)
        {
            count = count + 1;
            for (size_t j = i; j < (vec.size() - count); ++j)
            {
                vec[j] = vec[j + 1];
            }
            vec[vec.size() - count] = 0;
            i--;
        }
    }
    return vec.size() - count;
}

int remove_v3(std::vector<int> &vec, int target)
{
    int size = vec.size();
    for (size_t i = 0; i < size; ++i)
    {
        if (vec[i] == target)
        {
            for (size_t j = i; j < size - 1; ++j)
            {
                vec[j] = vec[j + 1];
            }

            i--;
            size--;
        }
    }

    return size;
}

int remove_v4(std::vector<int> &vec, int target)
{
    int slow_ptr = 0;
    int fast_ptr = 0;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (vec[i] == target)
        {
            fast_ptr++;
            continue;
        }

        if (fast_ptr != slow_ptr)
        {
            vec[slow_ptr] = vec[fast_ptr];
        }

        fast_ptr++;
        slow_ptr++;
    }

    return slow_ptr;
}

int remove_5(std::vector<int> &vec, int target)
{
    int size = vec.size();
    for (size_t i = 0; i < size; ++i)
    {
        if (vec[i] == target)
        {
            vec[i] = vec[size - 1];
            i--;
            size--;
        }
    }
}

int main()
{
    std::vector<int> vec{0, 1, 2, 2, 3, 0, 4, 2};
    // std::cout << remove(vec, 2) << std::endl;
    // std::cout << remove_v2(vec, 2) << std::endl;
    // std::cout << remove_v3(vec, 2) << std::endl;
    // std::cout << remove_v4(vec, 2) << std::endl;
    std::cout << remove_v4(vec, 2) << std::endl;

    for (auto it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}