#pragma once

#ifndef _SetLogLevel_
    #if __has_include(<spdlog/spdlog.h>)
        #include "Adapter.h"  // IWYU pragma: export

        #define _SetLogLevel_(LEVEL)                                                 \
            _Log_::Adapters::Spdlog::SpdlogAdapter::singleton().logger()->set_level( \
                spdlog::level::LEVEL                                                 \
            )

    #endif
#endif
