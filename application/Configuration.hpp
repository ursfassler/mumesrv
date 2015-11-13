#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <QStringList>
#include <QString>

class Configuration
{
	public:
    Configuration(QStringList arg);

    bool isValid() const;
    QString helpText() const;

    bool useSystemDbus() const;
    QString sysfsRoot() const;

  private:
    bool valid;
    QString _helpText;
    bool systemDbus;
    QString sysfs;

};

#endif // CONFIGURATION_HPP
