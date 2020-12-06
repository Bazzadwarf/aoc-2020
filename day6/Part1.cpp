#include "Part1.h"

void Part1::Solution(string f)
{
	ifstream file(f);

	string input, response, sanitizedResponse;
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
				if (sanitizedResponse.find(response[i]) == string::npos)
				{
					sanitizedResponse.append(1, response[i]);
				}
			}

			answer += sanitizedResponse.size();
			response.clear();
			sanitizedResponse.clear();
		}
	}

	cout << "The answer is: " << answer << endl;
}

