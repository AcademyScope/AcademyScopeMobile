#pragma once

#include <QObject>
#include <QStringList>
#include <BackEnd.hpp>

class Controller : public QObject {
    Q_OBJECT
    Q_PROPERTY(QStringList universities READ universities NOTIFY universitiesChanged)
    Q_PROPERTY(QStringList departments READ departments NOTIFY departmentsChanged)
public:
    explicit Controller(QObject *parent = nullptr);

    QStringList universities() const;
    QStringList departments() const;
    Q_INVOKABLE void setUniversity(QString university);
    Q_INVOKABLE void setDepartment(QString university);

signals:
    void universitiesChanged();
    void departmentsChanged();

private:
    AcademyScopeBackEnd backEnd;
    AcademyScopeParameters parameters;
    void updateUniversityTable();
};
