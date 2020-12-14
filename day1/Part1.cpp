#include "Part1.h"

void Part1::Solution(std::string f)
{
    std::vector<int> num = std::vector<int>();

    std::ifstream file(f);

    int a;

    while (file >> a)
    {
        num.push_back(a);
    }

    file.close();

    int length = num.size();

    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < length; j++)
        {
            if (num[i] + num[j] == 2020)
            {
                std::cout << "The answer is: " << num[i] * num[j] << std::endl;
                return;
            }
        }
    }
}
