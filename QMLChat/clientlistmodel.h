#ifndef CLIENTLISTMODEL_H
#define CLIENTLISTMODEL_H

#include<QAbstractListModel>
#include<QList>
#include<QString>

struct ClientModelElement{
    QString m_name;
    bool online;
};


class ClientListModel: public QAbstractListModel

{
    Q_OBJECT
    QList<ClientModelElement> m_clients;
    enum ClientRoles {
            NameRole = Qt::UserRole + 1,
            StatusRole
        };

public slots:
    void addClient(QString name, bool status);
    void changeStatus(QString name, bool status);


public:
    ClientListModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;

};

#endif // CLIENTLISTMODEL_H
