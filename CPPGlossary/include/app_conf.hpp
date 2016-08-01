#ifndef _APP_CONF_HPP_
#define _APP_CONF_HPP_

#define APP_IDENTITY(x) x

#define APP_STRINGIFY_NX(x) #x
#define APP_STRINGIFY(x) APP_STRINGIFY_NX(x)

#define APP_PASTE_NX(x,y) x##y
#define APP_PASTE(x,y) APP_PASTE_NX(x,y)

#define APP_UNSED(x) (void)x

#define APP_NOOP() struct _APP_##__LINE__


// Disable warnings for Microsoft Compiler

#if defined(_MSC_VER)

// disabled warnings: 4514 4619 4710 4711 4820

#define MSW_STL 4574 4668 4986
#define MSW_QT 4127 4231 4244 4251 4275 4365 4512 4571 4574 4619 4625 4626 4628 4668 4800 4946 4986
#define MSW_WCCOA 4127 4100 4242 4244 4251 4263 4264 4266 4365 4512 4574 4619 4625 4626 4668 4800 4946 4986

#define WF_MSW_DISABLE(...) __pragma( warning(push) ) __pragma( warning(disable: __VA_ARGS__) )
#define WF_MSW_RESTORE() __pragma( warning(pop) )

#else // NOT _MSC_VER

#define MSW_STL
#define MSW_QT
#define MSW_WCCOA

#define WF_MSW_DISABLE(...)
#define WF_MSW_RESTORE()

#endif // _MSC_VER


// Disable warnings for GCC

/* http://dbp-consulting.com/tutorials/SuppressingGCCWarnings.html */

#if defined(__GNUC__) && defined(__GNUC_MINOR__)

#if ((__GNUC__ * 100) + __GNUC_MINOR__) >= 402
#define GCC_DIAG_STR(s) #s
#define GCC_DIAG_JOINSTR(x,y) GCC_DIAG_STR(x ## y)
#define GCC_DIAG_DO_PRAGMA(x) _Pragma (#x)
#define GCC_DIAG_PRAGMA(x) GCC_DIAG_DO_PRAGMA(GCC diagnostic x)

#if ((__GNUC__ * 100) + __GNUC_MINOR__) >= 406
#define WF_GCCW_DISABLE(x) GCC_DIAG_PRAGMA(push) \
	GCC_DIAG_PRAGMA(ignored GCC_DIAG_JOINSTR(-W,x))
#define WF_GCCW_RESTORE(x) GCC_DIAG_PRAGMA(pop)
#else // NOT >= 406
#define WF_GCCW_DISABLE(x) GCC_DIAG_PRAGMA(ignored GCC_DIAG_JOINSTR(-W,x))
#define WF_GCCW_RESTORE(x) GCC_DIAG_PRAGMA(warning GCC_DIAG_JOINSTR(-W,x))
#endif // >= 406

#else // NOT >= 402
#define WF_GCCW_DISABLE(x)
#define WF_GCCW_RESTORE(x)
#endif // >= 402

#else // NOT __GNUC__ && __GNUC_MINOR__
#define WF_GCCW_DISABLE(x)
#define WF_GCCW_RESTORE(x)
#endif // __GNUC__ && __GNUC_MINOR__

#endif // !_APP_COMMON_HPP_


#endif // !_APP_CONF_HPP_
