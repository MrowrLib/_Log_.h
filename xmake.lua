set_languages("c++20")
add_rules("mode.debug")
set_toolchains("msvc")

-- Required for the example, but you can bring your own logger and add an adapter
add_requires("spdlog")

target("_Log_")
    set_kind("headeronly")
    add_headerfiles("include/_Log_")
    add_includedirs("include", {public = true})

target("Example")
    set_kind("binary")
    add_files("Example.cpp")
    add_deps("_Log_")
    add_packages("spdlog")
