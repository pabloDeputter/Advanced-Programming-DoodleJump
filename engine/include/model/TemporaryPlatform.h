//
// Created by Pablo Deputter on 05/12/2021.
//

#ifndef DOODLEJUMP_TEMPORARYPLATFORM_H
#define DOODLEJUMP_TEMPORARYPLATFORM_H

#include "Entity.h"

namespace Model {

class TemporaryPlatform : public Entity
{

public:
        TemporaryPlatform() = default;

        ~TemporaryPlatform() override = default;

        Model::Type getType() const override;

        void move(bool collision) override;
};
} // namespace Model

#endif // DOODLEJUMP_TEMPORARYPLATFORM_H