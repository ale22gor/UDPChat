#ifndef MESSAGESMODEL_H
#define MESSAGESMODEL_H

#include <QAbstractListModel>

class QStringList;
class QString;

#include "model_global.h"

struct MODELSHARED_EXPORT MessageModelElement{
    QString message;
    bool sendByMe;
};

class MODELSHARED_EXPORT MessagesModel:public QAbstractListModel
{
    Q_OBJECT
    QList<MessageModelElement> messageList;
    enum ClientRoles {
            MessageRole = Qt::UserRole + 1,
            SendByMeRole
        };

public slots:
    void addMessage(QString message);
    void addMyMessage(QString message);

public:
    MessagesModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;

};

#endif // MESSAGESMODEL_H
