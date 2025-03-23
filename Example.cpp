// Uncomment to change the default log level of _Log_
// It MUST be defined BEFORE including _Log_.h
// #define _Log_DefaultLevel_ error

// #include <_Log_/SetDefaultLevel/error.h>
// #include <_Log_/SetDefaultLevel/trace.h>

// And then this...
// #include <_Log_/_Log_.h>
// #include <_Log_/_SetLogLevel_.h>
#include <_Log_.h>

int main() {
    // Uncomment to test setting a specific log file path
    // _LogToFile_("Example2.log");

    // Uncomment to test setting a specific log level
    // _SetLogLevel_(trace);
    _SetLogLevel_(warn);

    _Trace_("Trace");
    _Debug_("Debug");
    _Debug_("Debug {}", 123);
    _Info_("Info {}", 420);
    _Warn_("Warn");
    _Error_("Error");
    _Fatal_("Fatal");

    // Standard '_Log_' which you get from just #include <_Log_/Log.h>
    // (INFO unless #define _Log_DefaultLevel_ is set BEFORE including _Log_.h)
    _Log_("Log!");
}
