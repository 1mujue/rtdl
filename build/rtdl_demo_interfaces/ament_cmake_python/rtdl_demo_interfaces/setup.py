from setuptools import find_packages
from setuptools import setup

setup(
    name='rtdl_demo_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('rtdl_demo_interfaces', 'rtdl_demo_interfaces.*')),
)
