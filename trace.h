#ifndef TRACE_H
#define TRACE_H

#include <QObject>
#include <QFile>
#include <QTextStream>

/* TRACE MACRO
 * arg1: lvl: enum
 * arg2: className: QString
 * arg3: msg: QString
 *
 * Trace level:
 *  0: Minimum
 *  1: Medium
 *  2: Maximum
 *
 * Default Trace lvl: 0
 */

class Trace;

#define TRACE(lvl,className,msg)                                                                 \
{                                                                                                \
    if((int)lvl <= (int)Trace::getCurrentTraceLvl())                                                  \
    {                                                                                            \
        Trace trace;                                                                             \
        if(trace.classNameShouldBeDisplayed(className))                                          \
        {                                                                                        \
            trace.traceMessage(__DATE__, __TIME__, __FILE__, __LINE__, className, msg);          \
        }                                                                                        \
    }                                                                                            \
}

class Trace : public QObject
{
    Q_OBJECT
    Q_ENUMS(LevelEnum)

public:
    explicit Trace(QObject *parent = 0);

    enum LevelEnum
    {
        NONE = -1,
        MAJOR = 0,
        MEDIUM = 1,
        MINOR = 2,
        ALL = 3
    };


    // setters
    static void setLogFileName(QString name)
    {
        logFileName = name;
    }
    static void setLogFilePath(QString path)
    {
        logFilePath = path;
    }
    static void setCurrentTraceLvl(LevelEnum lvl)
    {
        currentTraceLvl = lvl;
    }
    static void setListOfClassToLog(QList<QString> list)
    {
        listOfClassToLog = list;
    }

    // getters
    static QString getLogFileName()
    {
        return logFileName;
    }
    static QString getLogFilePath()
    {
        return logFilePath;
    }
    static LevelEnum getCurrentTraceLvl()
    {
        return currentTraceLvl;
    }
    static QList<QString> getListOfClassToLog()
    {
        return listOfClassToLog;
    }

    // functions
    void initializeTrace();
    void traceMessage(QString date, QString time, QString fileLogged, int line, QString className, QString msg);
    static bool classNameShouldBeDisplayed(QString className)
    {
        // By default (if the list of classes to log is empty)
        // we log every trace so we return true
        bool result = true;

        if(listOfClassToLog.isEmpty() == false)
        {
            if(listOfClassToLog.contains(className) == false)
            {
                result = false;
            }
        }

        return result;
    }
    static void addClassNameToLog(QString className)
    {
        listOfClassToLog.append(className);
    }

private:
    // variables
    static LevelEnum currentTraceLvl;
    static QString logFileName;
    static QString logFilePath;
    static QList<QString> listOfClassToLog;
};

#endif // TRACE_H
