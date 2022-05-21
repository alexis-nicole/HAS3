/**********************************************************************************
* @File      main.h
* @Author    Alexis Nicole Benini, Ph.D.
* @Date      May 20th, 2022
**********************************************************************************/

#pragma once

#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <iterator>
#include <exception>

#include "boost/asio.hpp"
#include "boost/program_options.hpp"
#include "boost/filesystem.hpp"
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

#include "Config.h"

#define EXIT_DONE 2

using std::cerr;
using std::cout;
using std::endl;
using std::exception;

namespace po = boost::program_options;
namespace fs = boost::filesystem;
namespace pt = boost::posix_time;

#endif