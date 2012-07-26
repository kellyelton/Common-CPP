#pragma once
#ifndef __Script_Timer__
	#define __Script_Timer__
	#include <sys/timeb.h>
#ifdef __cplusplus
		class Script_Timer
#else
		struct Script_Timer
#endif
		{
#ifdef __cplusplus
		public:
#endif
			unsigned long milliseconds;
			unsigned long seconds;
			struct timeb start_t;
			struct timeb end_t;
#ifdef __cplusplus
			void End()
			{
				ftime(&this->end_t);
				this->seconds = this->end_t.time - this->start_t.time;
				this->milliseconds = (this->seconds * 1000) + (this->end_t.millitm - this->start_t.millitm);
			}
			void Start()
			{
				ftime(&this->start_t);
			}
#endif
		};
		void End_ST(Script_Timer *This)
		{
			ftime(&This->end_t);
			This->seconds = This->end_t.time - This->start_t.time;
			This->milliseconds = (This->seconds * 1000) + (This->end_t.millitm - This->start_t.millitm);
		}
		void Start_ST(Script_Timer *This)
		{
			ftime(&This->start_t);
		}
#endif