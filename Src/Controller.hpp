#pragma once

#include <QObject>
#include <QStringList>

class Controller : public QObject {
    Q_OBJECT
    Q_PROPERTY(QStringList universities READ universities NOTIFY universitiesChanged)
    Q_PROPERTY(QStringList departments READ departments NOTIFY departmentsChanged)
public:
    explicit Controller(QObject *parent = nullptr);

    QStringList universities() const;
    QStringList departments() const;
    Q_INVOKABLE void selectUniversity(int index);

signals:
    void universitiesChanged();
    void departmentsChanged();

private:
    QStringList m_universities;
    QStringList m_departments;
};
