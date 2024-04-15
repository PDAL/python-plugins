================================================================================
PDAL Python Plugins
================================================================================

PDAL Python plugins allow you to process data with PDAL into
`Numpy <http://www.numpy.org/>`__ arrays.
They support embedding Python in PDAL pipelines with the
`readers.numpy <https://pdal.io/stages/readers.numpy.html>`__ and
`filters.python <https://pdal.io/stages/filters.python.html>`__ stages.

Installation
--------------------------------------------------------------------------------

PyPI
................................................................................

PDAL Python plugins are installable via PyPI:

.. code-block::

    pip install pdal-plugins

GitHub
................................................................................

The repository for PDAL's Python plugins is available at https://github.com/PDAL/python-plugins

.. image:: https://github.com/PDAL/python-plugins/workflows/Build/badge.svg
   :target: https://github.com/PDAL/python-plugins/actions?query=workflow%3ABuild

Requirements
================================================================================

* PDAL 2.6+
* Python >=3.9
* Numpy (eg :code:`pip install numpy`)
* scikit-build-core (eg :code:`pip install scikit-build-core`)
