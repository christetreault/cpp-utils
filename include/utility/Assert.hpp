#pragma once

#include <cstdio>

// TODO: different versions for debug vs release mode

#ifndef expect
#define expect(_msg, _e)                                                \
  {                                                                     \
    if(!(_e))                                                           \
      {                                                                 \
        fprintf(stderr, "Truth Assertion Failed!\n\t%s\n\tFile: %s"     \
                "\n\tLine: %d\n\tFunction: %s\n", _msg, __FILE__, __LINE__, __func__); \
        exit(EXIT_FAILURE);                                             \
      }                                                                 \
  }
#else
#error expect already defined!
#endif

#ifndef verify
#define verify(_msg, _e) expect(_msg, _e)
#else
#error verify already defined!
#endif

#ifndef unreachable
#define unreachable(_msg)                                               \
  {                                                                     \
    fprintf(stderr, "Unreachable code executed! This should never happen!\n\t%s\n\tFile: %s" \
            "\n\tLine: %d\n\tFunction: %s\n", _msg, __FILE__, __LINE__, __func__); \
    exit(EXIT_FAILURE);                                                 \
  }
#else
#error unreachable already defined!
#endif

#ifndef todo
#define todo(_msg)                                                      \
  {                                                                     \
    fprintf(stderr, "Feature not implemented! This should never happen!\n\t%s\n\tFile: %s" \
            "\n\tLine: %d\n\tFunction: %s\n", _msg, __FILE__, __LINE__, __func__); \
    exit(EXIT_FAILURE);                                                 \
  }
#else
#error todo already defined!
#endif

#ifndef impossible
#define impossible(_msg)                                                \
  {                                                                     \
    fprintf(stderr, "This should never happen!\n\t%s\n\tFile: %s"       \
            "\n\tLine: %d\n\tFunction: %s\n", _msg, __FILE__, __LINE__, __func__); \
    exit(EXIT_FAILURE);                                                 \
  }
#else
#error impossible already defined!
#endif
