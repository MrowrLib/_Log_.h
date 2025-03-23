# `#include <_Log_.h>`

```cpp
#include <_Log_.h>

void Example() {
    _Log_("A great number is: {}", 42);
    
    // Or use any of the other macros of different log levels:
    _Error_("Oh noes!");
    _Debug_("Debugging...");
    
    // Specify a level (default: trace)
    _SetLogLevel_(warn);
    
    // Specify a log file (default: console)
    _LogToFile_("my.log");
}
```

## What?

A simple logging interface for C++ libraries.

## Why?

I truly don't care what logging library I'm using.

Just do it. Log the thing. Make it go, please.

> **Except** _sometimes_ I _do_ care.
>
> And in those scenarios, I want to be able to use my own logger. But use the same lazy `_Log_()` syntax.
>
> As there are only a few really simple macros, it's really easy to completely override them with your own implementation.
> - `_Log_(...)`
> - `_Trace_(...)`
> - `_Debug_(...)`
> - `_Info_(...)`
> - `_Warn_(...)`
> - `_Error_(...)`
> - `_Fatal_(...)`
> - `_SetLogLevel_(...)`
> - `_LogToFile_(...)`
>
> If you only care about the `_Log_` macro, your programs can:
> ```cpp
> #include <_Log_/_Log_.h>
> ```
>
> And that will use the default `spdlog` implementation but the ONLY macro added to your program will be `_Log_`.
>
> And, of course, this makes it really easy to override:
> ```cpp
> #define _Log_(...) myLogger.log(__VA_ARGS__)
> #include <_Log_/_Log_.h>
> ```

## Installation

### xmake

#### `xmake.lua`

```lua
add_repositories("MrowrLib https://github.com/MrowrLib/Packages.git")
add_requires("_Log_")

target("Example")
    add_packages("_Log_")
```

### vcpkg

#### `CMakeLists.txt`

```cmake
add_executable(Example main.cpp)

# Find _Log_ and link it to your target
find_package(_Log_ CONFIG REQUIRED)
target_link_libraries(Example PRIVATE _Log_::_Log_)
```

#### `vcpkg.json`

```json
{
    "dependencies": ["mrowr-log"]
}
```

And if you want to use `spdlog`:

```json
{
    "dependencies": ["mrowr-log", "spdlog"]
}
```

#### `vcpkg-configuration.json`

```json
{
    "default-registry": {
        "kind": "git",
        "repository": "https://github.com/microsoft/vcpkg.git",
        "baseline": "670f6dddaafc59c5dfe0587a130d59a35c48ea38"
    },
    "registries": [
        {
            "kind": "git",
            "repository": "https://github.com/MrowrLib/Packages.git",
            "baseline": "6887c023180286b54b805f50ec33eab3f30e4818",
            "packages": ["mrowr-log"]
        }
    ]
}
```

> _Update the default-registry baseline to the latest commit from https://github.com/microsoft/vcpkg_  
> _Update the MrowrLib/Packages baseline to the latest commit from https://github.com/MrowrLib/Packages_

## Naming?

Searching across GitHub, there are many libraries which...
- `#include <_Log_.h>` or `#include <Log.h>`
- Have a `Logging` or `Log` class or namespace
- Have a `Log` or `LOG` or `_log_` or `_LOG_` function or macro

Because _almost all_ of my libraries use this library, I wanted to make **sure** that this library's names were very, **_very_ unlikely to conflict with other libraries**.

Hence `#include <_Log_.h>` and `_Log_` / `_LogToFile_`.

I couldn't find anyone using `_Log_` (_camel case_) across GitHub.

**You can safely use this in your own libraries**.

> _I also don't like to "sign" my own work, so I didn't want something like `<Mrowr/Logging.h>`_

### No Logging

By default, `_Log_` logs using `spdlog` to console (_or file if you specify it_).

If you want to disable all logging entirely:

```cpp
#include <_Log_/Disable.h>
```

### Bring Your Own Logger

Easy.

Just define `_Log_` before including any library headers.

If a `_Log_` macro is defined, then this library will use it.

> Optionally also define `_LogToFile_` (defaults to an empty macro)  
> and whichever log levels you want to implement (etc)

## License

Use however, no attribution required.

```
BSD Zero Clause License (SPDX: 0BSD)

Permission to use, copy, modify, and/or distribute this software for any purpose
with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.

```
