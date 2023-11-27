#pragma once

// First, try spdlog in case it's available
#include "Adapters/spdlog/_Trace_.h"  // IWYU pragma: keep

// Then fall back to an empty definition
#include "Adapters/none/_Trace_.h"  // IWYU pragma: keep
