#pragma once

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <functional>
#include <string>

#include "_Log_\Adapters\spdlog\Adapter.h"

namespace _Log_ {
    namespace Adapters {
        namespace Spdlog {

            void SpdlogAdapter::reset() {
                if (_logFilePath.empty()) {
                    if (auto defaultLogger = spdlog::default_logger()) {
                        _spdlogLogger = defaultLogger;
                        _spdlogLogger->set_level(spdlog::level::trace);
                        _spdlogLogger->flush_on(spdlog::level::trace);
                        return;
                    }
                }

                if (_spdlogLogger) spdlog::drop("basic_logger");

                if (_logFilePath.empty()) _spdlogLogger = spdlog::stderr_color_mt("console");
                else _spdlogLogger = spdlog::basic_logger_mt("basic_logger", _logFilePath, true);

                _spdlogLogger->set_level(spdlog::level::trace);
                _spdlogLogger->flush_on(spdlog::level::trace);
                _spdlogLogger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%s:%#] [%l] %v");
            }

            void SpdlogAdapter::set_filepath(const std::string& logFilePath) {
                if (_logFilePath == logFilePath) return;
                _logFilePath = logFilePath;
                reset();
            }

            const std::string& SpdlogAdapter::filepath() const { return _logFilePath; }

            void SpdlogAdapter::set_logger(const std::shared_ptr<spdlog::logger>& spdlogLogger) {
                _spdlogLogger = spdlogLogger;
            }

            std::shared_ptr<spdlog::logger>& SpdlogAdapter::logger() {
                if (!_spdlogLogger) reset();
                return _spdlogLogger;
            }

            SpdlogAdapter& SpdlogAdapter::singleton() {
                static SpdlogAdapter singleton;
                return singleton;
            }

            SpdlogAdapter::~SpdlogAdapter() = default;

            SpdlogAdapter::OnLoadMacroHelperFunctionRunner::OnLoadMacroHelperFunctionRunner(
                std::function<void()> function
            )
                : _function(function) {
                _function();
            }

        }
    }
}
