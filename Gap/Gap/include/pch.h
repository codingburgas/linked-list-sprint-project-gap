#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "register.h"
#include <vector>
#include "../../BLL/include/register.h"
#include "../../DAL/include/files.h"
#include <fstream>
#include "json.hpp"
#include "menu.h"
#include "login.h"
#include "dashboard.h"
#include "profile.h"
#include <limits>

#ifdef OSisWindows
    #include <conio.h>
#else   
    #include <stdio.h>
    #define _getch getchar
#endif

using nlohmann::ordered_json;
using json = nlohmann::json;