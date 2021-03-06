/*
  Copyright (C) 2016 National Institute For Space Research (INPE) - Brazil.

  This file is part of the WTSS.CXX.

  WTSS.CXX is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License version 3 as
  published by the Free Software Foundation.

  WTSS.CXX is distributed  "AS-IS" in the hope that it will be useful,
  but WITHOUT ANY WARRANTY OF ANY KIND; without even the implied warranty
  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License along
  with WTSS.CXX. See COPYING. If not, see
  <http://www.gnu.org/licenses/lgpl-3.0.html>.
 */

/*!
  \file wtss-cxx/exception.hpp

  \brief Base exception class in WTSS.CXX.

  \author Matheus Cavassan Zaglia
 */

#ifndef __WTSS_CXX_EXCEPTION_HPP__
#define __WTSS_CXX_EXCEPTION_HPP__

// STL
#include <stdexcept>
#include <string>

// Boost
#include <boost/exception/all.hpp>

//! WTSS.CXX.
namespace wtss
{
  namespace cxx
  {
    //! Base exception class for WTSS.CXX.
    struct exception : virtual std::exception, virtual boost::exception{};

    //! Exception type for missing parameter value in service request.
    struct missing_argument_error : virtual exception{};

    //! Exception type for invalid parameter value in service request.
    struct invalid_argument_error : virtual exception{};

    //! Exception type when parsing a document (JSON, XML or any other format).
    struct parse_error : virtual exception{};

    //! Exception type for an http server response error.
    struct http_response_error : virtual exception{};

    //! The base type for error report messages.
    typedef boost::error_info<struct tag_error_description, std::string>
        error_description;
  }  // end namespace cxx
}  // end namespace wtss

#endif  // __WTSS_CXX_EXCEPTION_HPP__
