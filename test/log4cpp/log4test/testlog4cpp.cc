#include <log4cpp/SimpleLayout.hh>//布局，负责设定日志的格式，SimpleLayout："优先级 + 日志信息“
#include<log4cpp/BasicLayout.hh>//时间戳+优先级+内容
#include<log4cpp/PatternLayout.hh>//"使用类似 printf 的格式化模式"（推荐使用这种）
#include<log4cpp/OstreamAppender.hh>//输出到一个 ostream 类
#include<log4cpp/Category.hh>//负责向日志中写入信息
#include<log4cpp/Priority.hh>//优先级，用来指定 Category 优先级和日志优先级
#include<log4cpp/FileAppender.hh>//输出到一个 ostream 类
#include<log4cpp/RollingFileAppender.hh>//输出到一个 ostream 类
#include<iostream>  

using namespace std;
using namespace log4cpp; //一次性把log4cpp里的实体全部引出来

void test(){
    //日志的格式
    SimpleLayout *psl=new SimpleLayout();
    //日志的目的地
    OstreamAppender *poa=new OstreamAppender("OstreamAppender",&cout);//名字，流名字
    poa->setLayout(psl);//设置日志格式

   // 日志的种类
   Category &root=Category::getRoot();//为什么用引用，因为category是用protected进行修饰的，类外面创建的对象不能直接调用,getRoot的返回值是引用
   root.setAppender(poa); //设置目的地
   //root.setPriority(Priority::DEBUG);//设置优先级
   
   //日志记录器，只有当日志的优先级大于等于Category的优先级的时候，才会被记录，否则日志就会被过滤掉
   root.setPriority(Priority::ERROR);//设置优先级
   root.emerg("this is an emerg message");
   root.fatal("this is an fatal message");
   root.alert("this is an alert message");
   root.crit("this is an crit message");
   root.error("this is an error message");
   root.notice("this is an notice message");
   root.debug("this is an emerg message");

   //回收
   Category::shutdown();
}

void test1(){
    //日志的格式
    // SimpleLayout *psl=new SimpleLayout();
    //BasicLayout *pbl=new BasicLayout();
    PatternLayout *ppl=new PatternLayout();
    ppl->setConversionPattern("%d %c [%p] %m%n");//设置打印格式，%d日期，%cCategory，%p优先级，%m信息，%n换行
    
    //日志的目的地
    OstreamAppender *poa=new OstreamAppender("OstreamAppender",&cout);//名字，流名字
   
    // poa->setLayout(pbl);//设置日志格式
   // poa->setLayout(psl);//设置日志格式
    poa->setLayout(ppl);//设置日志格式
   // 日志的种类
   //Category &root=Category::getRoot();//为什么用引用，因为category是用protected进行修饰的，类外面创建的对象不能直接调用,getRoot的返回值是引用
   
   Category &root=Category::getRoot().getInstance("mycat");//设置category的名字
    root.setAppender(poa); //设置目的地
   //root.setPriority(Priority::DEBUG);//设置优先级
   
   //日志记录器，只有当日志的优先级大于等于Category的优先级的时候，才会被记录，否则日志就会被过滤掉
   root.setPriority(Priority::ERROR);//设置优先级
   root.emerg("this is an emerg message");
   root.fatal("this is an fatal message");
   root.alert("this is an alert message");
   root.crit("this is an crit message");
   root.error("this is an error message");
   root.notice("this is an notice message");
   root.debug("this is an emerg message");

   //回收
   Category::shutdown();
}


