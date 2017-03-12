#include <boost/algorithm/string.hpp>
#include <map>
#include <fstream>
#include <iostream>
#include <boost/noncopyable.hpp>

class CDictionaryLogic : boost::noncopyable
{
public:
	std::string GetFileName();
	void SetFileName();
	std::multimap <std::string, std::string> GetDictionary();
	bool HaveRusTranslate(std::string const & wordToTranslate);
	bool HaveEngTranslate(std::string const & wordToTranslate);
	std::string GetTranslation();
	void InputDictionary();
	void SavingNewWordTranslation(std::string const & wordToTranslate, std::string const & translatedWord);
	void SaveDictionaryInFile();
	std::string m_fileName;
private:
	std::multimap <std::string, std::string> m_dictionary;
};