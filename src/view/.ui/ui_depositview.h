/********************************************************************************
** Form generated from reading UI file 'depositview.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITVIEW_H
#define UI_DEPOSITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

namespace s21 {

class Ui_DepositView
{
public:
    QTableWidget *deposits;
    QTableWidget *withdrawals;
    QPushButton *addDeposit;
    QPushButton *removeDeposit;
    QPushButton *removeWithdrawal;
    QPushButton *addWithdrawal;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *depositAmount;
    QLabel *label_2;
    QLineEdit *period;
    QLabel *label_3;
    QLineEdit *rate;
    QLabel *label_4;
    QLineEdit *taxRate;
    QLabel *label_5;
    QCheckBox *capitalization;
    QLabel *label_6;
    QLineEdit *interest;
    QLineEdit *tax;
    QLineEdit *amount;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *depositEqual;
    QComboBox *frequency;

    void setupUi(QWidget *DepositView)
    {
        if (DepositView->objectName().isEmpty())
            DepositView->setObjectName("DepositView");
        DepositView->resize(525, 661);
        deposits = new QTableWidget(DepositView);
        deposits->setObjectName("deposits");
        deposits->setGeometry(QRect(17, 353, 211, 241));
        withdrawals = new QTableWidget(DepositView);
        withdrawals->setObjectName("withdrawals");
        withdrawals->setGeometry(QRect(270, 353, 211, 241));
        addDeposit = new QPushButton(DepositView);
        addDeposit->setObjectName("addDeposit");
        addDeposit->setGeometry(QRect(237, 353, 25, 25));
        removeDeposit = new QPushButton(DepositView);
        removeDeposit->setObjectName("removeDeposit");
        removeDeposit->setGeometry(QRect(237, 383, 25, 25));
        removeWithdrawal = new QPushButton(DepositView);
        removeWithdrawal->setObjectName("removeWithdrawal");
        removeWithdrawal->setGeometry(QRect(490, 383, 25, 25));
        addWithdrawal = new QPushButton(DepositView);
        addWithdrawal->setObjectName("addWithdrawal");
        addWithdrawal->setGeometry(QRect(490, 353, 25, 25));
        label_9 = new QLabel(DepositView);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(50, 330, 151, 17));
        label_10 = new QLabel(DepositView);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(320, 330, 111, 17));
        formLayoutWidget = new QWidget(DepositView);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 481, 308));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        depositAmount = new QLineEdit(formLayoutWidget);
        depositAmount->setObjectName("depositAmount");

        formLayout->setWidget(0, QFormLayout::FieldRole, depositAmount);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        period = new QLineEdit(formLayoutWidget);
        period->setObjectName("period");

        formLayout->setWidget(1, QFormLayout::FieldRole, period);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        rate = new QLineEdit(formLayoutWidget);
        rate->setObjectName("rate");

        formLayout->setWidget(2, QFormLayout::FieldRole, rate);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        taxRate = new QLineEdit(formLayoutWidget);
        taxRate->setObjectName("taxRate");

        formLayout->setWidget(3, QFormLayout::FieldRole, taxRate);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        capitalization = new QCheckBox(formLayoutWidget);
        capitalization->setObjectName("capitalization");

        formLayout->setWidget(5, QFormLayout::LabelRole, capitalization);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_6);

        interest = new QLineEdit(formLayoutWidget);
        interest->setObjectName("interest");
        interest->setReadOnly(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, interest);

        tax = new QLineEdit(formLayoutWidget);
        tax->setObjectName("tax");
        tax->setReadOnly(true);

        formLayout->setWidget(8, QFormLayout::FieldRole, tax);

        amount = new QLineEdit(formLayoutWidget);
        amount->setObjectName("amount");
        amount->setReadOnly(true);

        formLayout->setWidget(9, QFormLayout::FieldRole, amount);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName("label_8");

        formLayout->setWidget(9, QFormLayout::LabelRole, label_8);

        depositEqual = new QPushButton(formLayoutWidget);
        depositEqual->setObjectName("depositEqual");

        formLayout->setWidget(6, QFormLayout::SpanningRole, depositEqual);

        frequency = new QComboBox(formLayoutWidget);
        frequency->addItem(QString());
        frequency->addItem(QString());
        frequency->addItem(QString());
        frequency->setObjectName("frequency");

        formLayout->setWidget(4, QFormLayout::FieldRole, frequency);


        retranslateUi(DepositView);

        QMetaObject::connectSlotsByName(DepositView);
    } // setupUi

    void retranslateUi(QWidget *DepositView)
    {
        DepositView->setWindowTitle(QCoreApplication::translate("DepositView", "MainWindow", nullptr));
        addDeposit->setText(QCoreApplication::translate("DepositView", "+", nullptr));
        removeDeposit->setText(QCoreApplication::translate("DepositView", "-", nullptr));
        removeWithdrawal->setText(QCoreApplication::translate("DepositView", "-", nullptr));
        addWithdrawal->setText(QCoreApplication::translate("DepositView", "+", nullptr));
        label_9->setText(QCoreApplication::translate("DepositView", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\271", nullptr));
        label_10->setText(QCoreApplication::translate("DepositView", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\201\320\275\321\217\321\202\320\270\320\271", nullptr));
        label->setText(QCoreApplication::translate("DepositView", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("DepositView", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217 \320\262 \320\274\320\265\321\201\321\217\321\206\320\260\321\205", nullptr));
        label_3->setText(QCoreApplication::translate("DepositView", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260 (% \320\263\320\276\320\264\320\276\320\262\321\213\321\205)", nullptr));
        rate->setText(QString());
        label_4->setText(QCoreApplication::translate("DepositView", "\320\235\320\260\320\273\320\276\320\263\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        taxRate->setText(QCoreApplication::translate("DepositView", "35", nullptr));
        label_5->setText(QCoreApplication::translate("DepositView", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\273\320\260\321\202", nullptr));
        capitalization->setText(QCoreApplication::translate("DepositView", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262", nullptr));
        label_6->setText(QCoreApplication::translate("DepositView", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        label_7->setText(QCoreApplication::translate("DepositView", "\320\235\320\260\320\273\320\276\320\263", nullptr));
        label_8->setText(QCoreApplication::translate("DepositView", "\320\241\321\203\320\274\320\274\320\260 \320\275\320\260 \320\262\320\272\320\273\320\260\320\264\320\265 \320\272 \320\272\320\276\320\275\321\206\321\203 \321\201\321\200\320\276\320\272\320\260", nullptr));
        depositEqual->setText(QCoreApplication::translate("DepositView", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        frequency->setItemText(0, QCoreApplication::translate("DepositView", "1 \321\200\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        frequency->setItemText(1, QCoreApplication::translate("DepositView", "1 \321\200\320\260\320\267 \320\262 \320\277\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        frequency->setItemText(2, QCoreApplication::translate("DepositView", "1 \321\200\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));

    } // retranslateUi

};

namespace s21 {
    class DepositView: public Ui_DepositView {};
} // namespace Ui

}  // namespace s21

#endif // UI_DEPOSITVIEW_H
