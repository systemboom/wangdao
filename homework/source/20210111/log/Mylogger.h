#ifndef _MYLOGGER_H_
#define _MYLOGGER_H_

#include<log4cpp/Category.hh>
#include<log4cpp/PatternLayout.hh>
//#include<log4cpp/FileAppender.hh>
#include<log4cpp/Priority.hh>
#include<iostream>
#include<string>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/RollingFileAppender.hh>
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using namespace log4cpp;

#define catMsg(msg) string(msg).append(__FILE__).append(" ").append(__FUNCTION__).append(" ").append(to_string(__LINE__)).c_str()
#define logInfo(msg) Mylogger::getInstance()->info(catMsg(msg))
#define logError(msg) Mylogger::getInstance()->error(catMsg(msg))
#define logWarn(msg) Mylogger::getInstance()->warn(catMsg(msg))
#define logDebug(msg) Mylogger::getInstance()->debug(catMsg(msg))


class Mylogger
{
public:
    static Mylogger *getInstance();
    static void destroy();
    void error(const char *msg);
    void info(const char *msg);
    void debug(const char *msg);
    void warn(const char *msg);
    
private:
    Mylogger();
    ~Mylogger();
    
    static Mylogger *_pInstance;
    log4cpp::Category &mylog;
};

#endif
