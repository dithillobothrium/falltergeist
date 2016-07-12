/*
 * InventoryList.cpp
 *
 *  Created on: Jul 11, 2016
 *      Author: isivkov
 */


#include "InventoryList.h"



namespace Falltergeist
{
namespace UI
{

//-----------------------------------------------------------------------------------------
InventoryList::InventoryList(const Point& pos ) : Falltergeist::UI::ItemsList(pos), _relativePos(pos)
{ }


//-----------------------------------------------------------------------------------------
void InventoryList::setSlotItem(std::unique_ptr<InventoryItem> item)
{
    _slotItems.push_back( std::pair<Point, std::unique_ptr<InventoryItem> >( item->position() ,std::move(item)) );
    updatePos();
}

//
////-----------------------------------------------------------------------------------------
//void InventoryList::setLeftHandSlot(std::unique_ptr<InventoryItem> item)
//{
//    _slotItems[1] = std::move(item);
//}
//
//
////-----------------------------------------------------------------------------------------
//void InventoryList::setRightHandSlot(std::unique_ptr<InventoryItem> item)
//{
//    _slotItems[2] = std::move(item);
//}

void InventoryList::handle(Event::Event* event)
{
    ItemsList::handle(event);

    for(auto& item: _slotItems)
    {
        item.second->handle(event);
    }
}

void InventoryList::think()
{
    ItemsList::think();

    for(auto& item: _slotItems)
    {
        item.second->think();
    }
}

//-----------------------------------------------------------------------------------------
void InventoryList::setPosition(const Point& pos)
{
    ItemsList::setPosition(pos);
    updatePos();
}


//-----------------------------------------------------------------------------------------
void InventoryList::updatePos()
{
    for(auto& item: _slotItems)
    {
        item.second->setPosition(position() + item.first - _relativePos);
    }
}


//-----------------------------------------------------------------------------------------
void InventoryList::render(bool eggTransparency)
{
    InventoryItem *draggedItem = nullptr;

    for(auto& item: _slotItems)
    {
        if(item.second->type() != InventoryItem::Type::DRAG)
        {
            item.second->render();
        }
        else
        {
            draggedItem = item.second.get();
        }
    }

    ItemsList::render(eggTransparency);

    if(draggedItem)
    {
        draggedItem->render();
    }
}


}
}
