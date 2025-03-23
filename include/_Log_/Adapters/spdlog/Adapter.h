#pragma once

#if __has_include(<spdlog/spdlog.h>)

    // The compile macros should respect all the way down to trace
    #ifdef SPDLOG_ACTIVE_LEVEL
        #undef SPDLOG_ACTIVE_LEVEL
    #endif
    #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

    #ifndef FMT_UNICODE
        #define FMT_UNICODE 0
    #endif

    #include <spdlog/sinks/basic_file_sink.h>
    #include <spdlog/sinks/stdout_color_sinks.h>
    #include <spdlog/spdlog.h>

    #include <functional>
    #include <memory>
    #include <string>

namespace _Log_ {

    namespace Adapters {

        namespace Spdlog {

            class SpdlogAdapter {
                ~SpdlogAdapter();
                SpdlogAdapter(const SpdlogAdapter&)            = delete;
                SpdlogAdapter(SpdlogAdapter&&)                 = delete;
                SpdlogAdapter& operator=(const SpdlogAdapter&) = delete;
                SpdlogAdapter& operator=(SpdlogAdapter&&)      = delete;

                std::shared_ptr<spdlog::logger> _spdlogLogger{nullptr};
                std::string                     _logFilePath;

                void reset();

            public:
                SpdlogAdapter() = default;

                void               set_filepath(const std::string& logFilePath);
                const std::string& filepath() const;

                void set_logger(const std::shared_ptr<spdlog::logger>& spdlogLogger);
                std::shared_ptr<spdlog::logger>& logger();

                static SpdlogAdapter& singleton();

                class OnLoadMacroHelperFunctionRunner {
                    std::function<void()> _function;

                public:
                    OnLoadMacroHelperFunctionRunner(std::function<void()> function);
                };
            };

        }
    }
}

#endif
