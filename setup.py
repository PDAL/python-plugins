from skbuild import setup

with open("README.rst", "r", encoding="utf-8") as fp:
    readme = fp.read()

setup(
    name="pdal-plugins",
    version="1.0.2",
    description="Point cloud data processing Python plugins",
    license="BSD",
    keywords="point cloud spatial",
    author="Howard Butler",
    author_email="howard@hobu.co",
    maintainer="Howard Butler",
    maintainer_email="howard@hobu.co",
    url="https://pdal.io",
    long_description=readme,
    long_description_content_type="text/x-rst",
    packages=["pdal"],
    classifiers=[
        "Development Status :: 5 - Production/Stable",
        "Intended Audience :: Developers",
        "Intended Audience :: Science/Research",
        "License :: OSI Approved :: BSD License",
        "Operating System :: OS Independent",
        "Programming Language :: Python :: 3.6",
        "Programming Language :: Python :: 3.7",
        "Programming Language :: Python :: 3.8",
        "Topic :: Scientific/Engineering :: GIS",
    ],
)
