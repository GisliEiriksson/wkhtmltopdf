/* -*- mode: c++; tab-width: 4; indent-tabs-mode: t; eval: (progn (c-set-style "stroustrup") (c-set-offset 'innamespace 0)); -*-
 * vi:set ts=4 sts=4 sw=4 noet :
 *
 * Copyright 2017 wkhtmltopdf authors
 *
 * This file is part of wkhtmltopdf.
 *
 * wkhtmltopdf is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * wkhtmltopdf is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with wkhtmltopdf.  If not, see <http: *www.gnu.org/licenses/>.
 */

#ifndef __WKHTMLTOX_NETWORK_H__
#define __WKHTMLTOX_NETWORK_H__
#include <wkhtmltox/dllbegin.inc>

// QNetworkRequest
struct wkhtmltox_network_request;
typedef struct wkhtmltox_network_request wkhtmltox_network_request;

// QNetworkReply
struct wkhtmltox_network_reply;
typedef struct wkhtmltox_network_reply wkhtmltox_network_reply;

// QIODevice
struct wkhtmltox_stream;
typedef struct wkhtmltox_stream wkhtmltox_stream;

// MyNetworkAccessManager
struct wkhtmltox_network_access_manager;
typedef struct wkhtmltox_network_access_manager wkhtmltox_network_access_manager;

// QNetworkAccessManager::Operation
typedef enum {
  HeadOperation = 1,
  GetOperation,
  PutOperation,
  PostOperation,
  DeleteOperation,
  CustomOperation,

  UnknownOperation = 0
} wkhtmltox_network_operation;

CAPI(wkhtmltox_network_request*) wkhtmltox_network_request_create(const char* url);
CAPI(wkhtmltox_network_request*) wkhtmltox_network_request_clone(const wkhtmltox_network_request* req);
CAPI(void) wkhtmltox_network_request_free(wkhtmltox_network_request* req);

CAPI(void) wkhtmltox_network_request_get_url(const wkhtmltox_network_request* req, char* url, int* cb);
CAPI(void) wkhtmltox_network_request_set_url(wkhtmltox_network_request* req, const char* url);

CAPI(wkhtmltox_network_reply*) wkhtmltox_network_reply_create(
	wkhtmltox_network_access_manager* nam,
	wkhtmltox_network_operation op,
	const wkhtmltox_network_request* req,
	wkhtmltox_stream* outgoingData);

#include <wkhtmltox/dllend.inc>
#endif // __WKHTMLTOX_NETWORK_H__
