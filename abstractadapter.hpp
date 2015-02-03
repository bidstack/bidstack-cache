#ifndef BIDSTACK_CACHE_ABSTRACTADAPTER_HPP
#define BIDSTACK_CACHE_ABSTRACTADAPTER_HPP

#include <QObject>

namespace Bidstack {
    namespace Cache {

        class AbstractAdapter : public QObject {
            Q_OBJECT

        public:
            AbstractAdapter(QObject *parent = 0);

        public:
            virtual bool store(QString key, QString data) =0;
            virtual bool has(QString key) =0;
            virtual bool remove(QString key) =0;
            virtual bool clear() =0;
            virtual QString fetch(QString key) =0;
            virtual QString fetch(QString key, QString defaultValue) =0;
        };

    };
};

#endif
