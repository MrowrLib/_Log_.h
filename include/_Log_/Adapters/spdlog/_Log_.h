#pragma once

#include "Adapter.h"  // IWYU pragma: keep

#ifndef _Log_
    #if __has_include(<spdlog/spdlog.h>)

        #define _Log_(...)                                         \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton() \
                .GetSpdlogLogger()                                 \
                ->_Log_DefaultLevel_(__VA_ARGS__)

    #endif
#endif
