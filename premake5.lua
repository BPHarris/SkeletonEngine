-- SkeletonEngine Workspace
workspace "SkeletonEngine"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }


-- Output directory (e.g. Debug-Win-x64)
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root
IncludeDir = {}
IncludeDir["GLFW"] = "SkeletonEngine/vendor/GLFW/include"

include "SkeletonEngine/vendor/GLFW"


-- SkeletonEngine DLL Project
project "SkeletonEngine"
    location "SkeletonEngine"   -- Place project files in SkeletonEngine/SkeletonEngine
    kind "SharedLib"            -- Set kind to DLL (SharedLib)
    language "C++"


    targetdir ("bin/"     .. outputdir .. "/%{prj.name}")
    objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")


    pchheader "sepch.h"
    pchsource "SkeletonEngine/src/sepch.cpp"


    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

    includedirs {
        "%{prj.name}/src",                          -- SkeletonEngine/src
        "%{prj.name}/vendor/spdlog/include",        -- spdlog
        "%{IncludeDir.GLFW}"                        -- GLFW
    }

    links { "GLFW", "opengl32.lib" }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines { "SE_PLATFORM_WINDOWS", "SE_BUILD_DLL" }

        postbuildcommands {
            -- On build, copy DLL into Demo project
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Demo")
        }

    filter "system:linux"
        systemversion "latest"
        defines { "SE_PLATFORM_LINUX" }

    filter "system:macosx"
        systemversion "latest"
        defines { "SE_PLATFORM_MACOSX" }
  
    filter "configurations:Debug"
        defines "SE_DEBUG"
        symbols "On"
        defines { "SE_ENABLE_ASSERTS" }
    
    filter "configurations:Release"
        defines "SE_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "SE_DIST"
        optimize "On"


project "Demo"
    location "Demo"
    kind "ConsoleApp"   -- Set kind to executable (ConsoleApp)
    language "C++"


    targetdir ("bin/"     .. outputdir .. "/%{prj.name}")
    objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")


    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

    includedirs {
        "SkeletonEngine/src",                           -- SkeletonEngine
        "SkeletonEngine/vendor/spdlog/include"          -- spdlog
    }

    links { "SkeletonEngine" }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines { "SE_PLATFORM_WINDOWS" }

    filter "system:linux"
        systemversion "latest"
        defines { "SE_PLATFORM_LINUX" }

    filter "system:macosx"
        systemversion "latest"
        defines { "SE_PLATFORM_MACOSX" }
        
    filter "configurations:Debug"
        defines "SE_DEBUG"
        symbols "On"
        defines { "SE_ENABLE_ASSERTS" }
    
    filter "configurations:Release"
        defines "SE_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "SE_DIST"
        optimize "On"
