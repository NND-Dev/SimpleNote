#include "model.h"
#include <QFile>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

Model::Model(QObject *parent) : QSqlQueryModel(parent)
{
    connectDatabase();
    createTable();
    refresh();

}

Model::~Model()
{
    m_db.close();
}

void Model::connectDatabase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("myfile.sqlite");
    if(!m_db.open())
    {
        qDebug() << "Can not open database: " << m_db.lastError().text();
    }
    else
    {
        qDebug() << "Open database success";
    }
}

void Model::createTable()
{
    QString createTable = "CREATE TABLE IF NOT EXISTS GHICHU (ID INTEGER PRIMARY KEY AUTOINCREMENT, TIEUDE VARCHAR(100), NOIDUNG TEXT);";

    QSqlQuery query;
    if(!query.exec(createTable))
    {
        qDebug() << "Can not create table: " << query.lastError().text();
    }
    else {
        qDebug() << "Create table success";
    }
}

void Model::refresh()
{
    updateID();
    QString str("SELECT *  FROM GHICHU;");
    this->setQuery(str);


}

void Model::updateID()
{
    QSqlQuery query("select * from ghichu order by id");
}

void Model::addRow(const QString &title, const QString &note)
{
    QSqlQuery query;
    query.prepare("INSERT INTO GHICHU (TIEUDE, NOIDUNG) VALUES (?,?);");
    query.addBindValue(title);
    query.addBindValue(note);
    if (!query.exec())
    {
        qDebug() << "Can not add row: " << query.lastError().text();
    }
    else {
        qDebug() << "Add row successfully";
    }
    refresh();
}

void Model::removeRow(const int &id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM GHICHU WHERE ID = (:ID);");
    query.bindValue(":ID",id);
    if(!query.exec())
    {
        qDebug() << "Can not remove the row because: " << query.lastError().text();
    }
    else
    {
        qDebug() << "Remove the row successfully";
    }

    refresh();
}

QHash<int, QByteArray> Model::roleNames() const
{
    QHash<int, QByteArray> roles ;
    for (int i = 0; i < this->record().count(); i ++) {
        roles.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }
    return roles;
}

QVariant Model::data(const QModelIndex &item, int role) const
{

    QVariant value;

    if (item.isValid()) {
        if (role < Qt::UserRole) {
            value = QSqlQueryModel::data(item, role);
        } else {
            int columnIdx = role - Qt::UserRole - 1;
            QModelIndex modelIndex = this->index(item.row(), columnIdx);
            value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
        }
    }
    return value;
}

int Model::getId(const int &row)
{
    return this->data(this->index(row, 0)).toInt();
}


