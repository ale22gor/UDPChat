#ifndef MESSAGESMODEL_H
#define MESSAGESMODEL_H

#include <QAbstractListModel>

class QStringList;
class QString;

#include "model_global.h"


class MODELSHARED_EXPORT MessagesModel:public QAbstractListModel
{
    Q_OBJECT
    QStringList messageList;

public slots:
    void addMessage(QString message);

public:
    MessagesModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;

};

#endif // MESSAGESMODEL_H
