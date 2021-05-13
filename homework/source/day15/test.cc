#include"Mylogger.h"
void test() {
		int number = 100;
		const char * pstr = "hello, log4cpp";
		logInfo("this is an info message. number = %d, str = %s\n", number, pstr);
	}
int main()
{
    test();
    /* logError("[Message]"); */
    /* logWarn("[Message]"); */
    /* logDebug("[Message]"); */
    /* logInfo("[Message]"); */
    Mylogger::destroy();
    return 0;
}
