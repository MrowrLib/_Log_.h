#pragma once

#include "LogLevel.h"

namespace _Log_ {
    struct ILogger {
        virtual ~ILogger()                                     = default;
        virtual bool        log(const char* message)           = 0;
        virtual bool        trace(const char* message)         = 0;
        virtual bool        debug(const char* message)         = 0;
        virtual bool        info(const char* message)          = 0;
        virtual bool        warn(const char* message)          = 0;
        virtual bool        error(const char* message)         = 0;
        virtual bool        critical(const char* message)      = 0;
        virtual bool        set_level(LogLevel level)          = 0;
        virtual LogLevel    level() const                      = 0;
        virtual bool        set_filepath(const char* filepath) = 0;
        virtual const char* filepath() const                   = 0;
        virtual bool        set_enabled(bool enabled)          = 0;
        virtual bool        enabled() const                    = 0;
    };
}
