#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include <fstream>
#include <QString>
using std::ifstream;
using std::ofstream;
using std::string;
namespace matt {
class Persistencia
{
private:
    QString nomeArquivo;
public:
    Persistencia(QString nomeArquivo);
    QString mostrar();
    void incluir(QString valor);
    int excluir(QString valor);
};
}
#endif // PERSISTENCIA_H
