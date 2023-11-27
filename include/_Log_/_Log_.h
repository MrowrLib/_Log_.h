#pragma once

#ifndef _Log_DefaultLevel_
    #define _Log_DefaultLevel_ info
#endif

#ifndef _Log_
    #if __has_include(<spdlog/spdlog.h>)

        #include <spdlog/sinks/basic_file_sink.h>
        #include <spdlog/sinks/stdout_color_sinks.h>
        #include <spdlog/spdlog.h>

        #include <functional>
        #include <string>

namespace _Log_ {

    //! Feel free to place your adapters here!
    namespace Adapters {

        //! Namespace containing everything needed for the spdlog adapter.
        namespace Spdlog {

            class SpdlogAdapter {
                ~SpdlogAdapter()                               = default;
                SpdlogAdapter(const SpdlogAdapter&)            = delete;
                SpdlogAdapter(SpdlogAdapter&&)                 = delete;
                SpdlogAdapter& operator=(const SpdlogAdapter&) = delete;
                SpdlogAdapter& operator=(SpdlogAdapter&&)      = delete;

                std::shared_ptr<spdlog::logger> _spdlogLogger{nullptr};
                std::string                     _logFilePath;

                void ReconfigureSpdlogger() {
                    if (_spdlogLogger) spdlog::drop("basic_logger");
                    if (_logFilePath.empty()) _spdlogLogger = spdlog::stderr_color_mt("console");
                    else
                        _spdlogLogger = spdlog::basic_logger_mt("basic_logger", _logFilePath, true);
                    _spdlogLogger->set_level(spdlog::level::trace);
                    _spdlogLogger->flush_on(spdlog::level::trace);
                    _spdlogLogger->set_pattern("%v");
                }

            public:
                SpdlogAdapter() = default;

                void SetLogFilePath(const std::string& logFilePath) {
                    if (_logFilePath == logFilePath) return;
                    _logFilePath = logFilePath;
                    ReconfigureSpdlogger();
                }

                std::shared_ptr<spdlog::logger>& GetSpdlogLogger() {
                    if (!_spdlogLogger) ReconfigureSpdlogger();
                    return _spdlogLogger;
                }

                static SpdlogAdapter& GetSingleton() {
                    static SpdlogAdapter singleton;
                    return singleton;
                }

                class OnLoadMacroHelperFunctionRunner {
                    std::function<void()> _function;

                public:
                    OnLoadMacroHelperFunctionRunner(std::function<void()> function)
                        : _function(function) {
                        _function();
                    }
                };
            };
        }
    }
}

        #define _Log_(...)                                         \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton() \
                .GetSpdlogLogger()                                 \
                ->_Log_DefaultLevel_(__VA_ARGS__)

        #define _LogToFile_(filePath)                                                              \
            _Log_::Adapters::Spdlog::SpdlogAdapter::OnLoadMacroHelperFunctionRunner                \
                __Log__spdlogLogFilePathSetup {                                                    \
                []() {                                                                             \
                    _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().SetLogFilePath(filePath \
                    );                                                                             \
                }                                                                                  \
            }

        #define _SetLogLevel_(LEVEL)                                                             \
            _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().GetSpdlogLogger()->set_level( \
                spdlog::level::LEVEL                                                             \
            )

    #endif
#endif

#ifndef _Log_
    #define _Log_(...)
#endif

#ifndef _LogToFile_
    #define _LogToFile_(...)
#endif

#ifndef _SetLogLevel_
    #define _SetLogLevel_(...)
#endif
