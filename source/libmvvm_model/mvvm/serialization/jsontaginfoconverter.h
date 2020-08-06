// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef MVVM_SERIALIZATION_JSONTAGINFOCONVERTER_H
#define MVVM_SERIALIZATION_JSONTAGINFOCONVERTER_H

#include <QString>
#include <mvvm/serialization/jsontaginfoconverterinterface.h>

namespace ModelView
{

//! Default converter between TagInfo and json object.

class MVVM_MODEL_EXPORT JsonTagInfoConverter : public JsonTagInfoConverterInterface
{
public:
    static const QString nameKey;
    static const QString minKey;
    static const QString maxKey;
    static const QString modelsKey;

    QJsonObject to_json(const TagInfo& tag) override;

    TagInfo from_json(const QJsonObject& object) override;

    bool isTagInfo(const QJsonObject& object);
};

} // namespace ModelView

#endif // MVVM_SERIALIZATION_JSONTAGINFOCONVERTER_H
