# `#include <_Logging_>`

```cpp
#include <_Logging_>

int main() { _Log_("A great number is: {}", 42); }
```

## Installation

```lua
-- xmake
add_repositories("MrowrLib https://github.com/MrowrLib/Packages.git")
add_requires("_Logging_")
```

```cmake
# CMake/vcpkg (coming soon)
```

## What?

A simple logging interface for C++ libraries.

## Why?

I want my libraries to all support logging.

But I want folks to be able to BYOL: **B**ring **Y**our **O**wn **L**ogger.

Want to use `spdlog`? Great!

This will _automatically_ detect `spdlog` and use it.

By default, however, it will do nothing.

## Naming?

Searching across GitHub, there are many libraries which...
- `#include <Logging_>` or `#include <Log.h>`
- Have a `Logging` or `Log` class or namespace
- Have a `Log` or `LOG` or `_log_` or `_LOG_` function or macro

Because _almost all_ of my libraries use this library, I wanted to make **sure** that this library's names were very, **_very_ unlikely to conflict with other libraries**.

Hence `#include <_Logging_>` and `_Log_` / `_LogToFile_`.

I couldn't find anyone using `_Log_()` (_camel case_) across GitHub.

**You can safely use this in your own libraries**.

> _I also don't like to "sign" my own work, so I didn't want something like `<Mrowr/Logging_>`_

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

If `spdlog` headers are detected when `<Logging_>` is included, then `_Log_` is defined as a macro that uses `spdlog`.

If no target filename is set via `_LogToFile_`, then `spdlog` will log to `stderr`.

> Reminder: `_LogToFile_` must be called before any library calls `_Log_`, or else the default `stderr` logger will be used.

### Bring Your Own Logger

Easy.

Just define `_Log_` before including any library headers.

If the `_Log_` macro is defined, then the library will use it.

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
