#pragma once

#if __has_include(<spdlog/spdlog.h>)
    #include "Adapters/spdlog.h"
#elif __has_include(<boost/log/core.hpp>)
    #include "Adapters/boost.h"
#else
    #error "No logging library found"
#endif
