#pragma once
#define fgt_LL_FATAL (5)
#define fgt_LL_ERROR (4)
#define fgt_LL_WARN (3)
#define fgt_LL_INFO (2)
#define fgt_LL_DEBUG (1)
#define fgt_LL_TRACE (0)

#ifndef fgt_LOG_LEVEL
#define fgt_LOG_LEVEL fgt_DEBUG_LEVEL
#endif

#if fgt_LOG_LEVEL <= fgt_LL_ERROR
#define fgt_LOG_ERROR_ENABLED (2)
#else
#define fgt_LOG_ERROR_ENABLED (0)
#endif

#if fgt_LOG_LEVEL <= fgt_LL_WARN
#define fgt_LOG_WARN_ENABLED (1)
#else
#define fgt_LOG_WARN_ENABLED (0)
#endif

#if fgt_LOG_LEVEL <= fgt_LL_INFO
#define fgt_LOG_INFO_ENABLED (1)
#else
#define fgt_LOG_INFO_ENABLED (0)
#endif

#if fgt_LOG_LEVEL <= fgt_LL_DEBUG
#define fgt_LOG_DEBUG_ENABLED (1)
#else
#define fgt_LOG_DEBUG_ENABLED (0)
#endif

#if fgt_LOG_LEVEL <= fgt_LL_TRACE
#define fgt_LOG_TRACE_ENABLED (1)
#else
#define fgt_LOG_TRACE_ENABLED (0)
#endif

#ifndef fgt_DEBUG_LEVEL
#define fgt_DEBUG_LEVEL (3)
#endif

#if fgt_LOG_ERROR_ENABLED
#define fgt_LOG_ERROR(logger, expr) \
    {                              \
        logger->error(expr);       \
    }
#else
#define fgt_LOG_ERROR (logger, expr) // do nothing
#endif

#if fgt_LOG_WARN_ENABLED
#define fgt_LOG_WARN(logger, expr) \
    {                             \
        logger->warn(expr);       \
    }
#else
#define fgt_LOG_INFO(logger, expr)
#endif

#if fgt_LOG_INFO_ENABLED
#define fgt_LOG_INFO(logger, expr) \
    {                             \
        logger->info(expr);       \
    }
#else
#define fgt_LOG_INFO(logger, expr)
#endif

#if fgt_LOG_DEBUG_ENABLED
#define fgt_LOG_DEBUG(logger, expr) \
    {                              \
        logger->debug(expr);       \
    }
#define fgt_OUT_DEBUG(out, expr) \
    {                           \
        out->println(expr);     \
    }

#else

#define fgt_LOG_DEBUG(logger, expr)
#define fgt_OUT_DEBUG(out, expr)

#endif

#if fgt_LOG_TRACE_ENABLED
#define fgt_LOG_TRACE(logger, expr) \
    {                              \
        logger->trace(expr);       \
    }
#else
#define fgt_LOG_TRACE(logger, expr)
#endif

namespace fgt::util {
class Debug {
public:
    static void print(const char *str);

    static void println();

    static void print(float f);

    static void print(int i);

    static void print(long l);

    static void print(bool b);

    static void print(double d);

    static void print(unsigned i);

    static void print(unsigned long i);

    static void debug(const char *str);

    static void debug(const char *str, float fValue);

    static void debug(const char *str, float fValue, const char *str2);

    static void debug(const char *str, float exp1, float exp2, float exp3);

    static void debug(const char *str, float fValue1, float fValue2, float fValue3, float fValue4, float fValue5);
};
} // namespace fgt::util

#ifndef fgt_DEBUG_PRINT
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG_PRINT(exp) \
    fgt::util::Debug::print(exp);
#else
#define fgt_DEBUG_PRINT(exp)
#endif
#endif

#ifndef fgt_DEBUG_PRINTLN
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG_PRINTLN() \
    fgt::util::Debug::println();
#else
#define fgt_DEBUG_PRINTLN()
#endif
#endif

#ifndef fgt_DEBUG
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG(exp) \
    fgt::util::Debug::debug(exp);
#else
#define fgt_DEBUG(exp)
#endif
#endif

#ifndef fgt_DEBUG2
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG2(exp1, exp2)         \
    {                                 \
        fgt::util::Debug::print(exp1); \
        fgt::util::Debug::print(exp2); \
        fgt::util::Debug::println();   \
    }
#else
#define fgt_DEBUG2(exp1, exp2)
#endif
#endif

#ifndef fgt_DEBUG3
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG3(exp1, exp2, exp3)   \
    {                                 \
        fgt::util::Debug::print(exp1); \
        fgt::util::Debug::print(exp2); \
        fgt::util::Debug::print(exp3); \
        fgt::util::Debug::println();   \
    }
#else
#define fgt_DEBUG3(exp1, exp2, exp3)
#endif
#endif

#ifndef fgt_DEBUG4
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG4(exp1, exp2, exp3, exp4) \
    {                                     \
        fgt::util::Debug::print(exp1);     \
        fgt::util::Debug::print(exp2);     \
        fgt::util::Debug::print(exp3);     \
        fgt::util::Debug::print(exp4);     \
        fgt::util::Debug::println();       \
    }

