/**
 * @file Aquarium.h
 * @author Alex Beck
 *
 * Class that holds all items/fish
 */
#include<memory>
#include<vector>
#include "Item.h"
#ifndef AQUARIUM_AQUARIUMLIB_AQUARIUM_H
#define AQUARIUM_AQUARIUMLIB_AQUARIUM_H
/**
 * Class holds all artistic elements of the display of aquarium
 */
class Aquarium
{
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use
    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<Item>> mItems;
    //  Aquarium * mAquarium;
    /// X location of the mouth relative to the center of the fish in pixels
    const int DovahfinMouthX = 95;

    /// Y location of the mouth relative to the center of the fish in pixels
    const int DovahfinMouthY = 20;

    /// Range of a thu'um in pixels in the X direction
    const int DovahfinThuumRange = 200;

    /// Spread of the thu'um in pixels in the Y direction up and down
    const int DovahfinThuumSpread = 160;

public:
    void OnDraw(wxDC *dc);
    Aquarium();
    void Add(std::shared_ptr<Item> item);
    std::shared_ptr<Item> HitTest(int x, int y);
    void MoveToFront(std::shared_ptr<Item> item);
    bool UnrelentingForceShout(double x, double y);
};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUM_H
