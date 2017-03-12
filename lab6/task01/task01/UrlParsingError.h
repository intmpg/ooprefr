#pragma once
#include <stdexcept>
#include "stdafx.h"

enum Protocol // to HttpUrl.h 
{
	HTTP,
	HTTPS
};

class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(const std::string & msg);
};

