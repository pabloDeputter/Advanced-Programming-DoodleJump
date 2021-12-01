//
// Created by Pablo Deputter on 21/11/2021.
//

#include "util/Collision.h"

using namespace Utils;
#include <iostream>
bool Collision::checkCollision(const std::shared_ptr<Model::Entity>& l, const std::shared_ptr<Model::Entity>& r)
{
        // TODO - transform not eerder al gedaan hebben ergens
        auto a = Utils::Camera::getInstance().inverseTransform(l->getWidth(), l->getHeight());
        auto lWidth = a.first * 0.9f;
        auto lHeight = a.second * 0.9f;

        auto b = Utils::Camera::getInstance().inverseTransform(r->getWidth(), r->getHeight());
        auto rWidth = b.first * 0.9f;
        auto rHeight = b.second * 0.9f;

        if (l->getX() + lWidth >= r->getX() &&  // l right edge is past r left edge
            l->getX() <= r->getX() + rWidth &&  // l left edge is past r right edge
            l->getY() + lHeight >= r->getY() && // l top edge is past r bottom edge
            l->getY() <= r->getY() + rHeight)   // l bottom edge is past r top edge
                return true;
        return false;
}