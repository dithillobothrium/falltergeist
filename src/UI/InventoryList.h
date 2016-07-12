/*
 * InventoryList.h
 *
 *  Created on: Jul 11, 2016
 *      Author: isivkov
 */

#ifndef FALLTERGEIST_SRC_STATE_INVENTORYLIST_H
#define FALLTERGEIST_SRC_STATE_INVENTORYLIST_H

#include <map>

#include "ItemsList.h"

namespace Falltergeist
{
namespace UI
{

class InventoryList: public Falltergeist::UI::ItemsList
{
public:
    InventoryList(const Point& pos);

    void setSlotItem(std::unique_ptr<InventoryItem> item);

//    void setLeftHandSlot(std::unique_ptr<InventoryItem> item);
//
//    void setRightHandSlot(std::unique_ptr<InventoryItem> item);

    virtual void handle(Event::Event* event) override;

    virtual void think() override;

    virtual void render(bool eggTransparency = false) override;

    virtual void setPosition(const Point& pos) override;


protected:
    std::vector< std::pair< Point, std::unique_ptr<InventoryItem> > > _slotItems;

    void updatePos();

    Point _relativePos;
};

}
}


#endif /* FALLTERGEIST_SRC_STATE_INVENTORYLIST_H */
