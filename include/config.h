#ifndef CONFIG_H
#define CONFIG_H

#ifdef _MSC_VER <= 1800
	#define __func__ __FUNCTION__
	#define snprintf _snprintf
#endif

#endif
