#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma warning(push, 0)
#include <QMainWindow>
#pragma warning(pop)
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
        };
    }
}
#endif // MAINWINDOW_H
