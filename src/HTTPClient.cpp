/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2018  yuribadz <email>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "HTTPClient.hpp"

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/Exception.h>
#include <iostream>
#include <map>
#include <sstream>


// helper function to convert istream to string
// it is used because stringstream is fairly slow
std::string gulp(std::istream &in)
{
    std::string ret;
    char buffer[4096];
    while (in.read(buffer, sizeof(buffer)))
    {
        ret.append(buffer, sizeof(buffer));
    }
    const unsigned int extractedCharCount =
            static_cast<const unsigned int>(in.gcount());
    ret.append(buffer, extractedCharCount);
    return ret;
}

HTTPClient::HTTPClient(): serverAdress("http://127.0.0.1:9980/")
{
}

std::string HTTPClient::postRequest(std::string body)
{
    return body;
}

std::string HTTPClient::getRequest(std::string body)
{
    try{
        std::map<std::string,std::string> headers;
//        headers["Test-Header"] = "Rainbow Lollipop";
        std::string  result;
        Poco::Net::HTTPClientSession session(serverAdress.getHost(),
                                             serverAdress.getPort());
        std::string path(serverAdress.getPathAndQuery());
        if (path.empty())
        {
            path = "/";
        }
        Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, path,
                                       Poco::Net::HTTPMessage::HTTP_1_1);
        request.setContentType("text/plain");

// Header test related
//        for(std::map<std::string,std::string>::iterator it = headers.begin();
//                   it != headers.end(); it++) {
//                   request.set(it->first, it->second);
//       }
        request.setContentLength(body.length());
        std::ostream& os = session.sendRequest(request);
        os << body; // sends the body
        request.write(std::cout); // print out request
        Poco::Net::HTTPResponse response;
        std::istream &is = session.receiveResponse(response);
        std::string responseBody = gulp(is);
        std::cout << "======================" << "\n";
        std::cout << responseBody << "\n";
        std::cout << "======================" << "\n";
        return responseBody;
    }
    catch (Poco::Exception &ex)
    {
        std::cerr << ex.displayText() << "\n";
        return "";
    }
}
