#pragma once

#include "_Log_.h"

#ifndef _Critical_
    #if __has_include(<spdlog/spdlog.h>)

        #define _Critical_(...)                                                                 \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().GetSpdlogLogger()->critical( \
                __VA_ARGS__                                                                     \
            )

    #endif
#endif

#ifndef _Critical_
    #define _Critical_(...) _Log_(__VA_ARGS__)
#endif
