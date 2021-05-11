#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setDisabled(true);
    ui->lineEdit->setDisabled(true);
    ui->pushButtonConv->setDisabled(true);
    ui->lineEditRemover->setDisabled(true);
    ui->pushButtonExcluir->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonConv_clicked()
{
    try {
        QString rec = ui->lineEdit->text();
        string nome = rec.toStdString();
        int aux;
        char *name = new char[nome.length()+1];
        memcpy(name, nome.c_str(),nome.length()+1);//copia os valores de num bytes do local apontado pela fonte diretamente para o bloco de memória apontado pelo destino
        for (int i = 0 ; i < nome.length() ; i++) {
            aux = name[i];
            if(aux >= 65 && aux <=90){//letra maiuscula
                aux = aux + 32;
            }else{//letra minuscula
                aux = aux - 32;
            }
            name[i] = aux;
        }
        //ui->textEdit->setText(name);
        p->incluir(name);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonMostrar_clicked()
{
    try {
        ui->textEdit->clear();
        ui->textEdit->setText(p->mostrar());
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_radioButtonAdicionar_clicked()
{
    ui->lineEdit->setDisabled(false);
    ui->pushButtonConv->setDisabled(false);

    ui->lineEditRemover->setDisabled(true);
    ui->pushButtonExcluir->setDisabled(true);
}

void MainWindow::on_radioButtonRemover_clicked()
{
    ui->lineEditRemover->setDisabled(false);
    ui->pushButtonExcluir->setDisabled(false);

    ui->lineEdit->setDisabled(true);
    ui->pushButtonConv->setDisabled(true);
}

void MainWindow::on_pushButtonExcluir_clicked()
{
    try {
        int aux;
        aux = p->excluir(ui->lineEditRemover->text());
        if(aux != 0)
            QMessageBox::information(this,"REMOVIDO",QString::number(aux) + " ocorrencia excluidas");
        else
            QMessageBox::information(this,"STRING NAO ENCONTRADA","Nao foi possivel remover: " + ui->lineEditRemover->text());
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
