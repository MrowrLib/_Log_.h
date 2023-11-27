#pragma once

#include "_Log_.h"

#ifndef _Debug_
    #if __has_include(<spdlog/spdlog.h>)

        #define _Debug_(...)                                                                 \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().GetSpdlogLogger()->debug( \
                __VA_ARGS__                                                                  \
            )

    #endif
#endif

#ifndef _Debug_
    #define _Debug_(...) _Log_(__VA_ARGS__)
#endif
