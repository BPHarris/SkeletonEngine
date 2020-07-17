-- SkeletonEngine Workspace
workspace "SkeletonEngine"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }


-- Output directory (e.g. Debug-Win-x64)
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root
IncludeDir = {}
IncludeDir["GLFW"] = "SkeletonEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "SkeletonEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "SkeletonEngine/vendor/imgui"

include "SkeletonEngine/vendor/GLFW"
include "SkeletonEngine/vendor/Glad"
include "SkeletonEngine/vendor/imgui"


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
        "%{IncludeDir.GLFW}",                       -- GLFW
        "%{IncludeDir.Glad}",                       -- glad
        "%{IncludeDir.ImGui}",                      -- ImGui
    }

    links { "GLFW", "Glad", "ImGui", "opengl32.lib" }

    defines { "GLFW_INCLUDE_NONE" }    

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
        symbols "On"
        buildoptions "/MDd"
        defines { "SE_DEBUG", "SE_ENABLE_ASSERTS" }
    
    filter "configurations:Release"
        optimize "On"
        buildoptions "/MD"
        defines { "SE_RELEASE" }
    
    filter "configurations:Dist"
        optimize "On"
        buildoptions "/MD"
        defines { "SE_DIST" }


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
        symbols "On"
        buildoptions "/MDd"
        defines { "SE_DEBUG", "SE_ENABLE_ASSERTS" }
    
    filter "configurations:Release"
        optimize "On"
        buildoptions "/MD"
        defines { "SE_RELEASE" }
    
    filter "configurations:Dist"
        optimize "On"
        buildoptions "/MD"
        defines { "SE_DIST" }
