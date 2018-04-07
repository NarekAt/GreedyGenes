#ifndef PROBLEM_H
#define PROBLEM_H

#include "QString"
#include "QMap"
#include "QVariant"

struct Problem
{
    Problem() = default;

    Problem(const QString& problem,
            const QString& method,
            const QString& inputDir)
        : m_problem(problem)
        , m_method(method)
        , m_inputDir(inputDir)
    {}

    QString m_problem;
    QString m_method;
    QString m_inputDir;

    QMap<QString, QString> m_geneticAlgOptions;
    QMap<QString, QString> m_greedyAlgOptions;
};

#endif // PROBLEM_H
