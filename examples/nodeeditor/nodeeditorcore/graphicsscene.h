// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef NODEEDITORCORE_GRAPHICSSCENE_H
#define NODEEDITORCORE_GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <map>

namespace NodeEditor {

class SampleModel;
class ConnectableView;
class ConnectableItem;
class NodeController;

//! Custom graphics scene for node editor.
//! Listens for updates in SessionModel and populates the scene with views.

class GraphicsScene : public QGraphicsScene {
    Q_OBJECT

public:
    GraphicsScene(SampleModel* model, QObject* parent);
    ~GraphicsScene() override;

signals:
    void connectableItemSelectionChanged(ConnectableItem* item);

private slots:
    void onConnectionRequest(ConnectableView* childView, ConnectableView* parentView);
    void onSelectionChanged();

private:
    void updateScene();
    void processItem(ConnectableItem* item);
    ConnectableView* findView(ConnectableItem* item);

    SampleModel* m_model{nullptr};
    std::map<ConnectableItem*, ConnectableView*> m_itemToView;
    NodeController* m_nodeController;
};

} // namespace NodeEditor

#endif //  NODEEDITORCORE_GRAPHICSSCENE_H
