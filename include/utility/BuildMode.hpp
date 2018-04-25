#pragma once

#ifdef NDEBUG
#define RELEASE_MODE
#else
#define DEBUG_MODE
#endif

// Exectue a statement IFF built in release mode (NDEBUG is definend)
// define ifRelease
#ifndef ifRelease // if (not defined ifRelease)

#ifdef NDEBUG    // if (not debug defined)
#define ifRelease(_e)                           \
  {                                             \
    _e;                                         \
  }
#else
#define ifRelease(_e) {}
#endif // endif (not debug defined)

#else
#error ifRelease already defined!
#endif // endif (not defined ifRelease)
// end define ifRelease

// Execute a statement IFF built in debug mode (NDEBUG not defined)
// define ifDebug
#ifndef ifDebug // if (not defined ifDebug)

#ifndef NDEBUG    // if (not debug not defined)
#define ifDebug(_e)                             \
  {                                             \
    _e;                                         \
  }
#else
#define ifDebug(_e) {}
#endif // endif (not debug not defined)

#else
#error ifDebug already defined!
#endif // endif (not defined ifDebug)
// end define ifDebug
