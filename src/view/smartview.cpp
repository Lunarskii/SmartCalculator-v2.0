#include "smartview.h"
#include "ui_smartview.h"

SmartView::SmartView(Controller* c, QWidget *parent)
    : controller(c)
    , QWidget(parent)
    , ui(new Ui::SmartView)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_power, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));

    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_lbracket, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_rbracket, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));

    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));

    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(updateExpressionWindow()));
}

SmartView::~SmartView()
{
    delete ui;
}

void SmartView::on_pushButton_equal_clicked()
{
    bool RETURN_CODE = false;
    long double xValue = ui->xValue->text().toDouble(&RETURN_CODE);

    if (RETURN_CODE == true) {
        std::string expression = ui->expressionWindow->text().toStdString();
        controller->setSmartCalculatorData(expression, xValue);
        ui->expressionWindow->setText(QString::fromStdString(controller->getResult()));
    } else {
        ui->expressionWindow->setText("x is invalid");
    }
}

void SmartView::updateExpressionWindow()
{
    if (ui->expressionWindow->text() == '0') ui->expressionWindow->setText("");

    QPushButton* button = (QPushButton *)sender();
    QString text = button->text();
    ui->expressionWindow->setText(ui->expressionWindow->text() += text);
}

void SmartView::on_pushButton_PLOT_clicked()
{
    bool RESULT_CODE = 0;
    int maxX = 0, minX = 0, maxY = 0, minY = 0;

    maxX = ui->maxX->text().toInt(&RESULT_CODE);
    if (RESULT_CODE) maxY = ui->maxY->text().toInt(&RESULT_CODE);
    if (RESULT_CODE) minX = ui->minX->text().toInt(&RESULT_CODE);
    if (RESULT_CODE) minY = ui->minY->text().toInt(&RESULT_CODE);
    if (RESULT_CODE) {
        int rangeX = maxX - minX;
        std::string expression = ui->expressionWindow->text().toStdString();
        QVector<double> x(1024), y(1024);
        QPen bluePen;

        for (int i = 0; i < 1024; ++i) {
          x[i] = minX + rangeX * (i / 1024.0);
          controller->setSmartCalculatorData(expression, x[i]);

          if (controller->getResult() == "inf")
            y[i] = INFINITY;
          else if (controller->getResult() == "-nan")
            y[i] = NAN;
          else
            y[i] = stod(controller->getResult());
        }

        ui->customPlot->addGraph();
        bluePen.setColor(QColor(30, 40, 255, 150));
        bluePen.setStyle(Qt::SolidLine);
        bluePen.setWidthF(5);
        ui->customPlot->graph(0)->setPen(bluePen);
        ui->customPlot->graph(0)->setData(x, y);
        // give the axes some labels:
        ui->customPlot->xAxis->setLabel("x");
        ui->customPlot->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(minX, maxX);
        ui->customPlot->yAxis->setRange(minY, maxY);
        ui->customPlot->replot();
    }
}
