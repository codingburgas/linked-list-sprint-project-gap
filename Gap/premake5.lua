workspace "Gap"
    startproject "PL"
    architecture "x64"
    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "BLL"
    location "BLL"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/".. outputdir.. "/%{prj.name}")
    objdir ("bin-int/".. outputdir.. "/%{prj.name}")

    files { "BLL/src/**.cpp", "BLL/include/**.h" }
    
    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "OD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OD_RELEASE"
        optimize "On"


project "DAL"
    location "DAL"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/".. outputdir.. "/%{prj.name}")
    objdir ("bin-int/".. outputdir.. "/%{prj.name}")

    files { "DAL/src/**.cpp", "DAL/include/**.h" }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "OD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OD_RELEASE"
        optimize "On"


project "PL"
    location "PL"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/".. outputdir.. "/%{prj.name}")
    objdir ("bin-int/".. outputdir.. "/%{prj.name}")

    files { "PL/src/**.cpp", "PL/include/**.h" }

    includedirs { "vendor/ftxui/install/include", "PL/src", "BLL/include", "DAL/include" }

    libdirs { "vendor/ftxui/install/lib" }

    links { "ftxui-screen", "ftxui-dom", "ftxui-component", "BLL", "DAL" }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "OD_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "OD_RELEASE"
        optimize "On"