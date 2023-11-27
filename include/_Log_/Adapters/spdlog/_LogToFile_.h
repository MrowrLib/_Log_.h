#pragma once

#include "Adapter.h"  // IWYU pragma: keep

#ifndef _LogToFile_
    #if __has_include(<spdlog/spdlog.h>)

        #define _LogToFile_(filePath)                                                              \
            _Log_::Adapters::Spdlog::SpdlogAdapter::OnLoadMacroHelperFunctionRunner                \
                __Log__spdlogLogFilePathSetup {                                                    \
                []() {                                                                             \
                    _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().SetLogFilePath(filePath \
                    );                                                                             \
                }                                                                                  \
            }

    #endif
#endif
