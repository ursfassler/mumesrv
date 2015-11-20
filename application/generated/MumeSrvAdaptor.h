/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp mumesrv.xml -a generated/MumeSrvAdaptor
 *
 * qdbusxml2cpp is Copyright (C) 2015 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef MUMESRVADAPTOR_H
#define MUMESRVADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface ch.bitzgi.MumeSrv
 */
class MumeSrvAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ch.bitzgi.MumeSrv")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"ch.bitzgi.MumeSrv\">\n"
"    <property access=\"read\" type=\"b\" name=\"switchOn\"/>\n"
"    <property access=\"read\" type=\"u\" name=\"count\"/>\n"
"    <method name=\"setOpenPositionMs\">\n"
"      <arg direction=\"in\" type=\"d\" name=\"value\"/>\n"
"    </method>\n"
"    <method name=\"setClosePositionMs\">\n"
"      <arg direction=\"in\" type=\"d\" name=\"value\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    MumeSrvAdaptor(QObject *parent);
    virtual ~MumeSrvAdaptor();

public: // PROPERTIES
    Q_PROPERTY(uint count READ count)
    uint count() const;

    Q_PROPERTY(bool switchOn READ switchOn)
    bool switchOn() const;

public Q_SLOTS: // METHODS
    void setClosePositionMs(double value);
    void setOpenPositionMs(double value);
Q_SIGNALS: // SIGNALS
};

#endif
