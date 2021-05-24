 ///
 /// @file    Timer.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-07-03 11:10:41
 ///

#ifndef __WD_TIMER_H__
#define __WD_TIMER_H__
#include <functional>

namespace wd
{

class Timer
{
	using TimerCallback = std::function<void()>;
public:
	Timer(TimerCallback && cb, int,int);

	void start();
	void stop();
private:
	int createTimerfd();
	void setTimerfd(int,int);

	void handleRead();

private:
	int _fd;
	int _initialTime;
	int _periodicTime;
	TimerCallback _cb;
	bool _isStarted;
};

}//end of namespace wd


#endif
