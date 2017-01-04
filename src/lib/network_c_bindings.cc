#include "network.h"

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "multipageloader_p.hh"

#include "dllbegin.inc"

CAPI(wkhtmltox_network_request*) wkhtmltox_network_request_create(const char* url) {
	return reinterpret_cast<wkhtmltox_network_request*>(new QNetworkRequest(QUrl(QString::fromUtf8(url))));
}

CAPI(void) wkhtmltox_network_request_free(wkhtmltox_network_request* req) {
	delete reinterpret_cast<QNetworkRequest*>(req);
}

CAPI(wkhtmltox_network_request*) wkhtmltox_network_request_clone(const wkhtmltox_network_request* req) {
	return reinterpret_cast<wkhtmltox_network_request*>(
		new QNetworkRequest(*reinterpret_cast<const QNetworkRequest*>(req)));
}

CAPI(void) wkhtmltox_network_request_get_url(const wkhtmltox_network_request* req, char* url, int* cb) {
	QByteArray s(reinterpret_cast<const QNetworkRequest*>(req)->url().toEncoded());
	int bufLen(*cb);

	*cb = s.length();
	if (url)
		strcpy_s(url, bufLen, s.constData());
}
CAPI(void) wkhtmltox_network_request_set_url(wkhtmltox_network_request* req, const char* url) {
	reinterpret_cast<QNetworkRequest*>(req)->setUrl(QUrl(QString::fromUtf8(url)));
}

CAPI(wkhtmltox_network_reply*) wkhtmltox_network_reply_create(
	wkhtmltox_network_access_manager* nam, wkhtmltox_network_operation op,
	const wkhtmltox_network_request* req, wkhtmltox_stream* outgoingData) {

	return reinterpret_cast<wkhtmltox_network_reply*>(
		reinterpret_cast<wkhtmltopdf::MyNetworkAccessManager*>(nam)->baseCreateRequest(
			static_cast<QNetworkAccessManager::Operation>(op),
			*reinterpret_cast<const QNetworkRequest*>(req),
			reinterpret_cast<QIODevice*>(outgoingData)));
}
