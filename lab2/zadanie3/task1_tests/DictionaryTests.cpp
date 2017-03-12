#include "stdafx.h"
#include <Windows.h>
#include "..\task1\DictionaryLogic.h"

using namespace std;

struct dictionary
{
	CDictionaryLogic log;
};

BOOST_FIXTURE_TEST_SUITE(start_dictionary_tests, dictionary)

// Создает пустой вектор из пустого вектора
BOOST_AUTO_TEST_CASE(load_empty_dictionary)
{
	log.m_fileName = "tests1.txt";

	ifstream inputFile(log.GetFileName());

	log.InputDictionary();

	BOOST_CHECK(log.GetDictionary().empty());

}

BOOST_AUTO_TEST_CASE(load_not_empty_dictionary)
{
	log.m_fileName = "tests2.txt";

	ifstream inputFile(log.GetFileName());

	log.InputDictionary();

	BOOST_CHECK(!log.GetDictionary().empty());

	log.SaveDictionaryInFile();
}

BOOST_AUTO_TEST_CASE(can_find_word_in_dictionary_and_save_it)
{
	log.m_fileName = "tests2.txt";

	ifstream inputFile(log.GetFileName());

	log.InputDictionary();
	string word = "hi";
	BOOST_CHECK(!log.GetDictionary().empty());
	BOOST_CHECK(log.HaveRusTranslate(word));
	word = "привет";
	BOOST_CHECK(!log.HaveRusTranslate(word));
	BOOST_CHECK(log.HaveEngTranslate(word));
	multimap <string, string> dictionary = log.GetDictionary();
	log.SaveDictionaryInFile();
	log.InputDictionary();
	BOOST_CHECK(log.GetDictionary() == dictionary);
	log.SaveDictionaryInFile();
}

BOOST_AUTO_TEST_CASE(can_add_word_in_dictionary)
{
	log.m_fileName = "tests2.txt";
	ifstream inputFile(log.GetFileName());
	log.InputDictionary();
	string word = "mother";
	string wordTranslation = "мама";
	BOOST_CHECK(!log.GetDictionary().empty());
	BOOST_CHECK(!log.HaveRusTranslate(word));
	log.SavingNewWordTranslation(word, wordTranslation);
	BOOST_CHECK(log.HaveRusTranslate(word));
	BOOST_CHECK(log.HaveEngTranslate(wordTranslation));
}

BOOST_AUTO_TEST_CASE(can_create_empty_dictionary_and_add_some_words)
{
	log.m_fileName = "tests3.txt";
	ifstream inputFile(log.GetFileName());
	log.InputDictionary();
	BOOST_CHECK(log.GetDictionary().empty());
	string firstWord = "mother";
	string firstWordTranslation = "мама";
	BOOST_CHECK(!log.HaveRusTranslate(firstWord));
	log.SavingNewWordTranslation(firstWord, firstWordTranslation);
	string secondWord = "father";
	string secondWordTranslation = "папа";
	BOOST_CHECK(!log.HaveRusTranslate(secondWord));
	log.SavingNewWordTranslation(secondWord, secondWordTranslation);
	multimap <string, string> dictionary = log.GetDictionary();
	log.SaveDictionaryInFile();
	log.InputDictionary();
	BOOST_CHECK(log.GetDictionary() == dictionary && !dictionary.empty());
	std::remove(log.m_fileName.c_str());
}

BOOST_AUTO_TEST_SUITE_END()


