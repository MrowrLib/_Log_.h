#pragma once

#ifndef _Fatal_
    #if __has_include(<spdlog/spdlog.h>)
        #include "Adapter.h"  // IWYU pragma: export

        #define _Fatal_(...)                                                              \
            SPDLOG_LOGGER_CRITICAL(                                                       \
                _Log_::Adapters::Spdlog::SpdlogAdapter::singleton().logger(), __VA_ARGS__ \
            )

    #endif
#endif
