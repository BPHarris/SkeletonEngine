-- SkeletonEngine Workspace
workspace "SkeletonEngine"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }


-- Output directory (e.g. Debug-Win-x64)
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- SkeletonEngine DLL Project
project "SkeletonEngine"
    location "SkeletonEngine"   -- Place project files in SkeletonEngine/SkeletonEngine
    kind "SharedLib"            -- Set kind to DLL (SharedLib)
    language "C++"

    -- bin/ and bin-int/ directories for project
    targetdir ("bin/"     .. outputdir .. "/%{prj.name}")
    objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

    -- All *.h and *.cpp files in the project directory
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    -- Include vendor code
    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"         -- spdlog
    }

    -- Windows
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SE_PLATFORM_WINDOWS",
            "SE_BUILD_DLL"
        }

        postbuildcommands
        {
            -- On build, copy DLL into Demo project
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Demo")
        }
    
    -- Debug
    filter "configurations:Debug"
        defines "SE_DEBUG"
        symbols "On"
    
    -- Release
    filter "configurations:Release"
        defines "SE_RELEASE"
        optimize "On"
    
    -- Dist
    filter "configurations:Dist"
        defines "SE_DIST"
        optimize "On"


-- Demo Project
project "Demo"
    location "Demo"
    kind "ConsoleApp"   -- Set kind to executable (ConsoleApp)
    language "C++"

    -- bin/ and bin-int/ directories for project
    targetdir ("bin/"     .. outputdir .. "/%{prj.name}")
    objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

    -- All *.h and *.cpp files in the project directory
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    -- Include vendor code
    includedirs
    {
        "SkeletonEngine/src",                           -- SkeletonEngine
        "SkeletonEngine/vendor/spdlog/include"          -- spdlog
    }

    -- Link to SkeletonEngine prject
    links
    {
        "SkeletonEngine"
    }

    -- Windows
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SE_PLATFORM_WINDOWS"
        }
    
    -- Debug
    filter "configurations:Debug"
        defines "SE_DEBUG"
        symbols "On"
    
    -- Release
    filter "configurations:Release"
        defines "SE_RELEASE"
        optimize "On"
    
    -- Dist
    filter "configurations:Dist"
        defines "SE_DIST"
        optimize "On"
