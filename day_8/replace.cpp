#include <iostream>
#include <string>

int cal_nums(std::string str)
{
    int count = 0;
    for (auto it : str)
    {
        if (it >= 'a' && it <= 'z')
        {
            continue;
        }

        count++;
    }

    return count;
}

std::string replace(std::string str)
{
    int count = cal_nums(str);
    std::string new_str;
    new_str.resize(str.size() + count * 5);

    int first = str.size() - 1;
    int last = new_str.size() - 1;

    std::string insert_str = "number";

    for (int i = first; i >= 0; i--)
    {
        // 如果是字母
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            new_str[last] = str[i];
            last--;
        }
        else
        {
            int end = insert_str.size() - 1;
            for (int j = end; j >= 0; j--)
            {
                new_str[last] = insert_str[j];
                last--;
            }
        }
    }

    return new_str;
}

int main()
{
    std::string str = "a5b";
    std::cout << replace(str) << std::endl;
}