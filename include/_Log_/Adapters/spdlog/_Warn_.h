#pragma once

#ifndef _Warn_
    #if __has_include(<spdlog/spdlog.h>)
        #include "Adapter.h"  // IWYU pragma: export

        #define _Warn_(...)                                                               \
            SPDLOG_LOGGER_WARN(                                                           \
                _Log_::Adapters::Spdlog::SpdlogAdapter::singleton().logger(), __VA_ARGS__ \
            )

    #endif
#endif
