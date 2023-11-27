#pragma once

#include "_Log_.h"

#ifndef _Warn_
    #if __has_include(<spdlog/spdlog.h>)

        #define _Warn_(...)                                                                 \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().GetSpdlogLogger()->warn( \
                __VA_ARGS__                                                                 \
            )

    #endif
#endif

#ifndef _Warn_
    #define _Warn_(...) _Log_(__VA_ARGS__)
#endif
