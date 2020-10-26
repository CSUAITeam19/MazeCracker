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
            // ��ȸı�
            void on_spbWidth_valueChanged(int arg1);
            // �߶ȸı�
            void on_spbHeight_valueChanged(int arg1);

            // ��������Թ�
            void on_btnGenerateMaze_click();
        };
    }
}
#endif // MAINWINDOW_H
