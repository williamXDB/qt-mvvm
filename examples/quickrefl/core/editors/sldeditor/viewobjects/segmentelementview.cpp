// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include "segmentelementview.h"
#include "layerelementcontroller.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

//! The constructor
SegmentElementView::SegmentElementView()
    : QGraphicsItem(), m_rectangle(QRectF(0, 0, 0, 0)), m_brush(QBrush()), m_pen(QPen()),
      m_pos(QPointF(0, 0))
{
    setFlag(QGraphicsItem::ItemIsMovable);
}

//! The overriden paint method
void SegmentElementView::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setPen(m_pen);
    painter->setBrush(m_brush);
    painter->drawRect(m_rectangle);
}

//! The shape
QPainterPath SegmentElementView::shape() const
{
    QPainterPath path;
    path.addRect(m_rectangle);
    return path;
}

//! The bounding rectangle of the handle
QRectF SegmentElementView::boundingRect() const
{
    return m_rectangle;
}

//! On move update the model
void SegmentElementView::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    m_pos = event->pos();
    p_controller->segmentViewMoved(this);
}

//! Set the controller to report back the move
void SegmentElementView::setLayerElementController(LayerElementController* controller)
{
    p_controller = controller;
}

//! Set the draw rectangle
void SegmentElementView::setRectangle(QRectF rectangle)
{
    prepareGeometryChange();
    m_rectangle = rectangle;
}

//! Set the brush
void SegmentElementView::setBrush(QBrush brush)
{
    m_brush = brush;
}

//! Set the pen
void SegmentElementView::setPen(QPen pen)
{
    m_pen = pen;
}

//! Get the last position of the item
QPointF SegmentElementView::getLastPos() const
{
    return m_pos;
}
