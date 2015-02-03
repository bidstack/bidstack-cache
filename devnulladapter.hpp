#ifndef BIDSTACK_CACHE_DEVNULLADAPTER_HPP
#define BIDSTACK_CACHE_DEVNULLADAPTER_HPP

#include <QObject>

#include "abstractadapter.hpp"

namespace Bidstack {
    namespace Cache {

        class DevNullAdapter : public AbstractAdapter {
            Q_OBJECT

        public:
            DevNullAdapter(QObject *parent = 0);

        public:
            bool store(QString key, QString data);
            bool has(QString key);
            bool remove(QString key);
            bool clear();
            QString fetch(QString key);
            QString fetch(QString key, QString defaultValue);
        };

    };
};

#endif
