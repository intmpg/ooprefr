#include "stdafx.h"
#include "HttpUrl.h"

CHttpUrl::CHttpUrl(std::string const & url)
	: m_url(url)
{
		boost::regex xRegEx("(https?)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)");
		boost::cmatch httpResults;
		if (boost::regex_match(url.c_str(), httpResults, xRegEx))
		{
			SetProtocol(boost::lexical_cast<std::string>(httpResults[1]));
			SetDomain(boost::lexical_cast<std::string>(httpResults[2]));
			SetPort(boost::lexical_cast<std::string>(httpResults[3]));
			SetDocument(boost::lexical_cast<std::string>(httpResults[4]));
		}
		else
		{
			throw CUrlParsingError("incorrect_url");
		}
}

CHttpUrl::CHttpUrl(std::string const & domain, std::string const & document, Protocol const & protocol, unsigned short port)
	: m_protocol(protocol)
	, m_port(port)
{
	SetDomain(domain);
	SetDocument(document);
}

std::string CHttpUrl::GetURL() const
{
	return (ProtocolToString() + "://" + m_domain + m_document);
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}	

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

void CHttpUrl::SetDomain(const std::string & domain)
{
	if (domain.empty())
	{
		throw CUrlParsingError("empty_domain");
	}
	if (find_if(domain.begin(), domain.end(), [](char ch) {return (isspace(ch) || (ch == '/') || (ch == '\'')); })
		!= domain.end())
	{
		throw CUrlParsingError("contains spaces, tab characters in the domain name");
	}
	m_domain = domain;
}

void CHttpUrl::SetDocument(const std::string & document)
{
	if (document[0] != '/')
	{
		m_document = '/' + document;
	}
	else if (find_if(document.begin(), document.end(), isspace) != document.end())
	{
		throw CUrlParsingError("contains spaces, tab characters in the document name");
	}
	else
	{
		m_document = document;
	}
}

void CHttpUrl::SetProtocol(const std::string & protocol)
{
	if (protocol == "http")
	{	
		m_protocol = HTTP;
	}
	else if (protocol == "https")
	{
		m_protocol = HTTPS;
	}
	else
	{
		throw CUrlParsingError("incorrect_protocol");
	}
}

void CHttpUrl::SetPort(const std::string & port)
{
	unsigned short currentPort = std::stoi(port);

	if (port.empty())
	{
		switch (m_protocol)
		{
		case Protocol::HTTP:
			m_port = 80;
			break;
		case Protocol::HTTPS:
			m_port = 443;
			break;
		}
	}
	else if (currentPort < 65535)
	{
		m_port = currentPort;
	}
	else
	{
		throw CUrlParsingError("incorrect_port");
	}
}

std::string CHttpUrl::ProtocolToString() const
{
	switch (m_protocol)
	{
	case Protocol::HTTP:
		return "http";
	case Protocol::HTTPS:
		return "https";
	};
	return std::string();
}
