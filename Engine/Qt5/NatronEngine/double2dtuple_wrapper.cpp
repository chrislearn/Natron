
// default includes
#include "Global/Macros.h"
CLANG_DIAG_OFF(mismatched-tags)
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
GCC_DIAG_OFF(missing-declarations)
GCC_DIAG_OFF(uninitialized)
GCC_DIAG_UNUSED_LOCAL_TYPEDEFS_OFF
#include <pysidesignal.h>
#include <shiboken.h> // produces many warnings
#ifndef QT_NO_VERSION_TAGGING
#  define QT_NO_VERSION_TAGGING
#endif
#include <QDebug>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <pysideqenum.h>
#include <feature_select.h>
#include <qapp_macro.h>

QT_WARNING_DISABLE_DEPRECATED

#include <typeinfo>
#include <iterator>

// module include
#include "natronengine_python.h"

// main header
#include "double2dtuple_wrapper.h"

// inner classes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING

#include <cctype>
#include <cstring>



template <class T>
static const char *typeNameOf(const T &t)
{
    const char *typeName =  typeid(t).name();
    auto size = std::strlen(typeName);
#if defined(Q_CC_MSVC) // MSVC: "class QPaintDevice * __ptr64"
    if (auto lastStar = strchr(typeName, '*')) {
        // MSVC: "class QPaintDevice * __ptr64"
        while (*--lastStar == ' ') {
        }
        size = lastStar - typeName + 1;
    }
#else // g++, Clang: "QPaintDevice *" -> "P12QPaintDevice"
    if (size > 2 && typeName[0] == 'P' && std::isdigit(typeName[1])) {
        ++typeName;
        --size;
    }
#endif
    char *result = new char[size + 1];
    result[size] = '\0';
    memcpy(result, typeName, size);
    return result;
}


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Double2DTuple_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Double2DTuple >()))
        return -1;

    ::Double2DTuple *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // Double2DTuple()
            cptr = new ::Double2DTuple();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Double2DTuple >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}


static const char *Sbk_Double2DTuple_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_Double2DTuple_methods[] = {

    {nullptr, nullptr} // Sentinel
};

PyObject* Sbk_Double2DTupleFunc___getitem__(PyObject *self, Py_ssize_t _i)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Double2DTuple *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE2DTUPLE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    // Begin code injection
    if (_i < 0 || _i >= 2) {
    PyErr_BadArgument();
    return 0;
    } else {
    double ret;
    switch (_i) {
    case 0:
    ret = cppSelf->x;
    break;
    case 1:
    ret = cppSelf->y;
    break;
    }
    return  Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret);
    }

    // End of code injection

}

static PyObject *Sbk_Double2DTuple_get_x(PyObject *self, void *)
{
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    auto cppSelf = reinterpret_cast< ::Double2DTuple *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE2DTUPLE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->x);
    return pyOut;
}
static int Sbk_Double2DTuple_set_x(PyObject *self, PyObject *pyIn, void *)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    auto cppSelf = reinterpret_cast< ::Double2DTuple *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE2DTUPLE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'x' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'x', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->x;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject *Sbk_Double2DTuple_get_y(PyObject *self, void *)
{
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    auto cppSelf = reinterpret_cast< ::Double2DTuple *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE2DTUPLE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->y);
    return pyOut;
}
static int Sbk_Double2DTuple_set_y(PyObject *self, PyObject *pyIn, void *)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    auto cppSelf = reinterpret_cast< ::Double2DTuple *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE2DTUPLE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'y' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'y', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->y;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for Double2DTuple
static PyGetSetDef Sbk_Double2DTuple_getsetlist[] = {
    {const_cast<char *>("x"), Sbk_Double2DTuple_get_x, Sbk_Double2DTuple_set_x},
    {const_cast<char *>("y"), Sbk_Double2DTuple_get_y, Sbk_Double2DTuple_set_y},
    {nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Double2DTuple_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Double2DTuple_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Double2DTuple_Type = nullptr;
static SbkObjectType *Sbk_Double2DTuple_TypeF(void)
{
    return _Sbk_Double2DTuple_Type;
}

static PyType_Slot Sbk_Double2DTuple_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Double2DTuple_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Double2DTuple_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Double2DTuple_methods)},
    {Py_tp_getset,      reinterpret_cast<void *>(Sbk_Double2DTuple_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_Double2DTuple_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    // type supports sequence protocol
    {Py_sq_item, (void *)&Sbk_Double2DTupleFunc___getitem__},
    {0, nullptr}
};
static PyType_Spec Sbk_Double2DTuple_spec = {
    "1:NatronEngine.Double2DTuple",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Double2DTuple_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Double2DTuple_PythonToCpp_Double2DTuple_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Double2DTuple_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_Double2DTuple_PythonToCpp_Double2DTuple_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_Double2DTuple_TypeF())))
        return Double2DTuple_PythonToCpp_Double2DTuple_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *Double2DTuple_PTR_CppToPython_Double2DTuple(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Double2DTuple *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
    }
    PyObject *result = Shiboken::Object::newObject(Sbk_Double2DTuple_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Double2DTuple_SignatureStrings[] = {
    "NatronEngine.Double2DTuple(self)",
    nullptr}; // Sentinel

void init_Double2DTuple(PyObject *module)
{
    _Sbk_Double2DTuple_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Double2DTuple",
        "Double2DTuple*",
        &Sbk_Double2DTuple_spec,
        &Shiboken::callCppDestructor< ::Double2DTuple >,
        0,
        0,
        0    );
    
    auto pyType = reinterpret_cast<PyTypeObject *>(_Sbk_Double2DTuple_Type);
    InitSignatureStrings(pyType, Double2DTuple_SignatureStrings);
    SbkObjectType_SetPropertyStrings(reinterpret_cast<PyTypeObject *>(_Sbk_Double2DTuple_Type), Sbk_Double2DTuple_PropertyStrings);
    SbkNatronEngineTypes[SBK_DOUBLE2DTUPLE_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Double2DTuple_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_Double2DTuple_TypeF(),
        Double2DTuple_PythonToCpp_Double2DTuple_PTR,
        is_Double2DTuple_PythonToCpp_Double2DTuple_PTR_Convertible,
        Double2DTuple_PTR_CppToPython_Double2DTuple);

    Shiboken::Conversions::registerConverterName(converter, "Double2DTuple");
    Shiboken::Conversions::registerConverterName(converter, "Double2DTuple*");
    Shiboken::Conversions::registerConverterName(converter, "Double2DTuple&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Double2DTuple).name());



}
