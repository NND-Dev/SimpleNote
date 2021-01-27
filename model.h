#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>


class Model : public QSqlQueryModel
{
    Q_OBJECT

public:
    Model(QObject *parent = nullptr);
    ~Model();

    //database
    void connectDatabase();
    void createTable();
    Q_INVOKABLE void refresh();

    void updateID();
    Q_INVOKABLE void addRow(const QString &title, const QString &note);
    Q_INVOKABLE void removeRow(const int &id);
    //model
    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE int getId(const int &row);
private:
    QSqlDatabase m_db;
    QByteArrayList nameRoles;
};

#endif // MODEL_H
