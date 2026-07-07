================================================================================
PDAL Python Plugins
================================================================================

PDAL Python plugins allow you to process data with PDAL into
`Numpy <http://www.numpy.org/>`__ arrays.
They support embedding Python in PDAL pipelines with the
`readers.numpy <https://pdal.org/stages/readers.numpy.html>`__ and
`filters.python <https://pdal.org/stages/filters.python.html>`__ stages.

Installation
--------------------------------------------------------------------------------

PyPI
................................................................................

PDAL Python plugins are installable via PyPI:

.. code-block::

    uv pip install pdal-plugins

If you are not using uv, :code:`pip install pdal-plugins` works too.

GitHub
................................................................................

The repository for PDAL's Python plugins is available at https://github.com/PDAL/python-plugins

.. image:: https://github.com/PDAL/python-plugins/workflows/Build/badge.svg
   :target: https://github.com/PDAL/python-plugins/actions?query=workflow%3ABuild

Requirements
================================================================================

* PDAL 2.6+
* Python >=3.9
* uv
* Numpy
* scikit-build-core
* pybind11
* CMake and Ninja

Development
================================================================================

The project uses uv for Python package installation and builds, with
scikit-build-core driving the CMake build.

Create a development environment with the same dependencies used by CI:

.. code-block:: bash

    mamba env create -f .github/environment.yml
    mamba activate test

Install the plugins into that environment and build the C++ tests:

.. code-block:: bash

    PYTHON=$(python -c 'import sys; print(sys.executable)')
    uv pip install --python "$PYTHON" --no-build-isolation -Ccmake.define.WITH_TESTS=ON .

Run the tests from the scikit-build output directory:

.. code-block:: bash

    export PYTHONHOME=$CONDA_PREFIX
    export PATH=$CONDA_PREFIX/bin:$PATH
    export WHEEL_DIR=$(python -m scikit_build_core.builder.wheel_tag)
    export PDAL_DRIVER_PATH=$(pwd)/build/$WHEEL_DIR/Release
    pdal --drivers
    $PDAL_DRIVER_PATH/pdal_filters_python_test
    $PDAL_DRIVER_PATH/pdal_io_numpy_test

Build source and wheel distributions with uv:

.. code-block:: bash

    PYTHON=$(python -c 'import sys; print(sys.executable)')
    uv build --python "$PYTHON"
