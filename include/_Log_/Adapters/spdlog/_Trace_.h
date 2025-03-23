#pragma once

#ifndef _Trace_
    #if __has_include(<spdlog/spdlog.h>)
        #include "Adapter.h"  // IWYU pragma: export

        #define _Trace_(...)                                                              \
            SPDLOG_LOGGER_TRACE(                                                          \
                _Log_::Adapters::Spdlog::SpdlogAdapter::singleton().logger(), __VA_ARGS__ \
            )

    #endif
#endif
