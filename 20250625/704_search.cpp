#include <vector>

int BinSearch(std::vector<int> &nums, const int &target, int start, int end)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;
    if (nums[mid] == target)
        return mid;
    if (nums[mid] < target)
        return BinSearch(nums, target, mid + 1, end);
    if (nums[mid] > target)
        return BinSearch(nums, target, start, mid - 1);
    return -1;
}

int search(std::vector<int> &nums, int target)
{
    return BinSearch(nums, target, 0, nums.size() - 1);
}

int searchv2(std::vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            start = mid + 1;
        if (nums[mid] > target)
            end = mid - 1;
    }

    return -1;
}