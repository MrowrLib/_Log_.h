#pragma once

#include "Adapter.h"  // IWYU pragma: keep

#ifndef _Info_
    #if __has_include(<spdlog/spdlog.h>)

        #define _Info_(...)                                                                 \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().GetSpdlogLogger()->info( \
                __VA_ARGS__                                                                 \
            )

    #endif
#endif
