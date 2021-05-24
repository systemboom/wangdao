 ///
 /// @file    TimerThread.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-07-03 11:52:10
 ///

#ifndef __WD_TIMER_THREAD_H__
#define __WD_TIMER_THREAD_H__
#include "Timer.hpp"
#include "Thread.hpp"
#include <functional>
using std::function;
using std::bind;

namespace wd
{

class TimerThread
{
	using TimerCallback = function<void()>;
public:
	TimerThread(TimerCallback && cb, int initialTime, int periodicTime)
	: _timer(std::move(cb), initialTime, periodicTime)
	, _thread(bind(&Timer::start, &_timer))
	{}

	void start() {
		_thread.start();
	}

	void stop() {
		_timer.stop();
		_thread.join();
	}

private:
	Timer _timer;
	Thread _thread;
};


}//end of namespace wd

#endif
