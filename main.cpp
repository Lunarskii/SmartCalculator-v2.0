#include <QApplication>

#include "controller/controller.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model model;
  s21::View view;
  s21::Controller controller(&model, &view);

  QObject::connect(&controller, SIGNAL(SolutionReady(std::string)), &view,
                   SLOT(HandleSolution_(std::string)));
  QObject::connect(&controller, SIGNAL(SolutionReady(CreditResult)), &view,
                   SLOT(HandleSolution_(CreditResult)));
  QObject::connect(&controller, SIGNAL(SolutionReady(DepositResult)), &view,
                   SLOT(HandleSolution_(DepositResult)));

  view.show();
  return a.exec();
}
