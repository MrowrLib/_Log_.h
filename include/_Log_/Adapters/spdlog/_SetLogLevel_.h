#pragma once

#include "Adapter.h"  // IWYU pragma: keep

#ifndef _SetLogLevel_
    #if __has_include(<spdlog/spdlog.h>)

        #define _SetLogLevel_(LEVEL)                                                             \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().GetSpdlogLogger()->set_level( \
                spdlog::level::LEVEL                                                             \
            )

    #endif
#endif
