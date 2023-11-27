#pragma once

#include "_Log_.h"

#ifndef _Error_
    #if __has_include(<spdlog/spdlog.h>)

        #define _Error_(...)                                                                 \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().GetSpdlogLogger()->error( \
                __VA_ARGS__                                                                  \
            )

    #endif
#endif

#ifndef _Error_
    #define _Error_(...) _Log_(__VA_ARGS__)
#endif
