#pragma once
#include "UrlParsingError.h"

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);

	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol const& protocol,
		unsigned short port = 80);

	std::string GetURL() const;

	std::string GetDomain() const;

	std::string GetDocument() const;

	Protocol GetProtocol() const;

	unsigned short GetPort() const;

private:
	void SetDomain(const std::string & domain);
	void SetDocument(const std::string & document);
	void SetProtocol(const std::string & protocol);
	void SetPort(const std::string & port);
	std::string ProtocolToString() const;
private:
	std::string m_url;
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};

