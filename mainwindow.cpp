#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

namespace MazeCracker
{
    namespace UI
    {
        MainWindow::MainWindow(QWidget* parent)
            : QMainWindow(parent)
            , ui(new Ui::MainWindow)
        {
            ui->setupUi(this);
        }

        void MainWindow::on_spbWidth_valueChanged(int width)
        {
            qDebug() << "new width: " << width;
        }

        void MainWindow::on_spbHeight_valueChanged(int height)
        {
            qDebug() << "new height:" << height;
        }

        void MainWindow::on_btnGenerateMaze_click()
        {
            qDebug() << "Start to create a new maze";
        }

        MainWindow::~MainWindow()
        {
            delete ui;
        }
    }
}


