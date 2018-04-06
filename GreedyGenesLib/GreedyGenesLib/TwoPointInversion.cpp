 
#include "TwoPointInversion.h"

#include <random>
#include <algorithm>

void TwoPointInversion::Inverse(Generation& gen)
{
    std::random_shuffle(std::begin(gen), std::end(gen));

    const size_t upTo = gen.size() / m_rate;

    for (size_t i = 0; i != upTo; ++i)
    {
        auto& chromosome = gen[i];
        auto& genes = chromosome->Representation();

        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, genes.size() - 1);

        auto point1 = dist(rng);
        auto point2 = dist(rng);

        if (point1 > point2)
            std::swap(point1, point2);

        const auto beg = std::begin(genes);
        std::reverse(beg + point1, beg + point2 + 1);
    }
}
