#include "Part2.h"

void Part2::Solution(std::string f)
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
            for (size_t k = 0; k < length; k++)
            {
                if (num[i] + num[j] + num[k] == 2020)
                {
                    std::cout << "The answer is: " << num[i] * num[j] * num[k] << std::endl;
                    return;
                }
            }
        }
    }
}
