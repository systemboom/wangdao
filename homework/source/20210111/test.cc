#include <iostream>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <string>
#include <log4cpp/Appender.hh>
#include <sstream>
#include <fstream>

using namespace std;
using namespace log4cpp;

class Mylogger{
public:
    static Mylogger *GetInstance(){//静态间接调用构造函数
        if(nullptr==_pInstance){
            _pInstance = new Mylogger();
        }
        return _pInstance;
    }
    static void destroy(){//间接调用析构函数
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
    void setpriority(int num);
    void warn(const char *msg);
    void error(const char *msg);
    void debug(const char *msg);
    void info(const char *msg);
private:
    static Mylogger* _pInstance;
    log4cpp:: Category & _root;
    Mylogger();//构造函数私有
    ~Mylogger();//析构函数保持形式一致
};

Mylogger* Mylogger:: _pInstance = nullptr;

Mylogger:: Mylogger ()//构造函数
    :_root(log4cpp::Category::getRoot().getInstance("Mycat"))
{
        PatternLayout *ppl1 = new PatternLayout();
        ppl1->setConversionPattern("%m %d %c [%p]");
        PatternLayout *ppl2= new PatternLayout();
        ppl2->setConversionPattern("%m %d %c [%p]");
        
        OstreamAppender *poa = new OstreamAppender("OstreamAppender",&cout);
        poa->setLayout(ppl1);
        RollingFileAppender *prfa = new RollingFileAppender("FileAppender","Mylog.txt",2*1024,5);
        prfa->setLayout(ppl2);

        _root.addAppender(poa);
        _root.setPriority(Priority::DEBUG);
        _root.addAppender(prfa);
        _root.setPriority(Priority::DEBUG);
}

Mylogger:: ~Mylogger(){//析构函数
    cout<<"~Mylogger"<<endl;
    _root.shutdown();
}

void Mylogger::setpriority(int num){//可以自定义优先级,默认debug
    switch(num){
    case 1:_root.setPriority(Priority::ERROR);break;
    case 2:_root.setPriority(Priority::WARN);break;
    case 3:_root.setPriority(Priority::INFO);break;
    case 4:_root.setPriority(Priority::DEBUG);break;
    default :_root.setPriority(Priority::DEBUG);break;
    }
}

//为了得到想要的格式,m的信息分开放,想到用文件流
void Mylogger::warn(const char *msg){
    _root.warn(msg);
    ofstream ofs("Mylog.txt",ios::app);
    if(ofs.good()){
        cout<<":This is a warn message!"<<endl;
        ofs<<":This is a warn message!"<<endl;
    }
    ofs.close();
    /* _root.warn("This is a warn message"); */
}
void Mylogger::error(const char *msg){
    _root.error(msg);
    ofstream ofs("Mylog.txt",ios::app);
    if(ofs.good()){
        cout<<":This is an error message!"<<endl;
        ofs<<":This is an error message!"<<endl;
    }
    ofs.close();
    /* _root.error("This is an error message"); */
}
void Mylogger::debug(const char *msg){
    _root.debug(msg);
    ofstream ofs("Mylog.txt",ios::app);
    if(ofs.good()){
        cout<<":This is a debug message!"<<endl;
        ofs<<":This is a debug message!"<<endl;
    }
    ofs.close();
    /* _root.debug("This is a debug message"); */
}
void Mylogger::info(const char *msg){
    _root.info(msg);
    ofstream ofs("Mylog.txt",ios::app);
    if(ofs.good()){
        cout<<":This is an info message!"<<endl;
        ofs<<":This is an info message!"<<endl;
    }
    ofs.close();
    /* _root.info("This is an info message"); */
}

//因为main中函数并不是类中的函数,所以想到用宏替换
#define catMsg(msg) string(msg).append("fileName:").append(__FILE__)\
                               .append(" functionName:").append(__func__)\
                               .append(" lineNumber:").append(int2string(__LINE__)).c_str()
Mylogger *log = Mylogger::GetInstance();
#define logInfo(msg) log->info(catMsg(msg))
#define logError(msg) log->error(catMsg(msg))
#define logWarn(msg) log->warn(catMsg(msg))
#define logDebug(msg) log->debug(catMsg(msg))

string int2string(int line){//行号转换字符串
    stringstream ss;
    ss<<line;
    return ss.str();
}

int main()
{
    cout<<"hello,world"<<endl;
    logError("Message");
    logWarn("Message");
    logDebug("Message");
    Mylogger::destroy();
    
    return 0;
}

