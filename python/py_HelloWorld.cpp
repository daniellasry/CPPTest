#include <pybind11/pybind11.h>
#include "src/HelloWorld.hpp"

namespace py = pybind11; // for less noise

PYBIND11_MODULE(cpptest, m)
{
    py::class_<HelloWorld>(m, "HelloWorld")
        .def(py::init<const std::string &>())
        .def("Print", &HelloWorld::Print)
        .def("GetMessage", &HelloWorld::GetMessage)
        .def("Append", &HelloWorld::Append)
        .def("Reverse", &HelloWorld::Reverse);
}