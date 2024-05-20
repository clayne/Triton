//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the Apache License 2.0.
*/


#include <triton/pythonBindings.hpp>
#include <triton/pythonUtils.hpp>
#include <triton/exceptions.hpp>
#include <triton/tritonTypes.hpp>

#include <limits>


#if PY_VERSION_HEX >= 0x030C0000

  #define tt_GET_OB_DIGIT(obj) obj->long_value.ob_digit
  #define tt_SET_OB_DIGIT(obj, n) obj->long_value.lv_tag = (n << 3) | (obj->long_value.lv_tag & 3)
  #define tt_PyLong_IsNegative(obj) ((obj->long_value.lv_tag & 3) == 2)
  #define tt_PyLong_DigitCount(obj) (obj->long_value.lv_tag >> 3)

#elif PY_VERSION_HEX >= 0X030A00F0

  #define tt_GET_OB_DIGIT(obj) obj->ob_digit
  #define tt_SET_OB_DIGIT(obj, n) Py_SET_SIZE(obj, n)
  #define tt_PyLong_IsNegative(obj) (Py_SIZE(obj) < 0)
  #define tt_PyLong_DigitCount(obj) (_PyLong_IsNegative(obj) ? -Py_SIZE(obj) : Py_SIZE(obj))

#else

  #define tt_GET_OB_DIGIT(obj) obj->ob_digit
  #define tt_SET_OB_DIGIT(obj, n) Py_SIZE(obj) = n
  #define tt_PyLong_IsNegative(obj) (Py_SIZE(obj) < 0)
  #define tt_PyLong_DigitCount(obj) (_PyLong_IsNegative(obj) ? -Py_SIZE(obj) : Py_SIZE(obj))

#endif


namespace triton {
  namespace bindings {
    namespace python {

      bool PyLong_AsBool(PyObject* obj) {
        return (PyObject_IsTrue(obj) != 0);
      }


      triton::__uint PyLong_AsUint(PyObject* vv) {
        triton::__uint x = 0, prev = 0;
        PyLongObject* v = nullptr;
        Py_ssize_t i = 0;
        bool n = false;

        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint(): Bad internal call.");
        }

        v = reinterpret_cast<PyLongObject*>(vv);
        n = tt_PyLong_IsNegative(v);
        i = tt_PyLong_DigitCount(v);
        x = 0;

        while (--i >= 0) {
          prev = x;
          x = (x << PyLong_SHIFT) | tt_GET_OB_DIGIT(v)[i];
          if ((x >> PyLong_SHIFT) != prev)
            throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint(): long int too large to convert.");
        }

        return (n ? ((~x)+1) : x);
      }


      triton::usize PyLong_AsUsize(PyObject* vv) {
        triton::usize x = 0, prev = 0;
        PyLongObject* v = nullptr;
        Py_ssize_t i = 0;
        bool n = false;

        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUsize(): Bad internal call.");
        }

        v = reinterpret_cast<PyLongObject*>(vv);
        n = tt_PyLong_IsNegative(v);
        i = tt_PyLong_DigitCount(v);
        x = 0;

        while (--i >= 0) {
          prev = x;
          x = (x << PyLong_SHIFT) | tt_GET_OB_DIGIT(v)[i];
          if ((x >> PyLong_SHIFT) != prev)
            throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUsize(): long int too large to convert.");
        }

        return (n ? ((~x)+1) : x);
      }


      triton::uint32 PyLong_AsUint32(PyObject* vv) {
        triton::uint32 x = 0, prev = 0;
        PyLongObject* v = nullptr;
        Py_ssize_t i = 0;
        bool n = false;

        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint32(): Bad internal call.");
        }

        v = reinterpret_cast<PyLongObject*>(vv);
        n = tt_PyLong_IsNegative(v);
        i = tt_PyLong_DigitCount(v);
        x = 0;

        while (--i >= 0) {
          prev = x;
          x = (x << PyLong_SHIFT) | tt_GET_OB_DIGIT(v)[i];
          if ((x >> PyLong_SHIFT) != prev)
            throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint32(): long int too large to convert.");
        }

