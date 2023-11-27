#pragma once

// If no one has set the default log level, set it to `info`
#include "LogLevels/info.h"  // IWYU pragma: keep

// First, try spdlog in case it's available
#include "Adapters/spdlog/_Log_.h"  // IWYU pragma: keep

// Then fall back to an empty definition
#include "Adapters/none/_Log_.h"  // IWYU pragma: keep
