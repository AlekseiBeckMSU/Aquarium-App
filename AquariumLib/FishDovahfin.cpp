/**
 * @file FishDovahfin.cpp
 * @author Alex Beck
 *
 *  holds dovahfin fish information
 */

#include "pch.h"
#include <string>
#include "FishDovahfin.h"
#include "Aquarium.h"
#include "Item.h"
using namespace std;
/// Fish filename
const wstring FishDovahfinImageName = L"images/dovahfin.png";
/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishDovahfin::FishDovahfin(Aquarium *aquarium) : Item(aquarium)
{
    mFishImage = make_unique<wxImage>(FishDovahfinImageName, wxBITMAP_TYPE_ANY);
    mFishBitmap = make_unique<wxBitmap>(*mFishImage);
}
/**
 * Draw this fish
 * @param dc Device context to draw on
 */
void FishDovahfin::Draw(wxDC *dc)
{
    double wid = mFishBitmap->GetWidth();
    double hit = mFishBitmap->GetHeight();
    dc->DrawBitmap(*mFishBitmap,
                   int(GetX() - wid / 2),
                   int(GetY() - hit / 2));
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool FishDovahfin::HitTest(int x, int y)
{
    double wid = mFishBitmap->GetWidth();
    double hit = mFishBitmap->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    return !mFishImage->IsTransparent((int)testX, (int)testY);
}
/**
 * Double left click action, for Dovahfin fish, pushes fish away from Dovahfin fish
 * @param x X position to test
 * @param y Y position to test
 */
void FishDovahfin::DoubleLeftClick(double x, double y)
{
    // while fish are being pushed keep looping until there are no more fish
    // stops once UnrelentingForceShout returns false/doesn't have anymore fish to push in area
    while(GetAquarium()->UnrelentingForceShout(GetX(),GetY()))
    {
        // doesn't need code inside the loop as the condition is calling unrelentingforceshout
    }
}