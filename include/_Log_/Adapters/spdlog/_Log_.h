#pragma once

#ifndef _Log_
    #if __has_include(<spdlog/spdlog.h>)
        #include "Adapter.h"  // IWYU pragma: export

        // Default it to INFO
        #define _Log_(...)                                                                \
            SPDLOG_LOGGER_INFO(                                                           \
                _Log_::Adapters::Spdlog::SpdlogAdapter::singleton().logger(), __VA_ARGS__ \
            )

    #endif
#endif
