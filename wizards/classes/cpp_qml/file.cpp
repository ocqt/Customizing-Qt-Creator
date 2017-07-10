%{Cpp:LicenseTemplate}\
//***************************************************************************************
//
//  %{SrcFileName} - source file for C++ class that can be registered for QML
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

#include "%{HdrFileName}"
%{JS: QtSupport.qtIncludes([ 'QtCore/QObject' ],
                           [ 'QtQml' ])}\
%{JS: Cpp.openNamespaces('%{Class}')}

%{CN}::%{CN}(QObject *parent) : QObject(parent)
{}


%{CN}::~%{CN}()
{}


// Register this class for access from QML
void %{CN}::registerQmlType(const char* uri, const int majorVersion, const int minorVersion)
{
    qmlRegisterType<%{CN}>(uri, majorVersion, minorVersion, "%{CN}");
}
%{JS: Cpp.closeNamespaces('%{Class}')}\
