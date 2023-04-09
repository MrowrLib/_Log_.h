set_languages("c++23")
add_rules("mode.debug")
set_toolchains("msvc")

add_requires("spdlog")

target("Logging")
    set_kind("library")
    add_headerfiles("include/(**.h)")
    add_includedirs("include", {public = true})

target("Example")
    set_kind("binary")
    add_files("Example.cpp")
    add_deps("Logging")
    add_imports("Logging")
    add_packages("spdlog")
