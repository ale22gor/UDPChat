#include "messagesmodel.h"
#include <QStringList>
#include <QString>



void MessagesModel::addMessage(QString message)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    messageList.push_back(MessageModelElement{message,false});
    endInsertRows();

}
void MessagesModel::addMyMessage(QString message)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    messageList.push_back(MessageModelElement{message,true});
    endInsertRows();

}
MessagesModel::MessagesModel(QObject *parent): QAbstractListModel{parent}
{

}

QVariant MessagesModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= messageList.count())
        return QVariant();

    const MessageModelElement messageElement = messageList[index.row()];
    if(role == MessageRole)
        return messageElement.message;
    else if(role == SendByMeRole)
        return messageElement.sendByMe;
    else if (role == Qt::DisplayRole)
        return messageElement.message;

    return QVariant();


}

int MessagesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return messageList.count();
}

QHash<int, QByteArray> MessagesModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[MessageRole] = "message";
    roles[SendByMeRole] = "sendByMe";
    return roles;
}
