#pragma once

#include "Chromosome.h"
#include <memory>
#include <vector>

using ChromosomePtr = std::shared_ptr<Chromosome>;

using Generation = std::vector<ChromosomePtr>;
