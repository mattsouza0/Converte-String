#include "Persistencia.h"
namespace matt{
Persistencia::Persistencia(QString nomeArquivo):nomeArquivo(nomeArquivo)
{

}
QString Persistencia::mostrar(){
    ifstream arquivo;
    arquivo.open(nomeArquivo.toStdString().c_str(), std::ios::in);
    if(!arquivo.is_open())//se nao está aberto
        throw QString("Arquivo nao pode ser aberto");
    string linha;
    QString saida = "";
    getline(arquivo,linha);
    if(arquivo.eof()){
        throw QString("Arquivo vazio");
    }
    while(!arquivo.eof()){//faz a leitura enqunato nao chega no fim
        saida += QString::fromStdString(linha)+"\n";
        getline(arquivo,linha);
    }
    arquivo.close();
    return saida;
}

void Persistencia::incluir(QString valor){
    ofstream arquivo;
    arquivo.open(nomeArquivo.toStdString().c_str(), std::ios::out | std::ios::app);
    if(!arquivo.is_open())
        throw QString("Erro ao abrir");
    arquivo<<valor.toStdString()+"\n";//toStdString converte para string
    arquivo.close();
}

int Persistencia::excluir(QString valor){
    ifstream arquivo;
    arquivo.open(nomeArquivo.toStdString().c_str(),std::ios::in);
    if(!arquivo.is_open())
        throw QString("Arquivo nao pode ser aberto");

    ofstream arqTemp;
    arqTemp.open("temp.txt", std::ios::out);
    if(!arqTemp.is_open()){
        throw QString("Arquivo temporario nao foi aberto");
    }

    string linha;
    int cont = 0;
    while(getline(arquivo,linha)){
        if(QString::fromStdString(linha) != valor)
            arqTemp << linha + "\n";
        else
            cont++;

    }

    arquivo.close();
    arqTemp.close();

    remove(nomeArquivo.toStdString().c_str());
    rename("temp.txt", nomeArquivo.toStdString().c_str());
    return cont;
}

}
