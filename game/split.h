#pragma once
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// splits the read string into a vector
// function given by professor
vector<string> split(string data)
{
	vector<string> results;
	istringstream memStream(data);
	string token;
	while (getline(memStream, token, ','))
	{
		results.push_back(token);
	}
	return results;
}

