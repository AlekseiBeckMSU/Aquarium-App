/**
 * @file FishBeta.h
 * @author Alex Beck
 *
 * holds beta fish information
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHBETA_H
#define AQUARIUM_AQUARIUMLIB_FISHBETA_H

#include "Item.h"
/**
 * Class holds all artistic elements of the Beta fish
 */
class FishBeta : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;
public:

    void Draw(wxDC *dc) override;
    /// Default constructor (disabled)
    FishBeta() = delete;

    /// Copy constructor (disabled)
    FishBeta(const FishBeta &) = delete;

    /// Assignment operator
    void operator=(const FishBeta &) = delete;

    FishBeta(Aquarium* aquarium);
    bool HitTest(int x, int y) override;
    void DoubleLeftClick(double x, double y) override;
};


#endif //AQUARIUM_AQUARIUMLIB_FISHBETA_H
