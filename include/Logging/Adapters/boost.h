#pragma once

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>

#include "../Config.h"

namespace Logging::Adapters {

    class BoostLogAdapter {
        ~BoostLogAdapter()                                 = default;
        BoostLogAdapter(const BoostLogAdapter&)            = delete;
        BoostLogAdapter(BoostLogAdapter&&)                 = delete;
        BoostLogAdapter& operator=(const BoostLogAdapter&) = delete;
        BoostLogAdapter& operator=(BoostLogAdapter&&)      = delete;

        BoostLogAdapter() {
            if (Config::LogFilePath.empty()) {
                boost::log::add_console_log(std::cout, boost::log::keywords::format = "%Message%");
            } else {
                boost::log::add_file_log(
                    boost::log::keywords::file_name  = Config::LogFilePath,
                    boost::log::keywords::format     = "%Message%",
                    boost::log::keywords::auto_flush = true
                );
            }
            boost::log::core::get()->set_filter(
                boost::log::trivial::severity >= boost::log::trivial::trace
            );
        }

    public:
        boost::log::sources::severity_logger<boost::log::trivial::severity_level> BoostLogger;

        static BoostLogAdapter& GetSingleton() {
            static BoostLogAdapter singleton;
            return singleton;
        }
    };
}

#define Logging_Log(text, ...)                                                                    \
    BOOST_LOG_SEV(                                                                                \
        Logging::Adapters::BoostLogAdapter::GetSingleton().BoostLogger, boost::log::trivial::info \
    ) << (text)
