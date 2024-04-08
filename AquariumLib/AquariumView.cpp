/**
 * @file AquariumView.cpp
 * @author Alex Beck
 *
 * AquariumView class that displays the aquarium
 */
#include "pch.h"
#include <wx/dcbuffer.h>
#include "AquariumView.h"
#include "ids.h"
#include "FishBeta.h"
#include "FishAngel.h"
#include "FishAngler.h"
#include "FishDovahfin.h"
#include "Aquarium.h"
using namespace std;
/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBetaFish, this, IDM_ADDFISHBETA);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishAngelFish, this, IDM_ADDFISHANGEL);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishAnglerFish, this, IDM_ADDFISHANGLER);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishDovahfinFish, this, IDM_ADDFISHDOVAHFIN);
    Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
    Bind(wxEVT_LEFT_DCLICK, &AquariumView::OnLeftDoubleClickDown, this);
    Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);
}
/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void AquariumView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);
    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();
    mAquarium.OnDraw(&dc);
}
/**
 * Menu hander for Add Fish>Beta Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishBetaFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishBeta>(&mAquarium);
    mAquarium.Add(fish);
    Refresh();
}
/**
 * Menu hander for Add Fish>Angel Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishAngelFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishAngel>(&mAquarium);
    mAquarium.Add(fish);
    Refresh();
}
/**
 * Menu hander for Add Fish>Angler Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishAnglerFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishAngler>(&mAquarium);
    mAquarium.Add(fish);
    Refresh();
}
/**
 * Menu hander for Add Fish>Dovahfin Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishDovahfinFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishDovahfin>(&mAquarium);
    mAquarium.Add(fish);
    Refresh();
}
/**
 * Handle the left mouse button down event
 * @param event
 */
void AquariumView::OnLeftDown(wxMouseEvent &event)
{
    mGrabbedItem = mAquarium.HitTest(event.GetX(), event.GetY());
    if (mGrabbedItem != nullptr)
    {
        mAquarium.MoveToFront(mGrabbedItem);
    }
}

/**
* Handle the left mouse button up event
* @param event
*/
void AquariumView::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}
/**
* Handle the left mouse button double click down event
* @param event
*/
void AquariumView::OnLeftDoubleClickDown(wxMouseEvent &event)
{
    double currentFishX = event.GetX();
    double currentFishY = event.GetY();
    auto fish = mAquarium.HitTest(currentFishX,currentFishY);
    // if fish is at the location of double click
    if (fish != nullptr)
    {
        // calls doubleleftclick onto the fish
        fish->DoubleLeftClick(currentFishX,currentFishY);
        Refresh();
    }
}

/**
* Handle the left mouse button hold down event
* @param event
*/
void AquariumView::OnMouseMove(wxMouseEvent &event)
{
    // See if an item is currently being moved by the mouse
    if (mGrabbedItem != nullptr)
    {
        // If an item is being moved, we only continue to
        // move it while the left button is down.
        if (event.LeftIsDown())
        {
            mGrabbedItem->SetLocation(event.GetX(), event.GetY());
        }
        else
        {
            // When the left button is released, we release the
            // item.
            mGrabbedItem = nullptr;
        }

        // Force the screen to redraw
        Refresh();
    }
}