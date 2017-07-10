%{Cpp:LicenseTemplate}\
//***************************************************************************************
//
//  %{HdrFileName} - header file for singleton object
//
//  Usage:
//      In main.cpp, before loading main.qml, insert a call to register the singleton:
//           %{CN}::registerQmlType("MyModule", 1, 0);
//      changing the module name, "MyModule", and the major and minor version numbers
//      as appropriate.
//
//      In qml files, import the module using the same name used in registration:
//           import MyModule 1.0
//
//      Any properties or public slots can then be accessed directly off the singleton:
//           Text { text: %{CN}.count }
//
//***************************************************************************************

#pragma once

%{JS: QtSupport.qtIncludes([ 'QtCore/QObject' ],
                           [ 'QtCore/QObject' ])}\
%{JS: Cpp.openNamespaces('%{Class}')}

class QQmlEngine;
class QJSEngine;

class %{CN} : public QObject
{
    Q_OBJECT

public:
    virtual ~%{CN}() {}
    static QObject* singleton_provider(QQmlEngine *, QJSEngine *) { return &getInstance(); }
    static %{CN}& getInstance();
    static void registerQmlType(const char* uri, const int majorVersion, const int minorVersion);

signals:

public slots:

protected:
    explicit %{CN}(QObject *parent = nullptr);

private:
};
%{JS: Cpp.closeNamespaces('%{Class}')}
