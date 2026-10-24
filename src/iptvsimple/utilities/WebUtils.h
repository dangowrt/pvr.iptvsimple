/*
 *  Copyright (C) 2005-2021 Team Kodi (https://kodi.tv)
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#pragma once

#include <map>
#include <string>
#include <utility>

namespace iptvsimple
{
  namespace utilities
  {
    static const std::string HTTP_PREFIX = "http://";
    static const std::string HTTPS_PREFIX = "https://";
    static const std::string NFS_PREFIX = "nfs://";
    static const std::string SPECIAL_PREFIX = "special://";
    static const std::string UDP_MULTICAST_PREFIX = "udp://@";
    static const std::string RTP_MULTICAST_PREFIX = "rtp://@";

    class WebUtils
    {
    public:
      static const std::string UrlEncode(const std::string& value);
      static const std::string UrlDecode(const std::string& value);
      static bool IsEncoded(const std::string& value);
      static std::string ReadFileContentsStartOnly(const std::string& url, int* httpCode);
      static bool IsHttpUrl(const std::string& url);
      static bool IsNfsUrl(const std::string& url);
      static bool IsSpecialUrl(const std::string& url);
      static std::string RedactUrl(const std::string& url);
      static bool Check(const std::string& url, int connectionTimeoutSecs, bool isLocalPath = false,
                        const std::string& uplinkSpec = {});
      static std::map<std::string, std::string> ConvertStringToHeaders(const std::string& input);
      static std::string ResolveLocalAddress(const std::string& spec);
      static std::pair<std::string, std::string> UplinkOption(const std::string& spec);
      static std::string AddUplinkToUrl(const std::string& url, const std::string& spec);
    };
  } // namespace utilities
} // namespace iptvsimple
