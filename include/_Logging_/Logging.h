#pragma once

#ifndef _Log_
    #if __has_include(<spdlog/spdlog.h>)
        #include "spdlog.h"
    #else
        #define _Log_(...)
    #endif
#endif

#ifndef _LogToFile_
    #define _LogToFile_(...)
#endif
