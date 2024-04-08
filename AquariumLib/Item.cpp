/**
 * @file Item.cpp
 * @author Alex Beck
 *
 * Base class for any item in our aquarium.
 */

#include "pch.h"
#include "Item.h"
#include "Aquarium.h"

/**
 * Destructor
 */
Item::~Item()
{

}
/**
 * Constructor
 * @param aquarium The aquarium this item is a member of
 */
Item::Item(Aquarium *aquarium) : mAquarium(aquarium)
{

}
/**
 * returns the aquarium object to access aquarium
 * @return mAquarium The aquarium object
 */
Aquarium * Item::GetAquarium()
{
    return mAquarium;
};
/**
 * Constructor
 * @param x the X axis value of the object
 * @param y the Y axis value of the object
 */
void Item::DoubleLeftClick(double x, double y)
{
    // while fish are being pushed keep looping until there are no more fish
    // stops once UnrelentingForceShout returns false/doesn't have anymore fish to push in area
    while(GetAquarium()->UnrelentingForceShout(GetX(),GetY()))
    {
        // doesn't need code inside the loop as the condition is calling unrelentingforceshout
    }
}