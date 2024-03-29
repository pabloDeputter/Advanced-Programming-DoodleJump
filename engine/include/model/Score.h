//
// Created by Pablo Deputter on 07/12/2021.
//

#ifndef DOODLEJUMP_SCORE_H
#define DOODLEJUMP_SCORE_H

#include "model/Entity.h"

#include "observer/Events.h"

#include "observer/Subject.h"

/**
 * @brief Namespace holds Models
 */
namespace Model {
/**
 * @brief Class for Score of Game
 */
class Score : public Entity, public Observer::Observer, public IEventHandler
{
private:
        std::weak_ptr<Model::Entity> mLastCollision; /**< Pointer to last Entity Player has collided with */
        int mCoins;                                  /**< Total coins collected this game */
private:
        /**
         * @brief On trigger of Subject
         * @param type EventType - type of event
         * @param event Event - Pointer to event
         */
        void onTrigger(EventType type, const std::shared_ptr<Event>& event) override { event->send(*this); }
        /**
         * @brief Handle NewMaxHeightEvent
         * @param event NewMaxHeightEvent
         */
        void handleEvent(const NewMaxHeightEvent& event) override;
        /**
         * Handle CollisionEvent
         * @param event CollisionEvent
         */
        void handleEvent(const CollisionEvent& event) override;
        /**
         * @brief Get type of Score
         * @return Model::Type - type of Score
         */
        [[nodiscard]] Model::Type getType() const override { return Model::eScore; }
        /**
         * @brief Move Score
         * @param collision bool - collided ot not
         */
        void move(bool collision) override {}

public:
        /**
         * @brief Default constructor for Score object
         */
        Score() : mCoins(0) {}
        /**
         * @brief Default destructor for Score object
         */
        ~Score() override = default;
        /**
         * @brief Get score
         * @return int - score
         */
        [[nodiscard]] int getScore() const override { return mScore; }
        /**
         * @brief Add to score
         * @param score int - score to be added
         */
        void setScore(int score) override { Score::mScore += score; }
        /**
         * @brief Get collected coins
         * @return int - total amount of collected coins
         */
        [[nodiscard]] int getCoins() const override { return mCoins; }
};
} // namespace Model

#endif // DOODLEJUMP_SCORE_H
