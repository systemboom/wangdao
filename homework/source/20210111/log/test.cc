#include"Mylogger.h"

int main()
{
    logError("[Message]");
    logWarn("[Message]");
    logDebug("[Message]");
    logInfo("[Message]");
    Mylogger::destroy();
    return 0;
}
