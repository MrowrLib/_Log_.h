#pragma once

#ifndef _Error_
    #if __has_include(<spdlog/spdlog.h>)
        #include "Adapter.h"  // IWYU pragma: export

        #define _Error_(...)                                                              \
            SPDLOG_LOGGER_ERROR(                                                          \
                _Log_::Adapters::Spdlog::SpdlogAdapter::singleton().logger(), __VA_ARGS__ \
            )

    #endif
#endif
