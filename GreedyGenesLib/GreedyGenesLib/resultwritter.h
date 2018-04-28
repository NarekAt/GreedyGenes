#ifndef RESULTWRITER_H
#define RESULTWRITER_H

#include <string>
#include <memory>
#include <vector>

class IResultWritter
{
public:
    virtual std::string write(std::vector<uint64_t>& res) = 0;

    virtual ~IResultWritter() = default;
};

using IResultWritterPtr = std::shared_ptr<IResultWritter>;
#endif // RESULTWRITER_H
