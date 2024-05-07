#pragma once

#include "Adapter.h"  // IWYU pragma: keep

#ifndef _Fatal_
    #if __has_include(<spdlog/spdlog.h>)

        #define _Fatal_(...)                                                                    \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().GetSpdlogLogger()->critical( \
                __VA_ARGS__                                                                     \
            )

    #endif
#endif
