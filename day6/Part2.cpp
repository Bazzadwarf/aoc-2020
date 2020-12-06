#include "Part2.h"

void Part2::Solution(string f)
{
	ifstream file(f);

	string input, response, sanitizedResponse;
	vector<string> responses = vector<string>();

	int answer = 0;

	while (getline(file, input))
	{
		if (input != "")
		{
			response.append(input);
			responses.push_back(input);
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

			for (size_t i = 0; i < sanitizedResponse.size(); i++)
			{
				bool found = true;

				for (size_t j = 0; j < responses.size(); j++)
				{
					if (responses[j].find(sanitizedResponse[i]) == string::npos)
					{
						found = false;
						break;
					}
				}
				answer += found;
			}

			response.clear();
			responses.clear();
			sanitizedResponse.clear();
		}
	}

	cout << "The answer is: " << answer << endl;
}

