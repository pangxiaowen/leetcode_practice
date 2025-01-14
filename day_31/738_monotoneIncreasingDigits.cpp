#include <string>
#include <iostream>

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

int main()
{
    int i = 98;

    std::cout << monotoneIncreasingDigits(i) << std::endl;
}