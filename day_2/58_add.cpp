#include <iostream>
#include <vector>

void add_v1()
{
    std::vector<int> vec;

    int n;
    std::cin >> n;

    while (n--)
    {
        int num;
        std::cin >> num;
        vec.push_back(num);
    }

    int l, r;
    std::cin >> l;
    std::cin >> r;

    int sum = 0;
    for (size_t i = l; i < r; i++)
    {
        sum += vec[i];
    }

    std::cout << sum << std::endl;
}

void add_v2()
{
    std::vector<int> vec(1, 0);

    int n;
    std::cin >> n;

    for (size_t i = 1; i < n + 1; i++)
    {
        int num;
        std::cin >> num;
        vec.push_back(vec[i - 1] + num);
    }

    int l, r;
    std::cin >> l;
    std::cin >> r;

    std::cout << vec[r + 1] - vec[l] << std::endl;
}

int main()
{
    add_v2();

    return 0;
}