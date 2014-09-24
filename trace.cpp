#include <QDebug>
#include <QDateTime>
#include "trace.h"
#include "config.h"

Trace::LevelEnum Trace::currentTraceLvl;
QString Trace::logFileName;
QString Trace::logFilePath;
QList<QString> Trace::listOfClassToLog;

Trace::Trace(QObject *parent) :
    QObject(parent)
{
    initializeTrace();
    setCurrentTraceLvl(ALL);
}

// functions
void Trace::initializeTrace()
{
    QString fileName = QDateTime::currentDateTime().toString("ddd-dd-MMM-yyyy-hh:mm:ss");
    fileName.replace(".","");
    fileName = fileName + ".txt";
    this->logFileName = fileName;
    this->logFilePath = constDefaultPath;
}

void Trace::traceMessage(QString date, QString time, QString fileLogged, int line, QString className, QString msg)
{
    QFile file(getLogFilePath() + getLogFileName());

    if(file.open(QIODevice::WriteOnly | QIODevice::Append) == false)
    {
        qDebug() << "Trace::traceMessage - impossible to open file;";
    }
    else
    {
        QTextStream stream(&file);
        stream << date << " at " << time << "\nin file:" << fileLogged << " at line:" << line << endl;
        stream << className << ": " << msg << endl << endl;

        file.close();
    }
}
