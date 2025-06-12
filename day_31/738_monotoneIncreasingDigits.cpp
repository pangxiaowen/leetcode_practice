#include <iostream>
#include <string>

int monotoneIncreasingDigits(int n)
{
    std::string str = std::to_string(n);

    int flag = str.size();
    for (int i = str.size() - 1; i > 0; i--)
    {

        if (str[i - 1] > str[i])
        {
            str[i - 1] = ((int)(str[i - 1]) - 1);
            flag = i;
        }
    }

    for (int i = flag; i < str.size(); ++i)
    {
        str[i] = '9';
    }

    return std::stoi(str);
}

bool check_num(int n)
{
    int max = 10;

    while (n)
    {
        int cur = n % 10;

        if (cur > max)
        {
            return false;
        }

        max = cur;
        n = n / 10;
    }

    return true;
}

int monotoneIncreasingDigitsv2(int n)
{
    for (int i = n; i > 0; i--)
    {
        if (check_num(i))
        {
            return true;
        }
    }

    return false;
}

int monotoneIncreasingDigitsv3(int n)
{
    std::string str = std::to_string(n);

    if (str.size() <= 1)
        return std::stoi(str);

    int flag;
    for (int i = str.size() - 1; i > 0; i--)
    {
        if (str[i] < str[i - 1])
        {
            str[i - 1]--;
            flag = i;
        }
    }

    for (int i = flag; i < str.size(); i++)
    {
        str[i] = '9';
    }

    return std::stoi(str);
}

int main()
{
    int i = 98;

    std::cout << monotoneIncreasingDigitsv3(i) << std::endl;
}