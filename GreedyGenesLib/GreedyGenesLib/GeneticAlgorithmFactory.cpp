 
#include "GeneticAlgorithmFactory.h"

GeneticAlgorithmFactory& GeneticAlgorithmFactory::GetInstance()
{
    static GeneticAlgorithmFactory instance;
    return instance;
}
