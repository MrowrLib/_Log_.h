set_languages("c++20")
add_rules("mode.debug")

add_repositories("MrowrLib https://github.com/MrowrLib/Packages.git")

-- Required for the example, but you can bring your own logger and add an adapter
add_requires("spdlog", "string_format")

target("_Log_")
    set_kind("headeronly")
    add_headerfiles("include/_Log_.h")
    add_includedirs("include", {public = true})

target("Example")
    set_kind("binary")
    add_files("Example.cpp")
    add_deps("_Log_")
    add_packages("string_format", "spdlog")
