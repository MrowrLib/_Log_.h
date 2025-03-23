#pragma once

#ifndef _LogToFile_
    #if __has_include(<spdlog/spdlog.h>)
        #include "Adapter.h"  // IWYU pragma: export

        #define _LogToFile_(filePath)                                                           \
            _Log_::Adapters::Spdlog::SpdlogAdapter::OnLoadMacroHelperFunctionRunner             \
                __Log__spdlogLogFilePathSetup {                                                 \
                []() {                                                                          \
                    _Log_::Adapters::Spdlog::SpdlogAdapter::singleton().set_filepath(filePath); \
                }                                                                               \
            }

    #endif
#endif
