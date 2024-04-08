/**
 * @file Aquarium.cpp
 * @author Alex Beck
 *
 * Aquarium class holds all fish
 */
#include "pch.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include "FishAngel.h"
#include "FishAngler.h"
#include "FishDovahfin.h"
#include "Item.h"
using namespace std;

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;
/**
 * Add an item to the aquarium
 * @param item New item to add
 */
void Aquarium::Add(std::shared_ptr<Item> item)
{
    item->SetLocation(InitialX, InitialY);
    mItems.push_back(item);
}

/**
 * Draw the aquarium
 * @param dc The device context to draw on
 */
void Aquarium::OnDraw(wxDC *dc)
{
    dc->DrawBitmap(*mBackground, 0, 0);
    wxFont font(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);
    dc->SetTextForeground(wxColour(0, 64, 0));
    dc->DrawText(L"Under the Sea!", 10, 10);
    for (auto item : mItems)
    {
        item->Draw(dc);
    }
}
/**
 * Aquarium Constructor
 */
Aquarium::Aquarium()
{
    mBackground = make_unique<wxBitmap>(
        L"images/background1.png", wxBITMAP_TYPE_ANY);
}
/**
 * Test an x,y click location to see if it clicked
 * on some item in the aquarium.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Aquarium::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }
    return  nullptr;
}
/**
 * Test an x,y click location to see if it clicked
 * @param item shared pointer item holds values of the current fish
 */
void Aquarium::MoveToFront(shared_ptr<Item> item)
{
    auto loc = find(begin(mItems), end(mItems), item);
    if (loc != end(mItems))
    {
        mItems.erase(loc);
    }
    mItems.push_back(item);
}
/**
 * Move fish away from Dovahfin
 * @param x X axis location of the fish
 * @param y Y axis location of the fish
 * @returns Bool returns true if fish was moved, false if fish was not
 */
bool Aquarium::UnrelentingForceShout(double x, double y)
{
    for(auto fish : mItems)
    {
        double currentFishX = fish->GetX();
        double currentFishY = fish->GetY();
        double xDistance = currentFishX - (DovahfinMouthX + x);
        if (xDistance >= 0 && xDistance <= DovahfinThuumRange)
        {
            double yDistance = currentFishY - (DovahfinMouthY + y);
            if(abs(yDistance) <= DovahfinThuumSpread / 2)
            {
                if (fish != HitTest(x, y))
                {
                    fish->SetLocation(870, currentFishY);
                }
                // returns true if a fish is moved
                return true;
            }
        }
    }
    // returns false if a fish is not moved
    return false;
}
