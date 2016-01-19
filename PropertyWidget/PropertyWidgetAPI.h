#ifndef QTN_PROPERTYWIDGETAPI_H
#define QTN_PROPERTYWIDGETAPI_H

#include <functional>

#define QTN_PW_EXPORT

QTN_PW_EXPORT bool initQtnPropertyWidgetLibrary();

template<typename T, typename R, class... Types>
std::function<R(Types...)> qtnMemFn(T* t, R(T::*memFn)(Types...) const)
{
    return [t, memFn](Types... args) { return std::invoke(memFn, t, std::forward<Types>(args)...); };
}

template<typename T, typename R, class... Types>
std::function<R(Types...)> qtnMemFn(T* t, R(T::*memFn)(Types...))
{
    return [t, memFn](Types... args) { return std::invoke(memFn, t, std::forward<Types>(args)...); };
}


#endif // QTN_PROPERTYWIDGETAPI_H
