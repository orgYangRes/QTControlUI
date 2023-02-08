﻿#ifndef CSINGLETON_H
#define CSINGLETON_H
#include <QScopedPointer>
#include <QMutex>

#define SINGLETON_DECL(Class) \
    public: \
    static Class *Instance(); \
    private: \
    Q_DISABLE_COPY(Class) \
    static QScopedPointer<Class> self;

#define SINGLETON_IMPL(Class) \
    QScopedPointer<Class> Class::self; \
    Class *Class::Instance() { \
    if (self.isNull()) { \
    static QMutex mutex; \
    QMutexLocker locker(&mutex); \
    if (self.isNull()) { \
    self.reset(new Class); \
    } \
    } \
    return self.data(); \
    }
#endif // CSINGLETON_H


