#pragma once

// First, try spdlog in case it's available
#include "Adapters/spdlog/_Error_.h"  // IWYU pragma: keep

// Then fall back to an empty definition
#include "Adapters/none/_Error_.h"  // IWYU pragma: keep
