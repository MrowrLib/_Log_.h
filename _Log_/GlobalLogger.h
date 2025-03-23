#pragma once

#include "ILogger.h"

namespace _Log_ {
    ILogger* get();
    void     set(ILogger* logger);
}
