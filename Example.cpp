// Uncomment to change the default log level of _Log_
// It MUST be defined BEFORE including _Log_.h
// #define _Log_DefaultLevel_ trace

#include <_Log_.h>

int main() {
    // Uncomment to test setting a specific log file path
    // _LogToFile_("Example.log");

    // Uncomment to test setting a specific log level
    // _SetLogLevel_(debug);

    _Trace_("Trace");
    _Debug_("Debug");
    _Info_("Info");
    _Warn_("Warn");
    _Error_("Error");
    _Critical_("Critical");

    // Standard '_Log_' which you get from just #include <_Log_/Log.h>
    // (INFO unless #define _Log_DefaultLevel_ is set BEFORE including _Log_.h)
    _Log_("Log");
}
