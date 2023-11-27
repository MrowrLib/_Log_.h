#pragma once

#include "Adapter.h"  // IWYU pragma: keep

#ifndef _Debug_
    #if __has_include(<spdlog/spdlog.h>)

        #define _Debug_(...)                                                                 \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().GetSpdlogLogger()->debug( \
                __VA_ARGS__                                                                  \
            )

    #endif
#endif
