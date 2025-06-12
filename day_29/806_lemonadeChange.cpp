#include <vector>

bool lemonadeChange(std::vector<int> &bills)
{
    int five = 0;
    int ten = 0;

    for (auto it : bills)
    {
        if (it == 5)
            five++;

        if (it == 10)
        {
            five--;
            ten++;
        }
        if (it == 20)
        {
            if (ten > 0)
            {
                ten--;
                five--;
            }
            else
            {
                five = five - 3;
            }
        }

        if (five < 0)
        {
            return false;
        }
    }

    return true;
}

bool lemonadeChangev2(std::vector<int> &bills)
{
    int five_count = 0;
    int ten_count = 0;

    for (auto it : bills)
    {
        if (it == 5)
        {
            five_count++;
        }
        else if (it == 10)
        {
            five_count--;
            ten_count++;
        }
        else if (it == 20)
        {
            if (ten_count > 0)
            {
                ten_count--;
                five_count--;
            }
            else
            {
                five_count -= 3;
            }
        }

        if (five_count < 0 || ten_count < 0)
        {
            return false;
        }
    }

    return true;
}