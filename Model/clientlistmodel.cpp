#include "clientlistmodel.h"

void ClientListModel::addClient(QString name, bool status)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_clients.push_back(ClientModelElement{name,status});
    endInsertRows();
}

void ClientListModel::changeStatus(QString name, bool status)
{
    auto oldInfo = std::find_if(m_clients.begin(),m_clients.end(),
                                [&name] (ClientModelElement const& c)
    {return (c.m_name == name) ; });
    if (oldInfo != m_clients.end()){
        oldInfo->online = status;
    }

    QVector<int> roleVector;
    roleVector << ClientRoles::StatusRole;

    emit dataChanged(createIndex(0, 0), createIndex(rowCount()-1, 0),roleVector);
}

ClientListModel::ClientListModel(QObject *parent): QAbstractListModel{parent}
{
}


QVariant ClientListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_clients.count())
        return QVariant();

    const ClientModelElement &client = m_clients[index.row()];
    if (role == NameRole)
        return client.m_name;
    else if (role == StatusRole){
        if (client.online)
            return "online";
        else
            return "offline";
    }else if (role == Qt::DisplayRole) {
        QString status;
        if (client.online)
            status = "online";
        else
            status = "offline";
        return client.m_name +":"+status;
    }
    return QVariant();

}

int ClientListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_clients.count();
}

QHash<int, QByteArray> ClientListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[StatusRole] = "status";
    return roles;
}
