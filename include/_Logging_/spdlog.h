#pragma once

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <functional>
#include <string>

namespace _Logging_ {

    //! Feel free to place your adapters here!
    namespace Adapters {

        //! Namespace containing everything needed for the spdlog adapter.
        namespace Spdlog {

            //! The path to the log file used by spdlog.
            std::string LogFilePath;

            class SpdlogAdapter {
                ~SpdlogAdapter()                               = default;
                SpdlogAdapter(const SpdlogAdapter&)            = delete;
                SpdlogAdapter(SpdlogAdapter&&)                 = delete;
                SpdlogAdapter& operator=(const SpdlogAdapter&) = delete;
                SpdlogAdapter& operator=(SpdlogAdapter&&)      = delete;

                SpdlogAdapter() {
                    if (LogFilePath.empty()) SpdlogLogger = spdlog::stderr_color_mt("console");
                    else SpdlogLogger = spdlog::basic_logger_mt("basic_logger", LogFilePath, true);
                    SpdlogLogger->set_level(spdlog::level::trace);
                    SpdlogLogger->flush_on(spdlog::level::trace);
                    SpdlogLogger->set_pattern("%v");
                }

            public:
                std::shared_ptr<spdlog::logger> SpdlogLogger;

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

#define _Log_(...) \
    _Logging_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().SpdlogLogger->info(__VA_ARGS__)

#define _LogToFile_(filePath)                                                   \
    _Logging_::Adapters::Spdlog::SpdlogAdapter::OnLoadMacroHelperFunctionRunner \
        __Logging__spdlogLogFilePathSetup {                                     \
        []() { _Logging_::Adapters::Spdlog::LogFilePath = filePath; }           \
    }