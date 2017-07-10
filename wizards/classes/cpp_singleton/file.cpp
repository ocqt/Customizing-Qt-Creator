%{Cpp:LicenseTemplate}\
//***************************************************************************************
//
//  %{SrcFileName} - implementation file for singleton object
//
//  Usage:
//      In main.cpp, before loading main.qml, insert a call to register the singleton:
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
//      Any properties or public slots can then be accessed directly off the singleton:
//
//           Text { text: %{CN}.count }
//
//***************************************************************************************

#include "%{HdrFileName}"
%{JS: QtSupport.qtIncludes([ 'QtCore/QObject' ],
                           [ 'QtQml' ])}\
%{JS: Cpp.openNamespaces('%{Class}')}

%{CN}::%{CN}(QObject *parent) : QObject(parent)
{}

// Return a reference to the singleton object
%{CN}& %{CN}::getInstance()
{
	static %{CN}* singleton = nullptr;

    if (!singleton) {
        singleton = new %{CN}();
    }

	return *singleton;
}

// Register this class for access from QML
void %{CN}::registerQmlType(const char* uri, const int majorVersion, const int minorVersion)
{
    qmlRegisterSingletonType<%{CN}>(uri, majorVersion, minorVersion, "%{CN}", %{CN}::singleton_provider);
}
%{JS: Cpp.closeNamespaces('%{Class}')}\
