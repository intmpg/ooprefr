#include "stdafx.h"

struct predicate_strsize_less
{
	bool operator()(const std::string &l, const std::string &r) const
	{
		if (l.size() != r.size())
			return l.size() > r.size();
		return l > r;
	}
};

typedef std::map<std::string, std::string, predicate_strsize_less> WordAccordances;

std::string ExpandTemplate(const std::string &tpl, const WordAccordances &params);