void test2(){
    //日志的格式
    // SimpleLayout *psl=new SimpleLayout();
    //BasicLayout *pbl=new BasicLayout();
    PatternLayout *ppl1=new PatternLayout();
    ppl1->setConversionPattern("%d %c [%p] %m%n");//设置打印格式，%d日期，%cCategory，%p优先级，%m信息，%n换行
    
    PatternLayout *ppl2=new PatternLayout();
    ppl2->setConversionPattern("%d %c [%p] %m%n");//设置打印格式，%d日期，%cCategory，%p优先级，%m信息，%n换行
    
    //日志的目的地
    //对于每一种日志的目的地，必须有自己的格式，不能共用
    OstreamAppender *poa=new OstreamAppender("OstreamAppender",&cout);//名字，流名字
    // poa->setLayout(pbl);//设置日志格式
   // poa->setLayout(psl);//设置日志格式
    poa->setLayout(ppl1);//设置日志格式

    FileAppender *pfl=new FileAppender("FileAppender","wd.log");
    pfl->setLayout(ppl2); 
   // 日志的种类
   //Category &root=Category::getRoot();//为什么用引用，因为category是用protected进行修饰的，类外面创建的对象不能直接调用,getRoot的返回值是引用
   
   Category &root=Category::getRoot().getInstance("mycat");//设置category的名字
    root.setAppender(poa); //设置目的地
   //root.setPriority(Priority::DEBUG);//设置优先级
   
    root.setAppender(pfl); //设置目的地
   //日志记录器，只有当日志的优先级大于等于Category的优先级的时候，才会被记录，否则日志就会被过滤掉
   root.setPriority(Priority::ERROR);//设置优先级
   root.emerg("this is an emerg message");
   root.fatal("this is an fatal message");
   root.alert("this is an alert message");
   root.crit("this is an crit message");
   root.error("this is an error message");
   root.notice("this is an notice message");
   root.debug("this is an emerg message");

   //回收
   //poa和pfl不能共用日志格式ppl，否则可能出现段错误
   Category::shutdown();
}

void test3(){
    //日志的格式
    // SimpleLayout *psl=new SimpleLayout();
    //BasicLayout *pbl=new BasicLayout();
    PatternLayout *ppl1=new PatternLayout();
    ppl1->setConversionPattern("%d %c [%p] %m%n");//设置打印格式，%d日期，%cCategory，%p优先级，%m信息，%n换行
    
    PatternLayout *ppl2=new PatternLayout();
    ppl2->setConversionPattern("%d %c [%p] %m%n");//设置打印格式，%d日期，%cCategory，%p优先级，%m信息，%n换行
    
    //日志的目的地
    //对于每一种日志的目的地，必须有自己的格式，不能共用
    OstreamAppender *poa=new OstreamAppender("OstreamAppender",&cout);//名字，流名字
    // poa->setLayout(pbl);//设置日志格式
   // poa->setLayout(psl);//设置日志格式
    poa->setLayout(ppl1);//设置日志格式

    //FileAppender *pfl=new FileAppender("FileAppender","wd.log");
    //pfl->setLayout(ppl2); 

    RollingFileAppender *pfl=new RollingFileAppender("RollingFileAppender","wd.log",5* 1024,3 );
    pfl->setLayout(ppl2); 
    // 日志的种类
   //Category &root=Category::getRoot();//为什么用引用，因为category是用protected进行修饰的，类外面创建的对象不能直接调用,getRoot的返回值是引用
   
   Category &root=Category::getRoot().getInstance("mycat");//设置category的名字
    root.setAppender(poa); //设置目的地
   //root.setPriority(Priority::DEBUG);//设置优先级
   
    root.setAppender(pfl); //设置目的地
   //日志记录器，只有当日志的优先级大于等于Category的优先级的时候，才会被记录，否则日志就会被过滤掉
   
   root.setPriority(Priority::ERROR);//设置优先级
    for(size_t idx=0;idx!=100;++idx){
   root.emerg("this is an emerg message");
   root.fatal("this is an fatal message");
   root.alert("this is an alert message");
   root.crit("this is an crit message");
   root.error("this is an error message");
   root.notice("this is an notice message");
   root.debug("this is an emerg message");
   }
   //回收
   //poa和pfl不能共用日志格式ppl，否则可能出现段错误
   Category::shutdown();
}
int main()
   //root.setPriority(Priority::DEBUG);//设置优先级
{
   // test();
   //test1();
   test3();
    return 0;
}

