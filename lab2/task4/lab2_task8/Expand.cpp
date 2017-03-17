#include "stdafx.h"
#include "Expand.h"

using namespace std;

const int hashBase = 257;
vector<long long> hashPowers;

void CalcHashPowers(size_t size)
{
	hashPowers.resize(size);
	long long curHashMult = 1;
	for (size_t i = 0; i < size; ++i, curHashMult *= hashBase)
	{
		hashPowers[i] = curHashMult;
	}
}

long long CalcHash(const std::string &s)
{
	long long hash = 0;
	for (size_t i = 0; i < s.length(); ++i)
	{
		hash += (s[i] + 1) * hashPowers[i];
	}

	return hash;
}

bool EqualStrings(const string &s1, const string &s2, size_t start, size_t end)
{
	for (size_t i = start; i <= end; i++)
	{
		if (s1[i - start] != s2[i])
		{
			return false;
		}
	}

	return true;
}

string ExpandTemplate(const string &tpl, const WordAccordances &params)
{
	if (params.empty())
	{
		return tpl;
	}

	vector<long long> hashes(params.size()), strHashes(tpl.length());
	CalcHashPowers(tpl.length());

	size_t curParam = 0;
	for (auto it = params.cbegin(); it != params.cend(); it++, curParam++)
	{
		if (it->first.length() <= tpl.length())
		{
			hashes[curParam] = CalcHash(it->first);
		}
	}

	long long curHash = 0;
	for (size_t i = 0; i < tpl.length(); ++i)
	{
		curHash += (tpl[i] + 1) * hashPowers[i];
		strHashes[i] = curHash;
	}
	
	string s = "";
	for (size_t i = 0; i < tpl.length(); ++i)
	{
		curParam = 0;
		bool found = false;
		WordAccordances::const_iterator foundParam;
		for (auto it = params.cbegin(); it != params.cend(); it++, curParam++)
		{
			if (it->first.empty())
			{
				break;
			}

			size_t paramIndex = it->first.length() + i - 1;
			if (tpl.length() > paramIndex)
			{
				long long curHash = strHashes[paramIndex];
				if (i)
				{
					curHash -= strHashes[i - 1];
				}

				size_t paramPower = it->first.length() - 1;
				long long paramHash = hashes[curParam] * hashPowers[i];

				if (curHash == paramHash && EqualStrings(it->first, tpl, i, paramIndex))
				{
					found = true;
					foundParam = it;
					break;
				}
			}
		}

		if (!found)
		{
			s += tpl[i];
		}
		else
		{
			s += foundParam->second;
			i += foundParam->first.length() - 1;
		}
	}

	return s;
}