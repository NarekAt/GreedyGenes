#-------------------------------------------------
#
# Project created by QtCreator 2018-03-31T18:03:33
#
#-------------------------------------------------

QT       += core gui
QT       += concurrent widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = App
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    additionaloptionswindow.cpp \
    executewindow.cpp \
    ../GreedyGenesLib/GreedyGenesLib/CellPlacementMatroid.cpp \
    ../GreedyGenesLib/GreedyGenesLib/CellPlacementMaxConSolver.cpp \
    ../GreedyGenesLib/GreedyGenesLib/ClusterMatroid.cpp \
    ../GreedyGenesLib/GreedyGenesLib/FloorPlanningMatroid.cpp \
    ../GreedyGenesLib/GreedyGenesLib/FloorPlanningSolver.cpp \
    ../GreedyGenesLib/GreedyGenesLib/GreedyAlgorithm.cpp \
    ../GreedyGenesLib/GreedyGenesLib/MaxClusterSolver.cpp \
    ../GreedyGenesLib/GreedyGenesLib/MinCoverSolver.cpp \
    ../GreedyGenesLib/GreedyGenesLib/MinWireLengthCellPlacementFitness.cpp \
    ../GreedyGenesLib/GreedyGenesLib/PairwiseInterchangeMutation.cpp \
    ../GreedyGenesLib/GreedyGenesLib/PMXCellPlacementCrossover.cpp \
    ../GreedyGenesLib/GreedyGenesLib/TwoPointInversion.cpp \
    ../GreedyGenesLib/GreedyGenesLib/optimizationsalgorithmfactory.cpp \
    ../GreedyGenesLib/GreedyGenesLib/tspgraph.cpp \
    ../GreedyGenesLib/GreedyGenesLib/tsp.cpp \
    ../GreedyGenesLib/GreedyGenesLib/tspmatroid.cpp

HEADERS += \
        mainwindow.h \
    problemsolvingengine.h \
    additionaloptionswindow.h \
    executewindow.h \
    problem.h \
    ../GreedyGenesLib/GreedyGenesLib/CellPlacementMatroid.h \
    ../GreedyGenesLib/GreedyGenesLib/CellPlacementMaxConSolver.h \
    ../GreedyGenesLib/GreedyGenesLib/Chromosome.h \
    ../GreedyGenesLib/GreedyGenesLib/ClusterMatroid.h \
    ../GreedyGenesLib/GreedyGenesLib/CrossoverStrategy.h \
    ../GreedyGenesLib/GreedyGenesLib/FitnessEvaluationStrategy.h \
    ../GreedyGenesLib/GreedyGenesLib/FloorPlanningMatroid.h \
    ../GreedyGenesLib/GreedyGenesLib/FloorPlanningSolver.h \
    ../GreedyGenesLib/GreedyGenesLib/GeneticAlgorithm.h \
    ../GreedyGenesLib/GreedyGenesLib/GeneticSDK.h \
    ../GreedyGenesLib/GreedyGenesLib/GreedyAlgorithm.h \
    ../GreedyGenesLib/GreedyGenesLib/GreedyPopulationGeneticAlgorithm.h \
    ../GreedyGenesLib/GreedyGenesLib/GreedySDK.h \
    ../GreedyGenesLib/GreedyGenesLib/GreedyStrategy.h \
    ../GreedyGenesLib/GreedyGenesLib/IncrementalGeneticAlgorithm.h \
    ../GreedyGenesLib/GreedyGenesLib/InversionStrategy.h \
    ../GreedyGenesLib/GreedyGenesLib/Matroid.h \
    ../GreedyGenesLib/GreedyGenesLib/MaxClusterSolver.h \
    ../GreedyGenesLib/GreedyGenesLib/MinCoverSolver.h \
    ../GreedyGenesLib/GreedyGenesLib/MinWireLengthCellPlacementFitness.h \
    ../GreedyGenesLib/GreedyGenesLib/MutationStrategy.h \
    ../GreedyGenesLib/GreedyGenesLib/PairwiseInterchangeMutation.h \
    ../GreedyGenesLib/GreedyGenesLib/PMXCellPlacementCrossover.h \
    ../GreedyGenesLib/GreedyGenesLib/TwoPointInversion.h \
    ../GreedyGenesLib/GreedyGenesLib/Types.h \
    ../GreedyGenesLib/GreedyGenesLib/optimizationsalgorithmfactory.h \
    ../GreedyGenesLib/GreedyGenesLib/Algorithm.h \
    ../GreedyGenesLib/GreedyGenesLib/tspgraph.h \
    ../GreedyGenesLib/GreedyGenesLib/tsp.h \
    ../GreedyGenesLib/GreedyGenesLib/tspmatroid.h

FORMS += \
        mainwindow.ui \
    additionaloptionswindow.ui \
    executewindow.ui

INCLUDEPATH += $$PWD/../GreedyGenesLib/GreedyGenesLib
INCLUDEPATH += $$PWD/../../rapidjson/include

DEPENDPATH += $$PWD/../GreedyGenesLib/GreedyGenesLib

STATECHARTS +=

target.path = $$[QT_INSTALL_EXAMPLES]/qtconcurrent/progressdialog

CONFIG += c++14 strict_c++
