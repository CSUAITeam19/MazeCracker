#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace MazeCracker
{
    namespace UI
    {
        class MainWindow : public QMainWindow
        {
            Q_OBJECT

        public:
            MainWindow(QWidget* parent = nullptr);
            ~MainWindow();

        private:
            Ui::MainWindow* ui;
        private slots:
            // 宽度改变
            void on_spbWidth_valueChanged(int arg1);
            // 高度改变
            void on_spbHeight_valueChanged(int arg1);

            // 生成随机迷宫
            void on_btnGenerateMaze_click();
        };
    }
}
#endif // MAINWINDOW_H
