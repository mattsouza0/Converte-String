#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <Persistencia.h>

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
    void on_pushButtonConv_clicked();

    void on_pushButtonMostrar_clicked();

    void on_radioButtonAdicionar_clicked();

    void on_radioButtonRemover_clicked();

    void on_pushButtonExcluir_clicked();

private:
    Ui::MainWindow *ui;
    matt::Persistencia *p = new matt::Persistencia("arquivo.txt");
};
#endif // MAINWINDOW_H
