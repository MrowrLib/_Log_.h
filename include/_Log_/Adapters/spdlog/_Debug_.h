#pragma once

#ifndef _Debug_
    #if __has_include(<spdlog/spdlog.h>)
        #include "Adapter.h"  // IWYU pragma: export

        #define _Debug_(...)                                                              \
            SPDLOG_LOGGER_DEBUG(                                                          \
                _Log_::Adapters::Spdlog::SpdlogAdapter::singleton().logger(), __VA_ARGS__ \
            )

    #endif
#endif
