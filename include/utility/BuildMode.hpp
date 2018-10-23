#pragma once

#ifdef NDEBUG
#define DMP_RELEASE_MODE
#else
#define DMP_DEBUG_MODE
#endif


#ifndef dmpIfRelease
// {
#ifdef DMP_RELEASE_MODE
//// {
#define dmpIfRelease(_e)                        \
  {                                             \
    _e;                                         \
  }
#else
#define dmpIfRelease(_e) {}
#endif
//// }
#else
#error dmpIfRelease already defined!
#endif
// }

#ifndef dmpIfDebug
// {
#ifdef DMP_DEBUG_MODE
//// {
#define dmpIfDebug(_e)                          \
  {                                             \
    _e;                                         \
  }
#else
#define dmpIfDebug(_e) {}
#endif
//// }
#else
#error dmpIfDebug already defined!
#endif
// }
