#ifndef SBK_PARAMETRICPARAMWRAPPER_H
#define SBK_PARAMETRICPARAMWRAPPER_H

#include <PyParameter.h>


// Extra includes
#include <PyParameter.h>
NATRON_NAMESPACE_ENTER NATRON_PYTHON_NAMESPACE_ENTER
class ParametricParamWrapper : public ParametricParam
{
public:
    inline void _addAsDependencyOf_protected(int fromExprDimension, Param * param, int thisDimension) { ParametricParam::_addAsDependencyOf(fromExprDimension, param, thisDimension); }
    ~ParametricParamWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};
NATRON_PYTHON_NAMESPACE_EXIT NATRON_NAMESPACE_EXIT

#  ifndef SBK_PARAMWRAPPER_H
#  define SBK_PARAMWRAPPER_H

// Inherited base class:
NATRON_NAMESPACE_ENTER NATRON_PYTHON_NAMESPACE_ENTER
class ParamWrapper : public Param
{
public:
    inline void _addAsDependencyOf_protected(int fromExprDimension, Param * param, int thisDimension) { Param::_addAsDependencyOf(fromExprDimension, param, thisDimension); }
    ~ParamWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};
NATRON_PYTHON_NAMESPACE_EXIT NATRON_NAMESPACE_EXIT

#  endif // SBK_PARAMWRAPPER_H

#endif // SBK_PARAMETRICPARAMWRAPPER_H

