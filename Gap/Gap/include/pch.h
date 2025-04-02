#pragma once

#include <iostream>
#include <string>
#include "register.h"
#include <vector>
#include <fstream>
#include "json.hpp"
#include "menu.h"
#include "login.h"

#ifdef OSisWindows
    #include <conio.h>
#else   
    #include <stdio.h>
    #define _getch getchar
#endif

using nlohmann::ordered_json;
using json = nlohmann::json;