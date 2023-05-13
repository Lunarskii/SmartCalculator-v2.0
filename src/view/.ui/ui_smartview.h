/********************************************************************************
** Form generated from reading UI file 'smartview.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTVIEW_H
#define UI_SMARTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "../qcustomplot.h"

namespace s21 {

class Ui_SmartView
{
public:
    QWidget *centralwidget;
    QLineEdit *expressionWindow;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_lbracket;
    QPushButton *pushButton_rbracket;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_log;
    QPushButton *pushButton_div;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_power;
    QPushButton *pushButton_0;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_undo;
    QPushButton *pushButton_x;
    QLineEdit *xValue;
    QPushButton *pushButton_PLOT;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *maxX;
    QLineEdit *minX;
    QLineEdit *maxY;
    QLineEdit *minY;
    QStatusBar *statusbar;
    QCustomPlot *customPlot;

    void setupUi(QWidget *SmartView)
    {
        if (SmartView->objectName().isEmpty())
            SmartView->setObjectName("SmartView");
        SmartView->resize(410, 668);
        QFont font;
        font.setPointSize(11);
        SmartView->setFont(font);
        centralwidget = new QWidget(SmartView);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 411, 367));
        expressionWindow = new QLineEdit(centralwidget);
        expressionWindow->setObjectName("expressionWindow");
        expressionWindow->setGeometry(QRect(10, 10, 391, 35));
        QFont font1;
        font1.setPointSize(14);
        expressionWindow->setFont(font1);
        expressionWindow->setLayoutDirection(Qt::RightToLeft);
        expressionWindow->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	qproperty-alignment: 'AlignVCenter | AlignLeft';\n"
"	border-bottom: 1px solid gray;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"background-color: white;"));
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName("pushButton_cos");
        pushButton_cos->setEnabled(true);
        pushButton_cos->setGeometry(QRect(10, 50, 65, 40));
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName("pushButton_atan");
        pushButton_atan->setGeometry(QRect(75, 50, 65, 40));
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(140, 50, 65, 40));
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_lbracket = new QPushButton(centralwidget);
        pushButton_lbracket->setObjectName("pushButton_lbracket");
        pushButton_lbracket->setGeometry(QRect(205, 50, 65, 40));
        pushButton_lbracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_rbracket = new QPushButton(centralwidget);
        pushButton_rbracket->setObjectName("pushButton_rbracket");
        pushButton_rbracket->setGeometry(QRect(270, 50, 65, 40));
        pushButton_rbracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_equal = new QPushButton(centralwidget);
        pushButton_equal->setObjectName("pushButton_equal");
        pushButton_equal->setGeometry(QRect(335, 50, 65, 40));
        pushButton_equal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName("pushButton_sin");
        pushButton_sin->setGeometry(QRect(10, 90, 65, 40));
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        pushButton_sqrt->setGeometry(QRect(75, 90, 65, 40));
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName("pushButton_minus");
        pushButton_minus->setGeometry(QRect(140, 90, 65, 40));
        pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(205, 90, 65, 40));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(270, 90, 65, 40));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(335, 90, 65, 40));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName("pushButton_tan");
        pushButton_tan->setGeometry(QRect(10, 130, 65, 40));
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName("pushButton_ln");
        pushButton_ln->setGeometry(QRect(75, 130, 65, 40));
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_mult = new QPushButton(centralwidget);
        pushButton_mult->setObjectName("pushButton_mult");
        pushButton_mult->setGeometry(QRect(140, 130, 65, 40));
        pushButton_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(205, 130, 65, 40));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(270, 130, 65, 40));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(335, 130, 65, 40));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName("pushButton_acos");
        pushButton_acos->setGeometry(QRect(10, 170, 65, 40));
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName("pushButton_log");
        pushButton_log->setGeometry(QRect(75, 170, 65, 40));
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName("pushButton_div");
        pushButton_div->setGeometry(QRect(140, 170, 65, 40));
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(205, 170, 65, 40));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(270, 170, 65, 40));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(335, 170, 65, 40));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName("pushButton_asin");
        pushButton_asin->setGeometry(QRect(10, 210, 65, 40));
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName("pushButton_mod");
        pushButton_mod->setGeometry(QRect(75, 210, 65, 40));
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_power = new QPushButton(centralwidget);
        pushButton_power->setObjectName("pushButton_power");
        pushButton_power->setGeometry(QRect(140, 210, 65, 40));
        pushButton_power->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(205, 210, 65, 40));
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setGeometry(QRect(270, 210, 65, 40));
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_undo = new QPushButton(centralwidget);
        pushButton_undo->setObjectName("pushButton_undo");
        pushButton_undo->setGeometry(QRect(335, 210, 65, 40));
        pushButton_undo->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName("pushButton_x");
        pushButton_x->setGeometry(QRect(10, 250, 65, 40));
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        xValue = new QLineEdit(centralwidget);
        xValue->setObjectName("xValue");
        xValue->setGeometry(QRect(80, 253, 187, 35));
        xValue->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	qproperty-alignment: 'AlignVCenter | AlignLeft';\n"
"	border-bottom: 1px solid gray;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"background-color: white;"));
        pushButton_PLOT = new QPushButton(centralwidget);
        pushButton_PLOT->setObjectName("pushButton_PLOT");
        pushButton_PLOT->setGeometry(QRect(270, 250, 130, 40));
        pushButton_PLOT->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 300, 44, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 330, 41, 25));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 300, 43, 25));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 330, 40, 25));
        maxX = new QLineEdit(centralwidget);
        maxX->setObjectName("maxX");
        maxX->setGeometry(QRect(70, 302, 90, 25));
        minX = new QLineEdit(centralwidget);
        minX->setObjectName("minX");
        minX->setGeometry(QRect(70, 332, 90, 25));
        maxY = new QLineEdit(centralwidget);
        maxY->setObjectName("maxY");
        maxY->setGeometry(QRect(240, 302, 90, 25));
        minY = new QLineEdit(centralwidget);
        minY->setObjectName("minY");
        minY->setGeometry(QRect(240, 332, 90, 25));
        statusbar = new QStatusBar(SmartView);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 22));
        customPlot = new QCustomPlot(SmartView);
        customPlot->setObjectName("customPlot");
        customPlot->setGeometry(QRect(10, 370, 391, 271));

        retranslateUi(SmartView);

        QMetaObject::connectSlotsByName(SmartView);
    } // setupUi

    void retranslateUi(QWidget *SmartView)
    {
        SmartView->setWindowTitle(QCoreApplication::translate("SmartView", "View", nullptr));
        expressionWindow->setText(QCoreApplication::translate("SmartView", "0", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("SmartView", "cos()", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("SmartView", "atan()", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("SmartView", "+", nullptr));
        pushButton_lbracket->setText(QCoreApplication::translate("SmartView", "(", nullptr));
        pushButton_rbracket->setText(QCoreApplication::translate("SmartView", ")", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("SmartView", "=", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("SmartView", "sin()", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("SmartView", "sqrt()", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("SmartView", "-", nullptr));
        pushButton_7->setText(QCoreApplication::translate("SmartView", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("SmartView", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("SmartView", "9", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("SmartView", "tan()", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("SmartView", "ln()", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("SmartView", "*", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SmartView", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("SmartView", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("SmartView", "6", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("SmartView", "acos()", nullptr));
        pushButton_log->setText(QCoreApplication::translate("SmartView", "log()", nullptr));
        pushButton_div->setText(QCoreApplication::translate("SmartView", "/", nullptr));
        pushButton_1->setText(QCoreApplication::translate("SmartView", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SmartView", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SmartView", "3", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("SmartView", "asin()", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("SmartView", "mod", nullptr));
        pushButton_power->setText(QCoreApplication::translate("SmartView", "^", nullptr));
        pushButton_0->setText(QCoreApplication::translate("SmartView", "0", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("SmartView", ".", nullptr));
        pushButton_undo->setText(QCoreApplication::translate("SmartView", "UNDO", nullptr));
        pushButton_x->setText(QCoreApplication::translate("SmartView", "x", nullptr));
        xValue->setText(QCoreApplication::translate("SmartView", "0", nullptr));
        pushButton_PLOT->setText(QCoreApplication::translate("SmartView", "PLOT", nullptr));
        label->setText(QCoreApplication::translate("SmartView", "max x:", nullptr));
        label_2->setText(QCoreApplication::translate("SmartView", "min x:", nullptr));
        label_3->setText(QCoreApplication::translate("SmartView", "max y:", nullptr));
        label_4->setText(QCoreApplication::translate("SmartView", "min y:", nullptr));
        maxX->setText(QCoreApplication::translate("SmartView", "10", nullptr));
        minX->setText(QCoreApplication::translate("SmartView", "-10", nullptr));
        maxY->setText(QCoreApplication::translate("SmartView", "10", nullptr));
        minY->setText(QCoreApplication::translate("SmartView", "-10", nullptr));
    } // retranslateUi

};

namespace s21 {
    class SmartView: public Ui_SmartView {};
} // namespace Ui

}  // namespace s21

#endif // UI_SMARTVIEW_H
