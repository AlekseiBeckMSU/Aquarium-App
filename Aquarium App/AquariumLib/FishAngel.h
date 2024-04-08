/**
 * @file FishAngel.h
 * @author Alex Beck
 *
 * holds angel fish information
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHANGEL_H
#define AQUARIUM_AQUARIUMLIB_FISHANGEL_H
#include "Item.h"
/**
 * Class holds all artistic elements of the Angel fish
 */
class FishAngel : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;
public:

    void Draw(wxDC *dc) override;
    /// Default constructor (disabled)
    FishAngel() = delete;

    /// Copy constructor (disabled)
    FishAngel(const FishAngel &) = delete;

    /// Assignment operator
    void operator=(const FishAngel &) = delete;

    FishAngel(Aquarium* aquarium);
    bool HitTest(int x, int y) override;
    void DoubleLeftClick(double x, double y) override;
};
#endif //AQUARIUM_AQUARIUMLIB_FISHANGEL_H
