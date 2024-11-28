#include <iostream>
#include <vector>

int main()
{
    int length;
    std::cin >> length;

    std::cout << "Input Length: " << length << std::endl;
    std::cout << "Please Input Element " << std::endl;

    std::vector<int> nums;
    std::vector<int> presum;

    int pre = 0;
    for (size_t i = 0; i < length; i++)
    {
        int in;
        std::cin >> in;
        nums.push_back(in);
        presum.push_back(pre + in);
        pre += in;
    }

    std::cout << "Please Input Range " << std::endl;

    while (true)
    {
        int start, end;
        std::cin >> start;
        std::cin >> end;

        int sum = 0;
        if (start == 0)
            sum = presum[end];
        else
            sum = presum[end] - presum[start - 1];

        // int sum = 0;
        // for (size_t i = start; i <= end; i++)
        // {
        //     sum += nums[i];
        // }

        std::cout << "Range [" << start << " " << end << "]" << std::endl;
        std::cout << "Sum: " << sum << std::endl;
    }

    return 0;
}