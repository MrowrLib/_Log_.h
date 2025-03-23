#pragma once

// #include <_Log_.h> includes support for: _Log_, _Debug_, _Info_, _Warn_, _Error_, _Fatal_
#include "_Log_/_Debug_.h"  // IWYU pragma: export
#include "_Log_/_Error_.h"  // IWYU pragma: export
#include "_Log_/_Fatal_.h"  // IWYU pragma: export
#include "_Log_/_Info_.h"   // IWYU pragma: export
#include "_Log_/_Log_.h"    // IWYU pragma: export
#include "_Log_/_Trace_.h"  // IWYU pragma: export
#include "_Log_/_Warn_.h"   // IWYU pragma: export

// And provide _LogToFile_ and _SetLogLevel_
#include "_Log_/_LogToFile_.h"    // IWYU pragma: export
#include "_Log_/_SetLogLevel_.h"  // IWYU pragma: export
