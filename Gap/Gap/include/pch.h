#pragma once

#include<iostream>
#include<string>
#include "register.h"
#include<vector>
#include "../../BLL/include/register.h"
#include "../../DAL/DAL.h"
#include <fstream>
#include "json.hpp"
#include "menu.h"

#ifdef OSisWindows
    #include <conio.h>
#else   
    #include <stdio.h>
    #define _getch getchar
#endif

using nlohmann::ordered_json;