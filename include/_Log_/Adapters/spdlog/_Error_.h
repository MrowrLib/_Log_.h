#pragma once

#include "Adapter.h"  // IWYU pragma: keep

#ifndef _Error_
    #if __has_include(<spdlog/spdlog.h>)

        #define _Error_(...)                                                                 \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().GetSpdlogLogger()->error( \
                __VA_ARGS__                                                                  \
            )

    #endif
#endif
