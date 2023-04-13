# `#include <_Logging_.h>`

```cpp
#include <_Logging_.h>

int main() { _Log_("A great number is: {}", 42); }
```

## What?

A simple logging interface for C++ libraries.

## Why?

I want my libraries to support logs of logging.

But I want folks to be able to BYOL: **B**ring **Y**our **O**wn **L**ogger.

## Naming?

I want to use names that are _very_ unlikely to conflict with other libraries, so you can _very_ **safely** use this in your own libraries.

Hence `_Logging_.h` and `_Log_`.

## How?

I simplified it all down to two macros:

```cpp
// Log a message
_Log_("A great number is: {}", 42);

// Set a target filename for the log
_LogToFile_("my.log"); // (Optional)
```

This makes it _super easy_ for folks to use their own logging libraries.

### No Logging

By default, `_Log_` is defined as a macro that does nothing.

So libraries can safely `_Log_` and it won't do anything.

### spdlog

If `spdlog` headers are detected when `<Logging.h>` is included, then `_Log_` is defined as a macro that uses `spdlog`.

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
