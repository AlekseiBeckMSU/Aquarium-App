/**
 * @file FishDovahfin.h
 * @author Alex Beck
 *
 * Dovahfin fish class
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHDOVAHFIN_H
#define AQUARIUM_AQUARIUMLIB_FISHDOVAHFIN_H

#include "Item.h"
/**
 * Class holds all artistic elements of the Dovahfin fish
 */
class FishDovahfin : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

public:
    void Draw(wxDC *dc) override;
    /// Default constructor (disabled)
    FishDovahfin() = delete;

    /// Copy constructor (disabled)
    FishDovahfin(const FishDovahfin &) = delete;

    /// Assignment operator
    void operator=(const FishDovahfin &) = delete;

    FishDovahfin(Aquarium* aquarium);
    bool HitTest(int x, int y) override;
    void DoubleLeftClick(double x, double y) override;
};


#endif //AQUARIUM_AQUARIUMLIB_FISHDOVAHFIN_H
