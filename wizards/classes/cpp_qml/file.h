%{Cpp:LicenseTemplate}\
//***************************************************************************************
//
//  %{HdrFileName} - header file for C++ class that can be registered for QML
//
//  Usage:
//      In main.cpp, before loading main.qml, insert a call to register the class:
//
//           %{CN}::registerQmlType("MyModule", 1, 0);
//
//      changing the module name, "MyModule", and the major and minor version numbers
//      as appropriate.
//
//      In qml files, import the module using the same name used in registration:
//
//           import MyModule 1.0
//
//      The class can then be declared in QML source code:
//           %{CN} { id:my%{CN} }
//
//***************************************************************************************

#pragma once

%{JS: QtSupport.qtIncludes([ 'QtCore/QObject' ],
                           [ 'QtCore/QObject' ])}\
%{JS: Cpp.openNamespaces('%{Class}')}

class %{CN} : public QObject
{
    Q_OBJECT

public:
    explicit %{CN}(QObject *parent = nullptr);
    virtual ~%{CN}();
    static void registerQmlType(const char* uri, const int majorVersion, const int minorVersion);

signals:

public slots:

protected:

private:
};
%{JS: Cpp.closeNamespaces('%{Class}')}
