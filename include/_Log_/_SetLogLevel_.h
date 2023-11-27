#pragma once

// First, try spdlog in case it's available
#include "Adapters/spdlog/_SetLogLevel_.h"  // IWYU pragma: keep

// Then fall back to an empty definition
#include "Adapters/none/_SetLogLevel_.h"  // IWYU pragma: keep