#else
#define fgt_DEBUG4(exp1, exp2, exp3, exp4)
#endif
#endif

#ifndef fgt_DEBUG5
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG5(exp1, exp2, exp3, exp4, exp5) \
    {                                           \
        fgt::util::Debug::print(exp1);           \
        fgt::util::Debug::print(exp2);           \
        fgt::util::Debug::print(exp3);           \
        fgt::util::Debug::print(exp4);           \
        fgt::util::Debug::print(exp5);           \
        fgt::util::Debug::println();             \
    }

#else
#define fgt_DEBUG5(exp1, exp2, exp3, exp4, exp5)
#endif
#endif

#ifndef fgt_DEBUG6
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG6(exp1, exp2, exp3, exp4, exp5, exp6) \
    {                                                 \
        fgt::util::Debug::print(exp1);                 \
        fgt::util::Debug::print(exp2);                 \
        fgt::util::Debug::print(exp3);                 \
        fgt::util::Debug::print(exp4);                 \
        fgt::util::Debug::print(exp5);                 \
        fgt::util::Debug::print(exp6);                 \
        fgt::util::Debug::println();                   \
    }
#else
#define fgt_DEBUG6(exp1, exp2, exp3, exp4, exp5, exp6)
#endif
#endif

#ifndef fgt_DEBUG7
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG7(exp1, exp2, exp3, exp4, exp5, exp6, exp7) \
    {                                                       \
        fgt::util::Debug::print(exp1);                       \
        fgt::util::Debug::print(exp2);                       \
        fgt::util::Debug::print(exp3);                       \
        fgt::util::Debug::print(exp4);                       \
        fgt::util::Debug::print(exp5);                       \
        fgt::util::Debug::print(exp6);                       \
        fgt::util::Debug::print(exp7);                       \
        fgt::util::Debug::println();                         \
    }
#else
#define fgt_DEBUG7(exp1, exp2, exp3, exp4, exp5, exp6, exp7)
#endif
#endif

#ifndef fgt_DEBUG8
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG8(exp1, exp2, exp3, exp4, exp5, exp6, exp7, exp8) \
    {                                                             \
        fgt::util::Debug::print(exp1);                             \
        fgt::util::Debug::print(exp2);                             \
        fgt::util::Debug::print(exp3);                             \
        fgt::util::Debug::print(exp4);                             \
        fgt::util::Debug::print(exp5);                             \
        fgt::util::Debug::print(exp6);                             \
        fgt::util::Debug::print(exp7);                             \
        fgt::util::Debug::print(exp8);                             \
        fgt::util::Debug::println();                               \
    }
#else
#define fgt_DEBUG8(exp1, exp2, exp3, exp4, exp5, exp6, exp7, exp8)
#endif
#endif

#ifndef fgt_DEBUG9
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG9(exp1, exp2, exp3, exp4, exp5, exp6, exp7, exp8, exp9) \
    {                                                                   \
        fgt::util::Debug::print(exp1);                                   \
        fgt::util::Debug::print(exp2);                                   \
        fgt::util::Debug::print(exp3);                                   \
        fgt::util::Debug::print(exp4);                                   \
        fgt::util::Debug::print(exp5);                                   \
        fgt::util::Debug::print(exp6);                                   \
        fgt::util::Debug::print(exp7);                                   \
        fgt::util::Debug::print(exp8);                                   \
        fgt::util::Debug::print(exp9);                                   \
        fgt::util::Debug::println();                                     \
    }
#else
#define fgt_DEBUG9(exp1, exp2, exp3, exp4, exp5, exp6, exp7, exp8, exp9)
#endif
#endif

#ifndef fgt_DEBUG10
#if fgt_LOG_DEBUG_ENABLED
#define fgt_DEBUG10(exp1, exp2, exp3, exp4, exp5, exp6, exp7, exp8, exp9, exp10) \
    {                                                                           \
        fgt::util::Debug::print(exp1);                                           \
        fgt::util::Debug::print(exp2);                                           \
        fgt::util::Debug::print(exp3);                                           \
        fgt::util::Debug::print(exp4);                                           \
        fgt::util::Debug::print(exp5);                                           \
        fgt::util::Debug::print(exp6);                                           \
        fgt::util::Debug::print(exp7);                                           \
        fgt::util::Debug::print(exp8);                                           \
        fgt::util::Debug::print(exp9);                                           \
        fgt::util::Debug::println();                                             \
    }
#else
#define fgt_DEBUG10(exp1, exp2, exp3, exp4, exp5, exp6, exp7, exp8, exp9, exp10)
#endif
#endif


#ifndef fgt_TRACE
#if fgt_LOG_TRACE_ENABLED
#define fgt_TRACE(exp) \
    fgt::util::Debug::debug(exp);
#else
#define fgt_TRACE(exp)
#endif
#endif

#ifndef fgt_TRACE2
#if fgt_LOG_TRACE_ENABLED
#define fgt_TRACE2(exp1, exp2)         \
    {                                 \
        fgt::util::Debug::print(exp1); \
        fgt::util::Debug::print(exp2); \
        fgt::util::Debug::println();   \
    }
#else
#define fgt_TRACE2(exp1, exp2)
#endif
#endif