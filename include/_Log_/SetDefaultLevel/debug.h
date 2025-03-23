#pragma once

#ifdef _Log_
    #undef _Log_
#endif

#define _Log_(...) \
    SPDLOG_LOGGER_DEBUG(_Log_::Adapters::Spdlog::SpdlogAdapter::singleton().logger(), __VA_ARGS__)
