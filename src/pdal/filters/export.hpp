#pragma once


#ifdef _WIN32
#   define PDAL_EXPORT   __declspec(dllexport)
#   define PDAL_LOCAL
#   define PDAL_EXPORT_UNIX
#ifdef __GNUC__
#   define PDAL_EXPORT_DEPRECATED __attribute__((deprecated)) PDAL_EXPORT
#else
#   define PDAL_EXPORT_DEPRECATED   __declspec(deprecated, dllexport)
#endif
#else
#   define PDAL_EXPORT     __attribute__ ((visibility("default")))
// Keep the PDAL_DLL name around so any external plugins that still might have that defined
// can still compile and be used
#   define PDAL_DLL     PDAL_EXPORT
#   define PDAL_LOCAL   __attribute__((visibility("hidden")))
#   define PDAL_EXPORT_UNIX   __attribute__ ((visibility("default")))
#   define PDAL_EXPORT_DEPRECATED   __attribute__((deprecated))
#endif // _WIN32
