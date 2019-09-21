#include "messagesmodel.h"
#include <QStringList>
#include <QString>



void MessagesModel::addMessage(QString message)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    messageList.push_back(message);
    endInsertRows();

}

MessagesModel::MessagesModel(QObject *parent): QAbstractListModel{parent}
{

}

QVariant MessagesModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= messageList.count())
        return QVariant();

    const QString message = messageList[index.row()];
    if (role == Qt::DisplayRole)
        return message;
    return QVariant();
}

int MessagesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return messageList.count();
}
