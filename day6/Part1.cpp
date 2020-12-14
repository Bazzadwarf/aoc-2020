#include "Part1.h"

void Part1::Solution(std::string f)
{
	std::ifstream file(f);

	std::string input, response, sanitizedResponse;
	int answer = 0;

	while (getline(file, input))
	{
		if (input != "")
		{
			response.append(input);
		}
		else
		{
			for (size_t i = 0; i < response.size(); i++)
			{
				if (sanitizedResponse.find(response[i]) == std::string::npos)
				{
					sanitizedResponse.append(1, response[i]);
				}
			}

			answer += sanitizedResponse.size();
			response.clear();
			sanitizedResponse.clear();
		}
	}

	std::cout << "The answer is: " << answer << std::endl;
}

