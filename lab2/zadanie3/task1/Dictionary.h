#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)
#include <boost/algorithm/string.hpp>
#include <map>
#include <fstream>
#include <boost/noncopyable.hpp>
#include "DictionaryLogic.h"

class CDictionary : boost::noncopyable
{
public:
	std::string GetWordToTranslate();
	void DialogBeforeFinishWithUser();
	void StartWorkWithDictionary();
	bool HaveTranslate(std::string const & wordToTranslate);
private:
	CDictionaryLogic logic;	
};

