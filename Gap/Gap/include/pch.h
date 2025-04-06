#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "register.h"
#include <vector>
#include <fstream>
#include "../../BLL/include/register.h"
#include "../../DAL/include/files.h"
#include "json.hpp"
#include "login.h"
#include "dashboard.h"
#include "profile.h"
#include "timeline.h"
#include <limits>

#ifdef OSisWindows
    #include <conio.h>
#else   
    #include <stdio.h>
    #define _getch getchar
#endif

using nlohmann::ordered_json;
using json = nlohmann::json;