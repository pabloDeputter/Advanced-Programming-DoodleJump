//
// Created by Pablo Deputter on 13/12/2021.
//

#include "HighScore.h"

#include <algorithm>

HighScore& HighScore::getInstance()
{
        static HighScore instance("resource/highscore.txt", 10);
        return instance;
}

void HighScore::load()
{
        // Open file as input
        std::ifstream file(mPath);
        // If file can't be opened, throw exception and return
        if (!file.is_open()) {
                throw(Utils::FileException(std::move(mPath), "HighScore"));
                return;
        }
        // Read file
        std::string line;
        while (std::getline(file, line)) {
                // Find name and score in line
                std::string name = line.substr(0, line.find(" -"));
                line.erase(0, line.find(" -") + 2);
                std::string score = line.substr(1, line.find('-'));
                // Create new score
                std::shared_ptr<HighScoreData> newScore = std::make_shared<HighScoreData>(std::stoi(score), name);
                add(newScore);
        }
        file.close();
}

void HighScore::save()
{
        // Open file as output
        std::ofstream file(mPath);
        // If file can't be opened, throw exception and return
        if (!file.is_open()) {
                throw(Utils::FileException(std::move(mPath), "HighScore"));
                return;
        }
        // Write every high score to file
        for (const auto& i : mScores) {
                file << *i;
        }
        file.close();
}

unsigned int HighScore::add(const std::shared_ptr<HighScoreData>& score)
{
        // If new Score is less or equal to last score, return
        if (mScores.size() == mQuantity && mScores.back()->mScore >= score->mScore) {
                return 11;
        }

        // Find index to insert new score
        auto index = std::lower_bound(
            std::begin(mScores), std::end(mScores), score,
            [](const std::shared_ptr<HighScoreData>& lhs, const std::shared_ptr<HighScoreData>& rhs) -> bool {
                    // Return true if lhs's score is greater than rhs's
                    return lhs->mScore > rhs->mScore;
            });
        // Insert new score at right index
        mScores.insert(index, score);

        // Remove last element if mScores exceed quantity
        if (mScores.size() > mQuantity) {
                mScores.erase(std::end(mScores) - 1);
        }
        return index - std::begin(mScores);
}

//[[maybe_unused]] int HighScore::getHighScore() const
//{
//        // If no scores are stored high score is equal to 0
//        if (mScores.empty()) {
//                return 0;
//        }
//        return mScores.front()->mScore;
//}

bool HighScore::isHighScore(int score) const
{
        // If stored high scores does not exceed capacity new score is automatically a new high score
        // Else check if it is higher than the lowest high score
        if (mScores.size() < mQuantity || score > mScores.back()->mScore) {
                return true;
        }
        return false;
}

void HighScore::changeName(const std::string& newName, unsigned int index)
{
        if (index < 0 || index > mScores.size()) {
                return;
        }
        mScores[index]->mName = newName;
}
