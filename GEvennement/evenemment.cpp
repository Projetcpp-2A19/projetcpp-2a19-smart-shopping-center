#include "evenemment.h"

#include <utility>

class EvenemmentData : public QSharedData
{
public:
};

Evenemment::Evenemment()
    : data(new EvenemmentData)
{}

Evenemment::Evenemment(const Evenemment &rhs)
    : data{rhs.data}
{}

Evenemment::Evenemment(Evenemment &&rhs)
    : data{std::move(rhs.data)}
{}

Evenemment &Evenemment::operator=(const Evenemment &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return *this;
}

Evenemment &Evenemment::operator=(Evenemment &&rhs)
{
    if (this != &rhs)
        data = std::move(rhs.data);
    return *this;
}

Evenemment::~Evenemment() {}
