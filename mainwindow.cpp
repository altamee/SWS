#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    levenshtein = make_shared<LevenshteinDistance> ();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_DISTANCEBUTTON_clicked handles when find distance button is clicked
 */
void MainWindow::on_DISTANCEBUTTON_clicked()
{
    QString firstWord = ui->FIRSTWORD->toPlainText();
    QString secondWord = ui->SECONDWORD->toPlainText();

    // word contains a space or is made of multiple words
    if (!IsSingle(firstWord) || !IsSingle(secondWord))
    {
        QMessageBox wordErrorMessage;
        wordErrorMessage.setText("Invalid input.");
        wordErrorMessage.setInformativeText("Input should be a single word and must not contain a space.");
        wordErrorMessage.exec();
    }

    else
    {
        int distance = levenshtein->GetDistance(firstWord, firstWord.length(), secondWord, secondWord.length());

        QMessageBox distanceMessage;
        distanceMessage.setText(QString("Your distance is %1").arg(distance));
        distanceMessage.exec();
    }

}

/**
 * @brief MainWindow::IsSingle checks if a string is made of multiple words and does not contain any space characters
 * @param string The string to check
 * @return true if string is made of a single word without any space characters, false  otherwise.
 */
bool MainWindow::IsSingle(QString string)
{
    return !string.contains(' ');
}
