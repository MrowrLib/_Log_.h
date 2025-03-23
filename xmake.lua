add_rules("mode.debug", "mode.release")

-- Support way, way back to C++14
-- MSVC doesn't even understand C++11 lol
set_languages("c++14")

option("build_example")
    set_default(true)
option_end()

add_requires("spdlog")

library_name = "_Log_"

target(library_name)
    set_kind("static")
    add_files("src/*.cpp")
    add_headerfiles("include/_Log_.h")
    add_includedirs("include", { public = true })
    add_packages("spdlog", { public = true })

if has_config("build_example") then
    target("Example")
        set_kind("binary")
        add_files("Example.cpp")
        add_deps(library_name)
end
