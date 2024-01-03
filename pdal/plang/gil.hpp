/*
    pybind11/gil.h: RAII helpers for managing the GIL

    Copyright (c) 2016 Wenzel Jakob <wenzel.jakob@epfl.ch>

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE file.
*/

#pragma once

#include <Python.h>


namespace pdal
{
namespace plang
{


class gil_scoped_acquire {
    PyGILState_STATE state;

public:
    gil_scoped_acquire() : state{PyGILState_Ensure()} {}
    gil_scoped_acquire(const gil_scoped_acquire &) = delete;
    gil_scoped_acquire &operator=(const gil_scoped_acquire &) = delete;
    ~gil_scoped_acquire() { PyGILState_Release(state); }
    void disarm() {}
};

class gil_scoped_release {
    PyThreadState *state;

public:
    // PRECONDITION: The GIL must be held when this constructor is called.
    gil_scoped_release() {
        assert(PyGILState_Check());
        state = PyEval_SaveThread();
    }
    gil_scoped_release(const gil_scoped_release &) = delete;
    gil_scoped_release &operator=(const gil_scoped_release &) = delete;
    ~gil_scoped_release() { PyEval_RestoreThread(state); }
    void disarm() {}
};




} // plang

}  // pdal
