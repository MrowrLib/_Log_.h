set_languages("c++23")
add_rules("mode.debug")
set_toolchains("msvc")

-- Required for the example, but you can bring your own logger and add an adapter
add_requires("spdlog")

target("_Logging_")
    set_kind("headeronly")
    add_headerfiles("include/(**.h)")
    add_includedirs("include", {public = true})

target("Example")
    set_kind("binary")
    add_files("Example.cpp")
    add_deps("_Logging_")
    add_options("use_spdlog", "use_boost")
    add_packages("spdlog")
