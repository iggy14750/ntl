

/* A very simple ASSERT system.
 * <cassert> doesn't work quite like I would like, but
 * I don't want to manually throw exceptions.
 */

#ifndef __ASSERT_H__
#define __ASSERT_H__ 

#include <stdexcept>

#ifdef NO_DEBUG
#define ASSERT(x) 
#else
#define ASSERT(x) {if (!(x)) throw std::runtime_error("assertion failed");}

#endif /* NO_DEBUG */

#endif /* __ASSERT_H__ */