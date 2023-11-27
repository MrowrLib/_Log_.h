#pragma once

// First, try spdlog in case it's available
#include "Adapters/spdlog/_LogToFile_.h"  // IWYU pragma: keep

// Then fall back to an empty definition
#include "Adapters/none/_LogToFile_.h"  // IWYU pragma: keep