        return (n ? ((~x)+1) : x);
      }


      triton::uint64 PyLong_AsUint64(PyObject* vv) {
        triton::uint64 x = 0, prev = 0;
        PyLongObject* v = nullptr;
        Py_ssize_t i = 0;
        bool n = false;

        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint64(): Bad internal call.");
        }

        v = reinterpret_cast<PyLongObject*>(vv);
        n = tt_PyLong_IsNegative(v);
        i = tt_PyLong_DigitCount(v);
        x = 0;

        while (--i >= 0) {
          prev = x;
          x = (x << PyLong_SHIFT) | tt_GET_OB_DIGIT(v)[i];
          if ((x >> PyLong_SHIFT) != prev)
            throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint64(): long int too large to convert.");
        }

        return (n ? ((~x)+1) : x);
      }


      triton::uint128 PyLong_AsUint128(PyObject* vv) {
        triton::uint128 x = 0, prev = 0;
        PyLongObject* v = nullptr;
        Py_ssize_t i = 0;
        bool n = false;

        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint128(): Bad internal call.");
        }

        v = reinterpret_cast<PyLongObject*>(vv);
        n = tt_PyLong_IsNegative(v);
        i = tt_PyLong_DigitCount(v);
        x = 0;

        while (--i >= 0) {
          prev = x;
          x = (x << PyLong_SHIFT) | tt_GET_OB_DIGIT(v)[i];
          if ((x >> PyLong_SHIFT) != prev)
            throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint128(): long int too large to convert.");
        }

        return (n ? ((~x)+1) : x);
      }


      triton::uint256 PyLong_AsUint256(PyObject* vv) {
        triton::uint256 x = 0, prev = 0;
        PyLongObject* v = nullptr;
        Py_ssize_t i = 0;
        bool n = false;

        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint256(): Bad internal call.");
        }

        v = reinterpret_cast<PyLongObject*>(vv);
        n = tt_PyLong_IsNegative(v);
        i = tt_PyLong_DigitCount(v);
        x = 0;

        while (--i >= 0) {
          prev = x;
          x = (x << PyLong_SHIFT) | tt_GET_OB_DIGIT(v)[i];
          if ((x >> PyLong_SHIFT) != prev)
            throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint256(): long int too large to convert.");
        }

        return (n ? ((~x)+1) : x);
      }


      triton::uint512 PyLong_AsUint512(PyObject* vv) {
        triton::uint512 x = 0, prev = 0;
        PyLongObject* v = nullptr;
        Py_ssize_t i = 0;
        bool n = false;

        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint512(): Bad internal call.");
        }

        v = reinterpret_cast<PyLongObject*>(vv);
        n = tt_PyLong_IsNegative(v);
        i = tt_PyLong_DigitCount(v);
        x = 0;

        while (--i >= 0) {
          prev = x;
          x = (x << PyLong_SHIFT) | tt_GET_OB_DIGIT(v)[i];
          if ((x >> PyLong_SHIFT) != prev)
            throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint512(): long int too large to convert.");
        }

        return (n ? ((~x)+1) : x);
      }


      /* Returns a PyObject from a {32,64}-bits integer */
      PyObject* PyLong_FromUint(triton::__uint value) {
        #if defined(__i386) || defined(_M_IX86)
        return PyInt_FromLong(static_cast<long>(value));
        #else
        PyLongObject* v;
        triton::__uint t;
        int ndigits = 0;

        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        /* Count the number of Python digits. */
        t = value;
        while (t) {
          ++ndigits;
          t >>= PyLong_SHIFT;
        }

        v = _PyLong_New(ndigits);
        digit* p = tt_GET_OB_DIGIT(v);
        tt_SET_OB_DIGIT(v, ndigits);

        while (value) {
          *p++ = static_cast<digit>(value & PyLong_MASK);
          value >>= PyLong_SHIFT;
        }

        return (PyObject*)v;
        #endif
      }


      /* Returns a PyObject from a {32,64}-bits integer */
      PyObject* PyLong_FromUsize(triton::usize value) {
        #if defined(__i386) || defined(_M_IX86)
        return PyInt_FromLong(static_cast<long>(value));
        #else
        PyLongObject* v;
        triton::usize t;
        int ndigits = 0;

        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        /* Count the number of Python digits. */
        t = value;
        while (t) {
          ++ndigits;
          t >>= PyLong_SHIFT;
        }

        v = _PyLong_New(ndigits);
        digit* p = tt_GET_OB_DIGIT(v);
        tt_SET_OB_DIGIT(v, ndigits);

        while (value) {
          *p++ = static_cast<digit>(value & PyLong_MASK);
          value >>= PyLong_SHIFT;
        }

        return (PyObject*)v;
        #endif
      }


      /* Returns a PyObject from a 32-bits integer */
      PyObject* PyLong_FromUint32(triton::uint32 value) {
        return PyInt_FromLong(static_cast<long>(value));
      }


      /* Returns a PyObject from a 64-bits integer */
      PyObject* PyLong_FromUint64(triton::uint64 value) {
        PyLongObject* v;
        triton::uint64 t;
        int ndigits = 0;

        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        /* Count the number of Python digits. */
        t = value;
        while (t) {
          ++ndigits;
          t >>= PyLong_SHIFT;
        }

        v = _PyLong_New(ndigits);
        digit* p = tt_GET_OB_DIGIT(v);
        tt_SET_OB_DIGIT(v, ndigits);

        while (value) {
          *p++ = static_cast<digit>(value & PyLong_MASK);
          value >>= PyLong_SHIFT;
        }

        return (PyObject*)v;
      }


      /* Returns a PyObject from a 128-bits integer */
      PyObject* PyLong_FromUint128(triton::uint128 value) {
        PyLongObject* v;
        triton::uint128 t;
        int ndigits = 0;

        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        /* Count the number of Python digits. */
        t = value;
        while (t) {
          ++ndigits;
          t >>= PyLong_SHIFT;
        }

        v = _PyLong_New(ndigits);
        digit* p = tt_GET_OB_DIGIT(v);
        tt_SET_OB_DIGIT(v, ndigits);

        while (value) {
          *p++ = static_cast<digit>(value & PyLong_MASK);
          value >>= PyLong_SHIFT;
        }

        return (PyObject*)v;
      }


      /* Returns a PyObject from a 256-bits integer */
      PyObject* PyLong_FromUint256(triton::uint256 value) {
        PyLongObject* v;
        triton::uint256 t;
        int ndigits = 0;

        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        /* Count the number of Python digits. */
        t = value;
        while (t) {
          ++ndigits;
          t >>= PyLong_SHIFT;
        }

        v = _PyLong_New(ndigits);
        digit* p = tt_GET_OB_DIGIT(v);
        tt_SET_OB_DIGIT(v, ndigits);

        while (value) {
          *p++ = static_cast<digit>(value & PyLong_MASK);
          value >>= PyLong_SHIFT;
        }

        return (PyObject*)v;
      }


      /* Returns a PyObject from a 512-bits integer */
      PyObject* PyLong_FromUint512(triton::uint512 value) {
        PyLongObject* v;
        triton::uint512 t = 0;
        int ndigits = 0;

        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        /* Count the number of Python digits. */
        t = value;
        while (t) {
          ++ndigits;
          t >>= PyLong_SHIFT;
        }

        v = _PyLong_New(ndigits);
        digit* p = tt_GET_OB_DIGIT(v);
        tt_SET_OB_DIGIT(v, ndigits);

        while (value) {
          *p++ = static_cast<digit>(value & PyLong_MASK);
          value >>= PyLong_SHIFT;
        }

        return (PyObject*)v;
      }

    }; /* python namespace */
  }; /* bindings namespace */
}; /* triton namespace */

#undef tt_GET_OB_DIGIT
#undef tt_SET_OB_DIGIT
#undef tt_PyLong_IsNegative
#undef tt_PyLong_DigitCount
