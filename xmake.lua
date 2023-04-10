set_languages("c++23")
add_rules("mode.debug")
set_toolchains("msvc")

-- Required for the example, but you can bring your own logger and add an adapter
add_requires("spdlog")
add_requires("boost")

option("use_spdlog")
    set_description("Enable spdlog for logging")
    set_default(false)
    set_showmenu(true)

option("use_boost")
    set_description("Enable Boost.Log for logging")
    set_default(false)
    set_showmenu(true)

target("Logging")
    set_kind("headeronly")
    add_headerfiles("include/(**.h)")
    add_includedirs("include", {public = true})

target("Example")
    set_kind("binary")
    add_files("Example.cpp")
    add_deps("Logging")
    add_options("use_spdlog", "use_boost")
    if has_config("use_boost") then
        add_packages("boost")
    end
    if has_config("use_spdlog") then
        add_packages("spdlog")
    end
