// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include <mvvm/model/modelutils.h>

using namespace ModelView;

//! Removes and deletes item from its model.

void Utils::DeleteItemFromModel(SessionItem* item)
{
    auto model = item->model();
    if (!model)
        return;

    model->removeItem(item->parent(), item->parent()->tagRowOfItem(item));
}

//! Moves item up (decrements row of the item). Works on children belonging to single tag.

void Utils::MoveUp(SessionItem* item)
{
    auto tagrow = item->parent()->tagRowOfItem(item);
    if (tagrow.row == 0)
        return; // item already at the top
    item->model()->moveItem(item, item->parent(), {tagrow.tag, tagrow.row - 1});
}

//! Moves item down (increments row of the item). Works on children belonging to single tag.

void Utils::MoveDown(SessionItem* item)
{
    auto tagrow = item->parent()->tagRowOfItem(item);
    if (tagrow.row == item->parent()->childrenCount() - 1)
        return; // item already at the buttom
    item->model()->moveItem(item, item->parent(), {tagrow.tag, tagrow.row + 1});
}
