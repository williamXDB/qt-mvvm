// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "customvariants.h"
#include "jsonvariant.h"

using namespace ModelView;

int Utils::VariantType(const QVariant& variant)
{
    auto result = static_cast<int>(variant.type());
    if (result == QVariant::UserType)
        result = variant.userType();
    return result;
}

bool Utils::CompatibleVariantTypes(const QVariant& oldValue, const QVariant& newValue)
{
    // Invalid variant can be rewritten by any variant.
    // Valid Variant can be replaced by invalid variant.
    // In other cases types of variants should coincide to be compatible.

    if (!oldValue.isValid() || !newValue.isValid())
        return true;

    return Utils::VariantType(oldValue) == Utils::VariantType(newValue);
}

bool Utils::IsTheSame(const QVariant& var1, const QVariant& var2)
{
    // variants of different type are always reported as not the same
    if (VariantType(var1) != VariantType(var2))
        return false;

    // variants of same type are compared by value
    return var1 == var2;
}

QVariant Utils::toQtVariant(const QVariant& custom)
{
    // converts variant based on std::string to variant based on QString
    if (custom.typeName() == JsonVariant::string_type_name)
        return QVariant(QString::fromStdString(custom.value<std::string>()));

    // in other cases returns unchanged variant
    return custom;
}

QVariant Utils::toCustomVariant(const QVariant& standard)
{
    const QString qstring_name = "QString";

    // converts variant based on std::string to variant based on QString
    if (standard.typeName() == qstring_name)
        return QVariant::fromValue(standard.toString().toStdString());

    // in other cases returns unchanged variant
    return standard;
}
