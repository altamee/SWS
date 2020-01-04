#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

#include "levenshteindistance.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_DISTANCEBUTTON_clicked();

    bool IsSingle(QString string);

private:
    Ui::MainWindow *ui;
    std::shared_ptr<LevenshteinDistance> levenshtein; //< used to get the levenshtein distance
};
#endif // MAINWINDOW_H
