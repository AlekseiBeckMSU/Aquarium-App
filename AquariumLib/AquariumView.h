/**
 * @file AquariumView.h
 * @author Alex Beck
 *
 * AquariumView class that displays the aquarium
 */
#include "Aquarium.h"
#ifndef AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
#define AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
/**
 * Class shows the aquarium
 */
class AquariumView : public wxWindow {

private:
    void OnPaint(wxPaintEvent& event);
    void OnAddFishBetaFish(wxCommandEvent& event);
    void OnAddFishAngelFish(wxCommandEvent& event);
    void OnAddFishAnglerFish(wxCommandEvent& event);
    void OnAddFishDovahfinFish(wxCommandEvent& event);
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent &event);
    void OnLeftDoubleClickDown(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
    /// An object that describes our aquarium
    Aquarium  mAquarium;
    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;
public:
    void Initialize(wxFrame* parent);
};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
