// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef MVVM_SCIENTIFICSPINBOX_H
#define MVVM_SCIENTIFICSPINBOX_H

#include "mvvm_global.h"
#include <QAbstractSpinBox>

class CORE_EXPORT ScientificSpinBox : public QAbstractSpinBox
{
    Q_OBJECT

    Q_PROPERTY(double value MEMBER m_value READ value WRITE setValue NOTIFY valueChanged USER true)
public:
    ScientificSpinBox(QWidget* parent = nullptr);
    ~ScientificSpinBox() override;

    double value() const;
    void setValue(double val);

    double singleStep() const;
    void setSingleStep(double step);

    double minimum() const;
    void setMinimum(double min);

    double maximum() const;
    void setMaximum(double max);

    void setDecimals(int);
    int decimals() const;

    void stepBy(int steps) override;
    QValidator::State validate(QString&, int&) const override { return QValidator::Acceptable; }
    void fixup(QString&) const override {}

    static QString toString(double val, int decimal_points);
    static double toDouble(QString text, const QDoubleValidator& validator, double min, double max,
                           double default_value);
    static double round(double val, int decimals);

signals:
    void valueChanged(double value);

protected:
    QAbstractSpinBox::StepEnabled stepEnabled() const override;

private:
    void updateValue();
    void updateText();
    bool inRange(double val) const;

    double m_value, m_min, m_max;
    double m_step;
    int m_decimals;
    QDoubleValidator m_validator;
};

#endif // MVVM_SCIENTIFICSPINBOX_H
