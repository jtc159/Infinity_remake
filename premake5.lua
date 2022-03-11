workspace "Infinity"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Infinity/vendor/glfw"
include "Infinity/vendor/Glad"
include "Infinity/vendor/imgui"

project "Infinity"
    location "Infinity"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "ifpch.h"
    pchsource "Infinity/src/ifpch.cpp"

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    defines
    {
        "IF_BUILD_DLL",
        "GLFW_INCLUDE_NONE",
    }

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/glfw/include",
        "%{prj.name}/vendor/Glad/include",
        "%{prj.name}/vendor/imgui",
        "%{prj.name}/src"
    }
    
    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    links
    {
        "Infinity"
    }
    includedirs
    {
    	"Infinity/vendor/spdlog/include",
        "Infinity/vendor/glfw/include",
        "Infinity/vendor/Glad/include",
        "Infinity/src"
    }