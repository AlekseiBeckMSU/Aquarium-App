/**
 * @file FishAngler.h
 * @author Alex Beck
 *
 * holds angler fish information
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHANGLER_H
#define AQUARIUM_AQUARIUMLIB_FISHANGLER_H
#include "Item.h"
/**
 * Class holds all artistic elements of the Angler fish
 */
class FishAngler : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;
public:

    void Draw(wxDC *dc) override;
    /// Default constructor (disabled)
    FishAngler() = delete;

    /// Copy constructor (disabled)
    FishAngler(const FishAngler &) = delete;

    /// Assignment operator
    void operator=(const FishAngler &) = delete;

    FishAngler(Aquarium* aquarium);
    bool HitTest(int x, int y) override;
    void DoubleLeftClick(double x, double y) override;
};
#endif //AQUARIUM_AQUARIUMLIB_FISHANGLER_H
