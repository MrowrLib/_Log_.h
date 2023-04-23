# `#include <_Log_>`

```cpp
#include <_Log_>

void Example() {
    _Log_("A great number is: {}", 42);
}
```

## What?

A simple logging interface for C++ libraries.

## Installation

### xmake

#### `xmake.lua`

```lua
add_repositories("MrowrLib https://github.com/MrowrLib/Packages.git")
add_requires("_Log_")

-- And if you want to use spdlog for log output
add_requires("spdlog")

target("Example")
    add_packages("_Log_")
    add_packages("spdlog") -- if using 'spdlog'
```

### vcpkg

#### `CMakeLists.txt`

```cmake
add_executable(Example main.cpp)

# Find _Log_ and link it to your target
find_package(_Log_ CONFIG REQUIRED)
target_link_libraries(Example PRIVATE _Log_::_Log_)

# Also find and link spdlog, if you plan on using it
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(Example PRIVATE spdlog::spdlog)
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
        "baseline": "95252eadd63118201b0d0df0b4360fa613f0de84"
    },
    "registries": [
        {
            "kind": "git",
            "repository": "https://github.com/MrowrLib/Packages.git",
            "baseline": "6e1884a73e89d614682de6c28107ef888d99f8a1",
            "packages": ["mrowr-log"]
        }
    ]
}
```

> _Update the default-registry baseline to the latest commit from https://github.com/microsoft/vcpkg_  
> _Update the MrowrLib/Packages baseline to the latest commit from https://github.com/MrowrLib/Packages_

## Why?

I want my libraries to all support logging.

But I want folks to be able to BYOL: **B**ring **Y**our **O**wn **L**ogger.

Want to use `spdlog`? Great!

This will _automatically_ detect `spdlog` and use it.

By default, however, it will do nothing.

## Naming?

Searching across GitHub, there are many libraries which...
- `#include <_Log_>` or `#include <Log.h>`
- Have a `Logging` or `Log` class or namespace
- Have a `Log` or `LOG` or `_log_` or `_LOG_` function or macro

Because _almost all_ of my libraries use this library, I wanted to make **sure** that this library's names were very, **_very_ unlikely to conflict with other libraries**.

Hence `#include <_Log_>` and `_Log_` / `_LogToFile_`.

I couldn't find anyone using `_Log_` (_camel case_) across GitHub.

**You can safely use this in your own libraries**.

> _I also don't like to "sign" my own work, so I didn't want something like `<Mrowr/Logging.h>`_

## Log Levels?

Meh.

Use your own logger if you want log levels.

I really wanted **one** simple `_Log_` macro that would work for all libraries.

## How?

I simplified it all down to two macros:

```cpp
// Log a message
_Log_("A great number is: {}", 42);

// Set a target filename for the log
_LogToFile_("my.log"); // (Optional)
```

> _Recommendation: never use `_LogToFile_` in libraries. It's global. Let users configure this._  
> _(You can always provide your own interface for users to configure it)_

This makes it _super easy_ for folks to use their own logging libraries.

### No Logging

By default, `_Log_` is defined as a macro that does nothing.

So libraries can safely `_Log_` and it won't do anything.

### spdlog

If `spdlog` headers are detected when `<_Log_>` is included, then `_Log_` is defined as a macro that uses `spdlog`.

If no target filename is set via `_LogToFile_`, then `spdlog` will log to `stderr`.

> Note: `_LogToFile_` must be called before any calls to `_Log_` or the default `stderr` logger will be used.

### Bring Your Own Logger

Easy.

Just define `_Log_` before including any library headers.

If a `_Log_` macro is defined, then this library will use it.

> Optionally also define `_LogToFile_` (defaults to an empty macro).

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
