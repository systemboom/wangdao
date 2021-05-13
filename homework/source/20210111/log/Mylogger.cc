#include"Mylogger.h"

Mylogger *Mylogger::_pInstance=nullptr;
Mylogger *Mylogger::getInstance(){
    if(nullptr==_pInstance){
        _pInstance=new Mylogger();
    }
    return _pInstance;
}
void Mylogger::destroy(){
    if(_pInstance){
        delete _pInstance;
        _pInstance=nullptr;
    }
}
void Mylogger::error(const char *msg){
    mylog.error(msg);
}
void Mylogger::info(const char *msg){
    mylog.info(msg);
}
void Mylogger::debug(const char *msg){

    mylog.debug(msg);
}
void Mylogger::warn(const char *msg){
    mylog.warn(msg);
}
Mylogger::Mylogger():mylog(Category::getRoot().getInstance("mycat")){     
    //日志的格式
    PatternLayout *ppl1 = new PatternLayout();
    ppl1->setConversionPattern("%m %d %c [%p]:This is an %p message！%n");

    PatternLayout *ppl2 = new PatternLayout();
    ppl2->setConversionPattern("%m %d %c [%p]:This is an %p message！%n");
    
    //日志的目的地
    //输出到终端
    OstreamAppender *poa = new OstreamAppender("OstreamAppender", &cout);
    poa->setLayout(ppl1);

    //输出到文件
    FileAppender *pfl = new RollingFileAppender("RollingFileAppender", "wd.log",5*1024,3);
    pfl->setLayout(ppl2);
    
    //日志记录器
    mylog.addAppender(poa);
    mylog.addAppender(pfl);

    //过滤器
    mylog.setPriority(Priority::DEBUG);
}
Mylogger::~Mylogger() {
    cout<<"~Mylogger()"<<endl;
    Category::shutdown();
}
    
