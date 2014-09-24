#include "trace.h"

int main()
{
    Trace t;
    t.setCurrentTraceLvl(Trace::MINOR);
    t.addClassNameToLog("classA");

    TRACE(Trace::MAJOR, "classA", "Major trace to log");
    TRACE(Trace::MEDIUM, "classA", "Medium trace to log");
    TRACE(Trace::MINOR, "classA", "Minor trace to log");

    TRACE(Trace::MAJOR, "classB", "Major trace to log");
    TRACE(Trace::MEDIUM, "classB", "Medium trace to log");
    TRACE(Trace::MINOR, "classB", "Minor trace to log");

    return 0;
}
