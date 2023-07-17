/********************************************************************************
** Form generated from reading UI file 'creditview.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITVIEW_H
#define UI_CREDITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

namespace s21 {

class Ui_CreditView
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *creditPeriod;
    QLabel *label;
    QLineEdit *creditAmount;
    QLabel *label_3;
    QLineEdit *percentRate;
    QLabel *label_7;
    QRadioButton *type_annuity;
    QRadioButton *type_diff;
    QPushButton *creditEqual;
    QLabel *label_4;
    QLineEdit *monthlyPayment;
    QLabel *label_5;
    QLineEdit *overpayment;
    QLabel *label_6;
    QLineEdit *totalPayment;

    void setupUi(QWidget *CreditView)
    {
        if (CreditView->objectName().isEmpty())
            CreditView->setObjectName("CreditView");
        CreditView->resize(516, 292);
        formLayoutWidget = new QWidget(CreditView);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 501, 271));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        creditPeriod = new QLineEdit(formLayoutWidget);
        creditPeriod->setObjectName("creditPeriod");

        formLayout->setWidget(1, QFormLayout::FieldRole, creditPeriod);

        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        creditAmount = new QLineEdit(formLayoutWidget);
        creditAmount->setObjectName("creditAmount");

        formLayout->setWidget(0, QFormLayout::FieldRole, creditAmount);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        percentRate = new QLineEdit(formLayoutWidget);
        percentRate->setObjectName("percentRate");

        formLayout->setWidget(2, QFormLayout::FieldRole, percentRate);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        type_annuity = new QRadioButton(formLayoutWidget);
        type_annuity->setObjectName("type_annuity");
        type_annuity->setChecked(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, type_annuity);

        type_diff = new QRadioButton(formLayoutWidget);
        type_diff->setObjectName("type_diff");

        formLayout->setWidget(4, QFormLayout::FieldRole, type_diff);

        creditEqual = new QPushButton(formLayoutWidget);
        creditEqual->setObjectName("creditEqual");

        formLayout->setWidget(5, QFormLayout::SpanningRole, creditEqual);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        monthlyPayment = new QLineEdit(formLayoutWidget);
        monthlyPayment->setObjectName("monthlyPayment");
        monthlyPayment->setReadOnly(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, monthlyPayment);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_5);

        overpayment = new QLineEdit(formLayoutWidget);
        overpayment->setObjectName("overpayment");
        overpayment->setReadOnly(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, overpayment);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_6);

        totalPayment = new QLineEdit(formLayoutWidget);
        totalPayment->setObjectName("totalPayment");
        totalPayment->setReadOnly(true);

        formLayout->setWidget(8, QFormLayout::FieldRole, totalPayment);


        retranslateUi(CreditView);

        QMetaObject::connectSlotsByName(CreditView);
    } // setupUi

    void retranslateUi(QWidget *CreditView)
    {
        CreditView->setWindowTitle(QCoreApplication::translate("CreditView", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("CreditView", "\320\241\321\200\320\276\320\272  \320\272\321\200\320\265\320\264\320\270\321\202\320\260 \320\262 \320\274\320\265\321\201\321\217\321\206\320\260\321\205", nullptr));
        label->setText(QCoreApplication::translate("CreditView", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("CreditView", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217  \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("CreditView", "\320\242\320\270\320\277 \320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\321\205 \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271", nullptr));
        type_annuity->setText(QCoreApplication::translate("CreditView", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\271", nullptr));
        type_diff->setText(QCoreApplication::translate("CreditView", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", nullptr));
        creditEqual->setText(QCoreApplication::translate("CreditView", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("CreditView", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        label_5->setText(QCoreApplication::translate("CreditView", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        label_6->setText(QCoreApplication::translate("CreditView", "\320\224\320\276\320\273\320\263 + \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace s21 {
    class CreditView: public Ui_CreditView {};
} // namespace Ui

}  // namespace s21

#endif // UI_CREDITVIEW_H
