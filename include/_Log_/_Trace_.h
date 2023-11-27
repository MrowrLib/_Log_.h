#pragma once

#include "_Log_.h"

#ifndef _Trace_
    #if __has_include(<spdlog/spdlog.h>)

        #define _Trace_(...)                                                                 \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().GetSpdlogLogger()->trace( \
                __VA_ARGS__                                                                  \
            )

    #endif
#endif

#ifndef _Trace_
    #define _Trace_(...) _Log_(__VA_ARGS__)
#endif
