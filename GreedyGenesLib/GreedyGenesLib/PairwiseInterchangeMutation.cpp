#include "stdafx.h"
#include "PairwiseInterchangeMutation.h"
#include <random>
#include <cassert>

void PairwiseInterchangeMutatation::Mutate(Generation& gen)
{
    if (gen.size() <= 2)
        return;

    std::random_shuffle(gen.begin(), gen.end());

    const size_t upTo = gen.size() / m_rate;

    for (size_t i = 0; i != upTo; ++i)
    {
        auto ch = gen[i];

        auto& interchange = ch->Representation();

        assert(interchange.size() > 2);

        std::random_shuffle(interchange.begin(), interchange.end());

        std::swap(interchange[0], interchange[1]);

        ChromosomePtr mutant = std::make_shared<Chromosome>(interchange);

        auto it = std::find_if(gen.begin(), gen.end(),
            [mutant](ChromosomePtr chromosome)
            {
                return chromosome->Representation() == mutant->Representation();
            });

        if (it == gen.end())
        {
            gen.push_back(mutant);
        }
    }
}

